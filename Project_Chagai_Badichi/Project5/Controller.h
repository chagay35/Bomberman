#pragma once
#include <vector>
#include "Player.h"
#include "Walls.h"
#include "Board.h"
using std::vector;

class Controller//the class who run the game
{
public:
	Controller();//c-tor, and create the window
	~Controller();//d-tor
	void run();//the main func
	void setLevl();//read each level from txt file to window
	void resizeView(sf::View& view);//to make sure that propotion stay the same 
	void death();//morbid name for handeling strike
	void bar();//printing bar to window
	void waitForEnter();//just for watch cout on the console
	float deltaTime;//for the movment
private:
	bool m_firsTime;//to make sure every func called one time only
	Board m_board;//the board
	Player* m_rob;//the player
	sf::RenderWindow m_window;//the window
	vector<Object*>m_objects;//for all the other stuff
	int m_level = 1;//number of levels for the bar
	int m_robLife;//number of lives for the bar
	int m_score = 0;//the score
	int m_numGuards;
};

