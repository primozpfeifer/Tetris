#pragma once
#include "Tetromino.hpp"


// constructor

Tetromino::Tetromino(int shapeType, sf::Vector2i position) {

	m_position = position;
	m_shapeType = shapeType;
	initShapes(shapeType);
	m_rotationState = 0;
	
}

// destructor

Tetromino::~Tetromino()	{}


// private method initShapes()

void Tetromino::initShapes(int shapeType) {

	switch (shapeType) {
	
	case 1:	// I
		m_vShapes.push_back({ {0,1},{1,1},{2,1},{3,1} });
		m_vShapes.push_back({ {2,0},{2,1},{2,2},{2,3} });
		m_vShapes.push_back({ {0,2},{1,2},{2,2},{3,2} });
		m_vShapes.push_back({ {1,0},{1,1},{1,2},{1,3} });
		break;

	case 2:	// J
		m_vShapes.push_back({ {0,0},{0,1},{1,1},{2,1} });
		m_vShapes.push_back({ {1,0},{1,1},{1,2},{2,0} });
		m_vShapes.push_back({ {0,1},{1,1},{2,1},{2,2} });
		m_vShapes.push_back({ {0,2},{1,0},{1,1},{1,2} });
		break;

	case 3:	// L
		m_vShapes.push_back({ {2,0},{0,1},{1,1},{2,1} });
		m_vShapes.push_back({ {1,0},{1,1},{1,2},{2,2} });
		m_vShapes.push_back({ {0,1},{0,2},{1,1},{2,1} });
		m_vShapes.push_back({ {0,0},{1,0},{1,1},{1,2} });
		break;

	case 4:	// O
		m_vShapes.push_back({ {0,0},{1,0},{0,1},{1,1} });
		break;

	case 5:	// S
		m_vShapes.push_back({ {1,0},{2,0},{0,1},{1,1} });
		m_vShapes.push_back({ {1,0},{1,1},{2,1},{2,2} });
		m_vShapes.push_back({ {0,2},{1,1},{1,2},{2,1} });
		m_vShapes.push_back({ {0,0},{0,1},{1,1},{1,2} });
		break;

	case 6:	// T
		m_vShapes.push_back({ {0,1},{1,1},{1,0},{2,1} });
		m_vShapes.push_back({ {1,0},{1,1},{1,2},{2,1} });
		m_vShapes.push_back({ {0,1},{1,1},{1,2},{2,1} });
		m_vShapes.push_back({ {0,1},{1,0},{1,1},{1,2} });
		break;

	case 7:	// Z
		m_vShapes.push_back({ {0,0},{1,0},{1,1},{2,1} });
		m_vShapes.push_back({ {1,1},{1,2},{2,0},{2,1} });
		m_vShapes.push_back({ {0,1},{1,1},{1,2},{2,2} });
		m_vShapes.push_back({ {0,1},{0,2},{1,0},{1,1} });
		break;

	}

}

// public method getShapeType()

int Tetromino::getShapeType() {

	return m_shapeType;

}

// public method getPositions()

std::vector<sf::Vector2i> Tetromino::getPositions() {

	std::vector<sf::Vector2i> vPositions;

	for (int i = 0; i < 4; i++) {

		vPositions.push_back(m_position + m_vShapes[m_rotationState][i]);

	}

	return vPositions;
}

// public method getPosition()

sf::Vector2i Tetromino::getPosition() {

	return m_position;

}

// public method setPosition()

void Tetromino::setPosition(sf::Vector2i position) {

	m_position = position;

}

// public method rotate()

void Tetromino::rotate(char rotation) {
	
	if (m_shapeType == 4)
		return;
	
	if (rotation == '+')
		m_rotationState++;
	if (rotation == '-')
		m_rotationState--;

	if (m_rotationState == 4)
		m_rotationState = 0;
	if (m_rotationState == -1)
		m_rotationState = 3;
}

