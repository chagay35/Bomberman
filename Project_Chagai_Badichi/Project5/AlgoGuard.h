#pragma once
#include "Guards.h"

class AlgoGuard:public Guards//לא הצלחתי לממש את המחלקה הזו
{
public:
	AlgoGuard(sf::Vector2f, sf::Vector2f,const char*);//c-tor
	~AlgoGuard();//d-tor
	void collide(AlgoGuard& other);//and all the coolides
	void collide(Bombs& other);
	void collide(Door& other);
	void collide(Gifts& other);
	void collide(Object& other);
	void collide(Player& other);
	void collide(RandoGuard& other);
	void collide(Stones& other);
	void collide(Walls& other);
};

