#pragma once
#include <iostream>
#include "Moving.h"
#include "RandoGuard.h"

class Player:public Moving//handeling the robot
{
public:
	Player(sf::Vector2f, sf::Vector2f,const char*);//c-tor
	~Player();//d-tor
	virtual void update(float,vector<Object*>&);//get orders from keyboard to move the robot
	std::string getName();//can't remember why he has a name
	void die();//again, morbid name for 'strike'
	int getAlife();//return how much strikes had left(seriously get!)
	void setLife(int);//set strikes that left
	void resuraction();//after 1 strike
	bool isAlive();//to know if strike
	void collide(AlgoGuard& other);//all the collide
	void collide(Bombs& other);
	void collide(Door& other);
	void collide(Gifts& other);
	void collide(Object& other);
	void collide(Player& other);
	void collide(RandoGuard& other);
	void collide(Stones& other);
	void collide(Walls& other);
private:
	bool m_alive;//to know if strike
	int m_life = 3;//the strikes you got
	int m_speed = 300;//the speed
	std::string m_name = "robi";//can't remember why he has a name
};

