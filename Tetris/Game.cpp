#pragma once
#include "Game.hpp"
#include <fstream>
#include <sstream>
#include <iostream>


// constructor

Game::Game(InputManager *inputManager, Playfield *playField) {

    m_inputManager = inputManager;
    m_playField = playField;
    
    startGame();

}

// destructor

Game::~Game() {}


// public method newGame()

void Game::newGame() {

    m_gameSpeed = global::gameSpeed;
    pressedKey = none;
    m_nextMove = { 0,0 };
    m_softDrop = 0;
    m_hardDrop = 0;

    m_score = 0;
    m_scoreLines = 0;
    m_level = 0;
    m_playTime = 0;

    m_timer1.restart();
    m_timer2.restart();

    m_playField->resetPlayField();
    m_playField->spawnMino();

    setState(Playing);

}

// public method startGame()

void Game::startGame() {

    setState(Start);
    m_playField->introPlayField();

}

// public method getState()

Gamestate Game::getState() {

    return m_gameState;

}

// public method setState()

void Game::setState(Gamestate state) {

    m_gameState = state;

}

// public method getStats()

std::vector<int> Game::getStats() {

    return { m_score, m_scoreLines, m_level, m_playTime };

}

// private method gameOver()

void Game::gameOver() {

    setState(Gameover);

    
    std::ifstream scoreFile;
    scoreFile.open("score.dat");
    if (!scoreFile.is_open()) return;
    
    std::string line;
    std::string word;
    std::vector<std::string> vLine;
    std::vector<std::vector<std::string>> vScores;

    while (getline(scoreFile, line)) {
        
        std::stringstream ss(line);
        
        while (getline(ss, word, ' '))
            vLine.push_back(word);

        vScores.push_back(vLine);
        vLine.clear();

    }

    scoreFile.close();

    bool change = false;
    
    if (vScores.size() < 10)
        change = true;

    int insertIndex = int(vScores.size());

    for (int i = 0; i < vScores.size(); i++) {
        
        if (m_score > stoi(vScores[i][0])) {

            insertIndex = i;
            change = true;
            break;

        }

    }


    if (change == true) {

        vLine.push_back(std::to_string(m_score));
        vLine.push_back(std::to_string(m_scoreLines));
        vLine.push_back(std::to_string(m_level));
        vLine.push_back(std::to_string(m_playTime));
        vScores.insert(vScores.begin() + insertIndex, vLine);

        while (vScores.size() > 10)
        vScores.pop_back();

        std::ofstream scoreFile;
        scoreFile.open("score.dat");
        if (!scoreFile.is_open()) return;

        for (int i = 0; i < vScores.size(); i++) {

            scoreFile << vScores[i][0] << " " << vScores[i][1] << " " << vScores[i][2] << " " << vScores[i][3];
            if (i + 1 < vScores.size()) scoreFile << std::endl;

        }

        scoreFile.close();

    }


}

// public method input()

void Game::input() {

    m_inputManager->updateEvents();
    pressedKey = m_inputManager->getLastPressedKey();

    switch (pressedKey) {

    case Escape:
        setState(Pause);
        break;

    case Up:
        m_nextMove.y = -1;
        break;

    case Down:
        if (!m_hardDrop)
            m_softDrop = 1;
        break;

    case Left:
        m_nextMove.x = -1;
        break;

    case Right:
        m_nextMove.x = 1;
        break;

    case Space:
        if (m_softDrop) {
            m_hardDrop = m_softDrop;
            m_softDrop = 0;
        }
        else
            m_hardDrop = 1;
        m_nextMove.y = 1;
        break;

    }


}

// private method activeMino()

Tetromino* Game::activeMino() {

    return m_playField->getActiveMino();

}

// private method scoreIncreaseLines()

void Game::scoreIncreaseLines(int lines) {

    int score = m_level + 1;

    switch (lines) {
    case 1:
        score *= 40;
        break;
    case 2:
        score *= 100;
        break;
    case 3:
        score *= 300;
        break;
    case 4:
        score *= 1200;
        break;
    }
    
    m_score += score;
    m_scoreLines += lines;
    m_level = int(m_scoreLines * 0.1f);

}

// private method scoreIncreaseDrops()

void Game::scoreIncreaseDrops(int drops, int multiplier) {

    m_score += (drops * multiplier) - 2;

}

// private method updatePlayTime()

void Game::updatePlayTime() {

    m_playTime = int(m_timer1.getElapsedTime().asSeconds());

}

// public method movement()

void Game::movement() {

    updatePlayTime();

    // horizontal and auto vertical movement
    if (m_nextMove.x != 0 || m_nextMove.y > 0) {

        // last and next position vectors
        sf::Vector2i lastPosition = activeMino()->getPosition();
        sf::Vector2i nextPosition = lastPosition + m_nextMove;
        std::vector<sf::Vector2i> lastPositions = activeMino()->getPositions();
        activeMino()->setPosition(nextPosition);
        std::vector<sf::Vector2i> nextPositions = activeMino()->getPositions();

        // collisions
        
        for (int i = 0; i < 4; i++) {
            
            // border collision
            if (m_nextMove.x != 0 && m_playField->getPositionType(nextPositions[i]) > 0) {
                activeMino()->setPosition(lastPosition);
                std::cout << "BORDER HIT" << std::endl;
                break;
            }
            
            // bottom collision
            if (m_nextMove.y == 1 && m_playField->getPositionType(nextPositions[i]) > 0) {
                activeMino()->setPosition(lastPosition);
                
                if (m_softDrop) {
                    scoreIncreaseDrops(m_softDrop, 1);
                    m_softDrop = 0;
                }
                else if (m_hardDrop) {
                    scoreIncreaseDrops(m_hardDrop, 2);
                    m_hardDrop = 0;
                }

                std::cout << "MINO LANDED" << std::endl;
                
                // save mino to the playfield grid
                for (int i = 0; i < 4; i++)
                    if (lastPositions[i].y >= 0) m_playField->setPositionType(lastPositions[i], activeMino()->getShapeType());

                // scan for and clear any full lines
                std::vector<int> vFullLines = m_playField->getFullLines();
                if (vFullLines.size() > 0) {
                    m_playField->deleteLines(vFullLines);
                    scoreIncreaseLines(int(vFullLines.size()));
                    m_gameSpeed = global::gameSpeed - (m_level * 0.025f);
                }

                // minos stacked to the top = game over
                if (nextPositions[i].y < 2) {
                    std::cout << "GAME OVER" << std::endl;
                    gameOver();
                    return;
                }

                // spawn new active mino
                m_playField->spawnMino();
                return;
            }

        }

    }

    // rotation
    else if (m_nextMove.y == -1) {


        activeMino()->rotate('+');
        std::vector<sf::Vector2i> nextPositions = activeMino()->getPositions();
        
        for (int i = 0; i < 4; i++) {
            if (m_playField->getPositionType(nextPositions[i]) > 0) {
                activeMino()->rotate('-');
                std::cout << "CANNOT ROTATE" << std::endl;
                break;
            }

        }

    }

    if (m_hardDrop == 0)
        m_nextMove = { 0,0 };
    else
        m_hardDrop++;

   
    
    // tick'ed section
    float gameSpeed = (m_softDrop) ? m_gameSpeed / 10 : m_gameSpeed;
    if (m_timer2.getElapsedTime().asSeconds() > gameSpeed) {

        std::cout << "tik-tak" << std::endl;
        
        m_nextMove.y = 1;
        m_timer2.restart();
        if (m_softDrop)
            m_softDrop++;

    }


    


}
