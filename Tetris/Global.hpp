#pragma once


enum Gamestate {

    Start,
    Playing,
    Pause,
    Gameover,
    Quit

};

enum EnumKey {

    none,
    Escape,
    Up,
    Down,
    Left,
    Right,
    Space,
    Enter,
    
};


namespace global {

    const int cols = 12;
    const int rows = 21;
    const int cellSize = 40;
    const int scoreBarHeight = 100;

    const float gameSpeed = 0.8f;

    //inline Gamestate gameState;

}

