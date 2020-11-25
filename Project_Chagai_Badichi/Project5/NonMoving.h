#pragma once
#include "Object.h"

class NonMoving:public Object//class for all non-moving parts
{
public:
	NonMoving(sf::Vector2f pos, sf::Vector2f size, const char* path);//c-tor
	~NonMoving();//d-tor
};

