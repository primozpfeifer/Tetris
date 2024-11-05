#pragma once
#include "Renderer.hpp"


// construcor

Renderer::Renderer(WindowManager *windowManager, Playfield *playField, Game* game, MainMenu* mainMenu) {

    m_window = windowManager->getWindow();
    m_playField = playField;
    m_game = game;
    m_mainMenu = mainMenu;
    
    if (!m_font.loadFromFile("arial.ttf"))
        return; // error loading font

}

// destructor

Renderer::~Renderer() {}


// private method getColor()

sf::Color Renderer::getColor(int positionType) {

    sf::Color color;

    switch (positionType) {

    case 0: // empty block
        color = sf::Color(37, 36, 86); break;
    case 1: // I
        color = sf::Color(0, 255, 255); break;
    case 2: // J
        color = sf::Color(0, 0, 255); break;
    case 3: // L
        color = sf::Color(255, 127, 0); break;
    case 4: // O
        color = sf::Color(255, 255, 0); break;
    case 5: // S
        color = sf::Color(0, 255, 0); break;
    case 6: // T
        color = sf::Color(128, 0, 128); break;
    case 7: // Z
        color = sf::Color(255, 0, 0); break;
    case 8: // borders
        color = sf::Color(32, 32, 32); break;
    case 9: // spacing
        color = sf::Color(0, 0, 0);

    }

    return color;

}

// private method drawPlayField()

void Renderer::drawPlayField() {

    sf::RectangleShape cell(sf::Vector2f(global::cellSize * 1.f, global::cellSize * 1.f));
    cell.setOutlineThickness(-2);
    cell.setOutlineColor(getColor(9));
    sf::Vector2i gridPosition;

    for (int y = 0; y < global::rows; y++) {

        for (int x = 0; x < global::cols; x++) {

            cell.setPosition(global::cellSize * x * 1.f, global::scoreBarHeight + global::cellSize * y * 1.f);

            gridPosition.x = x;
            gridPosition.y = y;

            sf::Color color = getColor(m_playField->getPositionType(gridPosition));

            // if game paused draw only the playfield without minos
            if (m_game->getState() == Pause)
                if (m_playField->getPositionType(gridPosition) < 8)
                    color = getColor(0);

            // draw cells
            cell.setFillColor(color);
            m_window->draw(cell);

        }
        
    }

}

// private method drawActiveMino()

void Renderer::drawActiveMino() {

    sf::RectangleShape cell(sf::Vector2f(global::cellSize * 1.f, global::cellSize * 1.f));
    cell.setOutlineThickness(-2);
    cell.setOutlineColor(getColor(9));

    int shapeType = m_playField->getActiveMino()->getShapeType();
    sf::Color color = getColor(shapeType);

    cell.setFillColor(color);

    std::vector<sf::Vector2i> positions = m_playField->getActiveMino()->getPositions();

    for (int i = 0; i < 4; i++) {

        cell.setPosition(global::cellSize * positions[i].x * 1.f, global::scoreBarHeight + global::cellSize * positions[i].y * 1.f);
        m_window->draw(cell);

    }

}

// private method drawScoreBar()

void Renderer::drawScoreBar() {

    sf::RectangleShape cell(sf::Vector2f(global::cellSize * global::cols * 1.f, global::scoreBarHeight * 1.f));
    cell.setOutlineThickness(-2);
    cell.setOutlineColor(getColor(9));
    cell.setPosition(0 * 1.f, 0 * 1.f);
    cell.setFillColor(getColor(8));
    m_window->draw(cell);

    std::vector<int> stats = m_game->getStats();

    sf::Text text;
    text.setFont(m_font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);

    text.setString("SCORE : " + std::to_string(stats[0]));
    text.setPosition(20, 15);
    m_window->draw(text);

    text.setString("LINES : " + std::to_string(stats[1]));
    text.setPosition(36, 55);
    m_window->draw(text);

    text.setString("LEVEL : " + std::to_string(stats[2]));
    text.setPosition(261, 55);
    m_window->draw(text);


    std::string hours = std::to_string(stats[3] / 3600);
    std::string minutes = std::to_string((stats[3] - ((stats[3] / 3600) * 3600)) / 60);
    std::string seconds = std::to_string(stats[3] - ((stats[3] / 3600) * 3600) - (((stats[3] - ((stats[3] / 3600) * 3600)) / 60) * 60));

    if (hours.length() == 1) hours = "0" + hours;
    if (minutes.length() == 1) minutes = "0" + minutes;
    if (seconds.length() == 1) seconds = "0" + seconds;

    text.setString("TIME : " + hours + ":" + minutes + ":" + seconds);
    text.setPosition(276, 15);
    m_window->draw(text);

}

