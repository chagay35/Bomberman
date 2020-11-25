#include "Gifts.h"
#include "Moving.h"



Gifts::Gifts(sf::Vector2f pos, sf::Vector2f size, const char* path) :NonMoving(pos, size, path) {}
//========================================================================
Gifts::~Gifts(){}
//========================================================================
void Gifts::collide(AlgoGuard & other)
{
}
//========================================================================
void Gifts::collide(Bombs & other)
{
}
//========================================================================
void Gifts::collide(Door & other)
{
}
//========================================================================
void Gifts::collide(Gifts & other)
{
}
//========================================================================
void Gifts::collide(Object & other)
{
	other.collide(*this);
}
//========================================================================
void Gifts::collide(Player & other)
{
}
//========================================================================
void Gifts::collide(RandoGuard & other)
{
}
//========================================================================
void Gifts::collide(Stones & other)
{
}
//========================================================================
void Gifts::collide(Walls & other)
{
}
