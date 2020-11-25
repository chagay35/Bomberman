#include "Bombs.h"
#include "Moving.h"



Bombs::Bombs(sf::Vector2f pos,sf::Vector2f size,const char* path):NonMoving(pos,size,path){}
//=================================================================
Bombs::~Bombs(){}
//=================================================================
void Bombs::collide(AlgoGuard & other)
{
}
//=================================================================
void Bombs::collide(Bombs & other)
{
}
//=================================================================
void Bombs::collide(Door & other)
{
}
//=================================================================
void Bombs::collide(Gifts & other)
{
}
//=================================================================
void Bombs::collide(Object & other)
{
	other.collide(*this);
}
//=================================================================
void Bombs::collide(Player & other)
{
}
//=================================================================
void Bombs::collide(RandoGuard & other)
{
}
//=================================================================
void Bombs::collide(Stones & other)
{
}
//=================================================================
void Bombs::collide(Walls & other)
{
}
