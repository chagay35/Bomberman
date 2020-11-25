#pragma once
#include "Object.h"
#include <string>

class Moving:public Object//class for all moving parts
{
public:
	Moving(sf::Vector2f, sf::Vector2f, const char*);//c-tor
	~Moving();//d-tor
	virtual void update(float);//other name for move
	void reSet();//go back to originl position after strike (or death)
};

