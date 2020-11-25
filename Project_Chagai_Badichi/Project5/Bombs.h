#pragma once
#include "NonMoving.h"

class Bombs:public NonMoving//לא הצלחתי לממש את המחלקה הזו
{
public:
	Bombs(sf::Vector2f,sf::Vector2f,const char*);//c-tor
	~Bombs();//d-tor
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

