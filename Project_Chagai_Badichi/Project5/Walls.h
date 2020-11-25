#pragma once
#include "NonMoving.h"

class Walls:public NonMoving//class for the walls
{
public:
	Walls(sf::Vector2f pos, sf::Vector2f size, const char* path);//c-tor
	~Walls();//d-tor
	void collide(AlgoGuard& other);//all the collides
	void collide(Bombs& other);
	void collide(Door& other);
	void collide(Gifts& other);
	void collide(Object& other);
	void collide(Player& other);
	void collide(RandoGuard& other);
	void collide(Stones& other);
	void collide(Walls& other);
};

