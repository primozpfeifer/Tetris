#pragma once
#include <SFML/Graphics.hpp>
#include "Global.hpp"


class WindowManager {

private:

    // private attributes

    sf::RenderWindow m_window;


public:

    // constructor & destructor

    WindowManager();
    ~WindowManager();

    // public methods

    sf::RenderWindow* getWindow();


};
