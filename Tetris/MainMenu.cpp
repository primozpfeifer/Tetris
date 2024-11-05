#pragma once
#include "MainMenu.hpp"


// constructor

MainMenu::MainMenu(InputManager *inputManager, Game *game) {

	m_inputManager = inputManager;
	m_game = game;

	m_menuSelection = 1;
    m_menuSelected = false;

}

// destructor

MainMenu::~MainMenu() {}


// public method input()

void MainMenu::input() {

    m_inputManager->updateEvents();
    m_pressedKey = m_inputManager->getLastPressedKey();

    switch (m_pressedKey) {

    case Up:
        if (m_menuSelection > 1)
            m_menuSelection--;
        break;

    case Down:
        if (m_menuSelection < 3)
            m_menuSelection++;
        break;

    case Enter:
        m_menuSelected = true;
        break;

    }

}

// public method action()

void MainMenu::action() {

    if (!m_menuSelected)
        return;

    m_menuSelected = false;


    switch (m_menuSelection) {

    case 1:
        if (m_game->getState() == Pause)
            m_game->setState(Playing);
        else
            m_game->newGame();
        break;

    case 2:
        if (m_game->getState() == Pause)
            m_game->newGame();
        else
            return; // opens scoreboard
        break;

    case 3:
        if (m_game->getState() == Pause)
            m_game->startGame();
        else
            m_game->setState(Quit);
        break;

    }

    m_menuSelection = 1;

}

// public method getMenuSelection()

int MainMenu::getMenuSelection()
{

    return m_menuSelection;

}
