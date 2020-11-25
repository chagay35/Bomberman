#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
class Controller;
class AlgoGuard;
class Bombs;
class Door;
class Gifts;
class Guards;
class Moving;
class NonMoving;
class Player;
class RandoGuard;
class Stones;
class Walls;
using std::vector;

class Object//the class who make haritage to all other classes
{
public:
	Object(sf::Vector2f pos, sf::Vector2f size, const std::string path);//c-tor, create object with position, size and picture
	~Object();//d-tor
	sf::Sprite& getObj();//return the sprite of object
	virtual bool on();
	virtual void update(float,vector<Object*>&);//another name for 'move' for moving parts
	virtual void reSet();//go back to originl position after strike (or death)
	sf::Vector2f getPos();//return position
	bool retOn();
	sf::Vector2f origPos;//remember original position
	void setNextLevelDoor(bool);//to re/set it
	bool nextLevelDoor();//if on you get to the next level
	virtual void collide(Object& other) = 0;//all the collides
	virtual void collide(AlgoGuard& other) = 0;
	virtual void collide(Bombs& other) = 0;
	virtual void collide(Door& other) = 0;
	virtual void collide(Gifts& other) = 0;
	virtual void collide(Player& other) = 0;
	virtual void collide(RandoGuard& other) = 0;
	virtual void collide(Stones& other) = 0;
	virtual void collide(Walls& other) = 0;
	bool checkCollision(std::vector<Object*>&m_object);
protected:
	sf::Sprite m_7up;//you got it?
	sf::Texture m_tex;//for the picture
	bool m_on = 1;
	bool m_nextLevelDoor = false;//you dont go to the next level so fast...
};

