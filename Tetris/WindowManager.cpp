#pragma once
#include "WindowManager.hpp"


// constructor

WindowManager::WindowManager() {

    m_window.create(sf::VideoMode(global::cellSize * global::cols, global::cellSize * global::rows + global::scoreBarHeight), "Tetris", sf::Style::Titlebar);
    m_window.setKeyRepeatEnabled(false);

}

// destructor

WindowManager::~WindowManager() {}


// public method getWindow()

sf::RenderWindow *WindowManager::getWindow() {

    return &m_window;

}

