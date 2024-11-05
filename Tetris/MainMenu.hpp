#pragma once
#include "InputManager.hpp"
#include "Game.hpp"


class MainMenu {

private:

	// private attributes

	InputManager *m_inputManager = nullptr;
	Game *m_game = nullptr;

	EnumKey m_pressedKey;
	int m_menuSelection;
	bool m_menuSelected;

	// private methods




public:

	// constructor & destructor

	MainMenu(InputManager *inputManager, Game *game);
	~MainMenu();

	// public methods

	void input();
	void action();
	int getMenuSelection();

};

