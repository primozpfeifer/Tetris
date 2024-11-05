#pragma once
#include <SFML/Graphics.hpp>
#include <vector>


class Tetromino {

private:

	// private attrubites

	int m_shapeType; // 1 = I, 2 = J, 3 = L, 4 = O, 5 = S, 6 = T, 7 = Z
	std::vector<std::vector<sf::Vector2i>> m_vShapes;
	sf::Vector2i m_position;
	int m_rotationState;

	// private methods

	void initShapes(int shapeType);


public:

	// constructor & destructor

	Tetromino(int shapeType, sf::Vector2i position);
	~Tetromino();

	// public methods

	int getShapeType();
	std::vector<sf::Vector2i> getPositions();
	sf::Vector2i getPosition();
	void setPosition(sf::Vector2i position);
	void rotate(char rotation);

};