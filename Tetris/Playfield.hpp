#pragma once
#include "Global.hpp"
#include "SFML/Graphics.hpp"
#include "Tetromino.hpp"
#include <random>


class Playfield {

private:

    // private attributes

    int m_grid[global::rows][global::cols];
    std::vector<Tetromino> m_vMino;

    // private methods

    
public:

    // constructor & destructor

    Playfield();
    ~Playfield();

    // public methods

    void resetPlayField();
    void introPlayField();
    void setPositionType(sf::Vector2i position, int shapeType);
    int getPositionType(sf::Vector2i position);

    Tetromino* getActiveMino();
    std::vector<int> getFullLines();
    void deleteLines(std::vector<int> vLines);
    void spawnMino();

};