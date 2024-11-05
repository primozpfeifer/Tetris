#pragma once
#include "Playfield.hpp"


// constructor

Playfield::Playfield() {}

// destructor

Playfield::~Playfield() {}


// public method resetPlayField()

void Playfield::resetPlayField() {

	for (int y = 0; y < global::rows; y++) {

		for (int x = 0; x < global::cols; x++) {

			if (x == 0 || x == global::cols -1 || y == global::rows - 1)

				m_grid[y][x] = 8;
			
			else

				m_grid[y][x] = 0;

		}

	}

}

// public method introPlayField()

void Playfield::introPlayField() {

	resetPlayField();

	m_grid[0][3] = 3; m_grid[0][5] = 7;	m_grid[0][6] = 7;
	m_grid[1][3] = 3; m_grid[1][5] = 7;
	m_grid[2][1] = 5; m_grid[2][3] = 3;	m_grid[2][4] = 3; m_grid[2][5] = 6;
	m_grid[3][1] = 5; m_grid[3][2] = 5;	m_grid[3][4] = 6; m_grid[3][5] = 6;	m_grid[3][6] = 6; m_grid[3][7] = 4;	m_grid[3][8] = 4;
	m_grid[4][1] = 5; m_grid[4][2] = 5;	m_grid[4][4] = 5; m_grid[4][5] = 5;	m_grid[4][6] = 7; m_grid[4][7] = 4;	m_grid[4][8] = 4; m_grid[4][9] = 2;
	m_grid[5][1] = 5; m_grid[5][2] = 5;	m_grid[5][3] = 5; m_grid[5][4] = 5;	m_grid[5][5] = 7; m_grid[5][6] = 7;	m_grid[5][7] = 5; m_grid[5][8] = 5;	m_grid[5][9] = 2;
	m_grid[6][1] = 6; m_grid[6][2] = 5;	m_grid[6][3] = 7; m_grid[6][4] = 7;	m_grid[6][5] = 7; m_grid[6][6] = 5;	m_grid[6][7] = 5; m_grid[6][8] = 2;	m_grid[6][9] = 2;
	m_grid[7][2] = 5; m_grid[7][3] = 6;	m_grid[7][4] = 4; m_grid[7][5] = 4;	m_grid[7][6] = 2; m_grid[7][7] = 3;	m_grid[7][9] = 2; m_grid[7][10] = 2;
	m_grid[8][2] = 5; m_grid[8][3] = 5;	m_grid[8][4] = 4; m_grid[8][5] = 4;	m_grid[8][6] = 4; m_grid[8][7] = 4;	m_grid[8][9] = 3; m_grid[8][10] = 3;
	m_grid[9][2] = 5; m_grid[9][3] = 5;	m_grid[9][4] = 4; m_grid[9][5] = 4;	m_grid[9][6] = 4; m_grid[9][7] = 4;	m_grid[9][9] = 3; m_grid[9][10] = 3;
	m_grid[10][2] = 5; m_grid[10][3] = 5; m_grid[10][4] = 4; m_grid[10][5] = 4;	m_grid[10][6] = 4; m_grid[10][7] = 4; m_grid[10][9] = 3; m_grid[10][10] = 3;
	m_grid[11][2] = 5; m_grid[11][3] = 5; m_grid[11][4] = 4; m_grid[11][5] = 4;	m_grid[11][6] = 4; m_grid[11][7] = 4; m_grid[11][8] = 5; m_grid[11][9] = 3; m_grid[11][10] = 3;
	m_grid[12][2] = 5; m_grid[12][3] = 5; m_grid[12][4] = 4; m_grid[12][5] = 4;	m_grid[12][6] = 3; m_grid[12][7] = 5; m_grid[12][8] = 5; m_grid[12][9] = 5;	m_grid[12][10] = 2;
	m_grid[13][2] = 1; m_grid[13][3] = 5; m_grid[13][4] = 3; m_grid[13][5] = 3;	m_grid[13][6] = 3; m_grid[13][7] = 5; m_grid[13][8] = 5; m_grid[13][9] = 5;	m_grid[13][10] = 2;
	m_grid[14][2] = 1; m_grid[14][3] = 1; m_grid[14][4] = 2; m_grid[14][5] = 2;	m_grid[14][6] = 5; m_grid[14][7] = 5; m_grid[14][8] = 5; m_grid[14][9] = 2;	m_grid[14][10] = 2;
	m_grid[15][2] = 1; m_grid[15][3] = 1; m_grid[15][4] = 2; m_grid[15][5] = 5;	m_grid[15][6] = 5; m_grid[15][7] = 4; m_grid[15][8] = 4; m_grid[15][9] = 2;	m_grid[15][10] = 2;
	m_grid[16][2] = 1; m_grid[16][3] = 1; m_grid[16][4] = 2; m_grid[16][5] = 5;	m_grid[16][6] = 5; m_grid[16][7] = 4; m_grid[16][8] = 4; m_grid[16][9] = 2;	m_grid[16][10] = 1;
	m_grid[17][2] = 7; m_grid[17][3] = 1; m_grid[17][4] = 5; m_grid[17][5] = 5;	m_grid[17][6] = 2; m_grid[17][7] = 2; m_grid[17][8] = 2; m_grid[17][9] = 2;	m_grid[17][10] = 1;
	m_grid[18][1] = 1; m_grid[18][2] = 2; m_grid[18][3] = 1; m_grid[18][4] = 1; m_grid[18][5] = 5; m_grid[18][6] = 3; m_grid[18][8] = 1; m_grid[18][9] = 4;	m_grid[18][10] = 4;
	m_grid[19][1] = 1; m_grid[19][2] = 1; m_grid[19][3] = 1; m_grid[19][4] = 1; m_grid[19][5] = 1; m_grid[19][6] = 5; m_grid[19][8] = 1; m_grid[19][9] = 4;	m_grid[19][10] = 4;

}

