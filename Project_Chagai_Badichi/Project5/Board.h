#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include "Moving.h"
#include "NonMoving.h"
#include "Walls.h"
#include "Stones.h"
#include "Door.h"
#include "Player.h"
#include "Gifts.h"
#include "RandoGuard.h"
using std::vector;
class controler;

class Board//the class who handeling the gameboard
{
public:
	Board();//c-tor
	~Board();//d-tor
	void readFile(vector<Object*>&,sf::Vector2u);//reading txt file, make gameboard out of it
	Player* initRob(vector<Object*>&);//make another ptr for the player
	int getNumGuards();
	sf::Vector2f cellSize;//size of 1 cell
	sf::Vector2f winSize;//size of the window
private:
	std::ifstream m_file;//var for the file
	unsigned int m_height, m_width;//vars for height & width
	int m_numGuards = 0;
};

