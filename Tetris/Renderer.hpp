#pragma once
#include "WindowManager.hpp"
#include "Playfield.hpp"
#include "Game.hpp"
#include "MainMenu.hpp"


class Renderer {

private:

	// private attributes

	sf::RenderWindow *m_window = nullptr;
	Playfield *m_playField = nullptr;
	Game* m_game = nullptr;
	MainMenu* m_mainMenu = nullptr;
	sf::Font m_font;

	// private methods

	sf::Color getColor(int positionType);
	void drawPlayField();
	void drawActiveMino();
	void drawScoreBar();
	void drawMenu();


public:

	// constructor & destructor

	Renderer(WindowManager *windowManager, Playfield *playField, Game *game, MainMenu *mainMenu);
	~Renderer();

	// public methods

	void renderGame();
	void renderMenu(Gamestate state);

};