// private method drawMenu()

void Renderer::drawMenu() {

    // transparent whiteout for background
    sf::RectangleShape cell(sf::Vector2f(global::cellSize * global::cols * 1.f, global::cellSize * global::rows * 1.f));
    cell.setOutlineThickness(-2);
    cell.setOutlineColor(getColor(9));
    cell.setPosition(0.f, global::scoreBarHeight + 0.f);
    cell.setFillColor(sf::Color(255, 255, 255, 160));
    m_window->draw(cell);

    // menu bar
    sf::Vector2f mainMenuSize = sf::Vector2f(global::cellSize * global::cols * 1.f, global::cellSize * 8.f);
    sf::Vector2f mainMenuPosition = sf::Vector2f(global::cellSize * global::cols / 2 - mainMenuSize.x / 2, global::scoreBarHeight + global::cellSize * 5.f);
    cell.setSize(mainMenuSize);
    cell.setOutlineThickness(-2);
    cell.setOutlineColor(getColor(9));
    cell.setPosition(mainMenuPosition);
    cell.setFillColor(sf::Color(32, 32, 32, 240));
    m_window->draw(cell);

    // menu bar elements
    sf::Text text;
    text.setFont(m_font);
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);

    sf::RectangleShape selectionRect(sf::Vector2f(global::cellSize * global::cols * 0.85f, 50 * 1.f));
    selectionRect.setOutlineThickness(0);
    selectionRect.setFillColor(sf::Color(255, 255, 255, 10));
    sf::Vector2f selectionRectPosition;

    if (m_game->getState() == Pause) text.setString("RESUME");
    else text.setString("NEW GAME");
    if (m_mainMenu->getMenuSelection() == 1) {
        text.setStyle(sf::Text::Bold);
        selectionRectPosition = sf::Vector2f(global::cellSize * global::cols / 2 - selectionRect.getSize().x / 2, mainMenuPosition.y + 45.f);
        selectionRect.setPosition(selectionRectPosition);
    }
    else
        text.setStyle(sf::Text::Regular);

    text.setPosition(global::cellSize * global::cols / 2 - text.getGlobalBounds().width / 2, mainMenuPosition.y + (mainMenuSize.y / 6) * 1 - text.getGlobalBounds().height + 20);
    m_window->draw(text);

    if (m_game->getState() == Pause) text.setString("NEW GAME");
    else text.setString("SCOREBOARD");
    if (m_mainMenu->getMenuSelection() == 2) {
        text.setStyle(sf::Text::Bold);
        selectionRectPosition = sf::Vector2f(global::cellSize * global::cols / 2 - selectionRect.getSize().x / 2, mainMenuPosition.y + 130.f);
        selectionRect.setPosition(selectionRectPosition);
    }
    else
        text.setStyle(sf::Text::Regular);

    text.setPosition(global::cellSize * global::cols / 2 - text.getGlobalBounds().width / 2, mainMenuPosition.y + (mainMenuSize.y / 6) * 3 - text.getGlobalBounds().height);
    m_window->draw(text);

    if (m_game->getState() == Pause) text.setString("END GAME");
    else text.setString("QUIT");
    if (m_mainMenu->getMenuSelection() == 3) {
        text.setStyle(sf::Text::Bold);
        selectionRectPosition = sf::Vector2f(global::cellSize * global::cols / 2 - selectionRect.getSize().x / 2, mainMenuPosition.y + 225.f);
        selectionRect.setPosition(selectionRectPosition);
    }
    else
        text.setStyle(sf::Text::Regular);

    text.setPosition(global::cellSize * global::cols / 2 - text.getGlobalBounds().width / 2, mainMenuPosition.y + (mainMenuSize.y / 6) * 5 - text.getGlobalBounds().height - 10);
    m_window->draw(text);

    m_window->draw(selectionRect);

}

// public method renderGame()

void Renderer::renderGame() {

    m_window->clear();

    drawPlayField();
    drawActiveMino();
    drawScoreBar();

    m_window->display();

}

// public method renderMenu()

void Renderer::renderMenu(Gamestate state) {

    m_window->clear();

    drawPlayField();
    if (state != Start) drawScoreBar();
    drawMenu();

    m_window->display();

}
