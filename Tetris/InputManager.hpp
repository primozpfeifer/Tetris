#pragma once
#include "WindowManager.hpp"
#include "Global.hpp"


class InputManager {

private:

    // private attributes

    sf::RenderWindow *m_window = nullptr;
    EnumKey m_lastPressedKey;

    // private methods

    void updateLastPressedKey(sf::Event event);


public:

    // constructor & destructor

    InputManager(WindowManager *windowManager);
    ~InputManager();

    // public methods

    void updateEvents();
    EnumKey getLastPressedKey();

};