#pragma once
#include "InputManager.hpp"
#include "Playfield.hpp"


class Game {
    
private:

    // private attributes

    InputManager *m_inputManager = nullptr;
    Playfield *m_playField = nullptr;

    EnumKey pressedKey;

    float m_gameSpeed;
    Gamestate m_gameState;
    sf::Vector2i m_nextMove;
    int m_softDrop;
    int m_hardDrop;

    int m_score;
    int m_scoreLines;
    int m_level;
    int m_playTime;

    // private methods

    Tetromino* activeMino();

    void scoreIncreaseLines(int lines);
    void scoreIncreaseDrops(int drops, int multiplier);
    void gameOver();
    
    sf::Clock m_timer1;     // playing time
    sf::Clock m_timer2;     // game tick

    
public:

    // constructor & destructor

    Game(InputManager *inputManager, Playfield *playField);
    ~Game();

    // public methods

    void newGame();
    void startGame();
    Gamestate getState();
    void setState(Gamestate state);
    std::vector<int> getStats();
    void updatePlayTime();
    void input();
    void movement();


};
