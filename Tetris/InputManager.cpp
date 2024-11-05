#pragma once
#include "InputManager.hpp"


// constructor

InputManager::InputManager(WindowManager *windowManager) {

    m_window = windowManager->getWindow();

}

// destructor

InputManager::~InputManager() {}


// private method updateLastPressedKey()

void InputManager::updateLastPressedKey(sf::Event event) {

    switch (event.key.code) {

    case sf::Keyboard::Escape:
        m_lastPressedKey = Escape;
        break;

    case sf::Keyboard::Left:
        m_lastPressedKey = Left;
        break;

    case sf::Keyboard::Right:
        m_lastPressedKey = Right;
        break;

    case sf::Keyboard::Up:
        m_lastPressedKey = Up;
        break;

    case sf::Keyboard::Down:
        m_lastPressedKey = Down;
        break;

    case sf::Keyboard::Space:
        m_lastPressedKey = Space;
        break;

    case sf::Keyboard::Enter:
        m_lastPressedKey = Enter;
        break;

    }



}

// public method updateEvents()

void InputManager::updateEvents() {

    m_lastPressedKey = none;
    sf::Event event;

    while (m_window->pollEvent(event)) {

        if (event.type == sf::Event::KeyPressed)
            updateLastPressedKey(event);

    }
    
}

// public method getLastPressedKey()

EnumKey InputManager::getLastPressedKey() {

    return m_lastPressedKey;

}

