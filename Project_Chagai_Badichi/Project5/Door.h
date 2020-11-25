#pragma once
#include "NonMoving.h"

class Door:public NonMoving//מימוש לא משלם
{
public:
	Door(sf::Vector2f, sf::Vector2f, const char*);//c-tor
	~Door();//d-tor
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

