#pragma once
#include <time.h>
#include <iostream>
#include "Guards.h"
#include "Player.h"

class RandoGuard:public Guards//class for guards who operate randomly
{
public:
	RandoGuard(sf::Vector2f, sf::Vector2f, const char*);//c-tor
	~RandoGuard();//d-tor
	void update(float,vector<Object*>&);//moving the guard randomly
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

