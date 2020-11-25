#include "AlgoGuard.h"
#include "NonMoving.h"



AlgoGuard::AlgoGuard(sf::Vector2f pos,sf::Vector2f size,const char* path):Guards(pos,size,path){}
//=================================================================
AlgoGuard::~AlgoGuard(){}
//=================================================================
void AlgoGuard::collide(AlgoGuard & other)
{
}
//=================================================================
void AlgoGuard::collide(Bombs & other)
{
}
//=================================================================
void AlgoGuard::collide(Door & other)
{
}
//=================================================================
void AlgoGuard::collide(Gifts & other)
{
}
//=================================================================
void AlgoGuard::collide(Object & other)
{
	other.collide(*this);
}
//=================================================================
void AlgoGuard::collide(Player & other)
{
}
//=================================================================
void AlgoGuard::collide(RandoGuard & other)
{
}
//=================================================================
void AlgoGuard::collide(Stones & other)
{
}
//=================================================================
void AlgoGuard::collide(Walls & other)
{
}