// public method setPositionType()

void Playfield::setPositionType(sf::Vector2i position, int shapeType) {

	m_grid[position.y][position.x] = shapeType;

}

// public method getPositionType()

int Playfield::getPositionType(sf::Vector2i position) {

	return m_grid[position.y][position.x];

}

// public method getActiveMino()

Tetromino* Playfield::getActiveMino() {

	return &m_vMino[0];

}

// public method spawnMino()

void Playfield::spawnMino() {

	// Mino shape type randomizer
	std::mt19937 seed(std::random_device{}());
	std::uniform_int_distribution dist(1, 7);
	int shapeType = dist(seed);

	// Mino starting position
	sf::Vector2i position;
	position.x = (global::cols - 4) / 2;
	position.y = -2;
	if (shapeType == 4) position.x += 1;

	// Mino object creation
	m_vMino.clear();
	m_vMino.push_back(Tetromino(shapeType, position));
}

// public method getFullLines()

std::vector<int> Playfield::getFullLines() {

	std::vector<int> vFullLines;

	for (int y = global::rows - 2; y >= 0; y--) {

		int elementsInLine = 0;

		for (int x = 1; x < global::cols - 1; x++) {

			// count elements in line
			if (m_grid[y][x] > 0 && m_grid[y][x] < 8) elementsInLine++;

			// if line full
			if (elementsInLine == global::cols - 2)
				vFullLines.push_back(y);

		}

		// exit loop when first empty line is found
		if (elementsInLine == 0)
			break;

	}

	return vFullLines;;

}

// public method deleteLines()

void Playfield::deleteLines(std::vector<int> vLines) {

	for (int i = 0; i < vLines.size(); i++) {

		for (int y = vLines[i] - 1 + i; y >= 0; y--) {

			int elementsInLine = 0;

			for (int x = 1; x < global::cols - 1; x++) {

				m_grid[y + 1][x] = m_grid[y][x];
				if (m_grid[y][x] != 0) elementsInLine++;

			}

			// break out of for loop on first empty line
			if (elementsInLine == 0)
				break;

		}
		
	}

}
