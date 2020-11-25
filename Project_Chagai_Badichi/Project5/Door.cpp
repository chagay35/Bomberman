#include "Door.h"
#include "Moving.h"
#include "Controller.h"




Door::Door(sf::Vector2f pos, sf::Vector2f size, const char* path):NonMoving(pos,size,path){}
//==================================================================
Door::~Door(){}
//==================================================================
void Door::collide(AlgoGuard & other)
{
}
//==================================================================
void Door::collide(Bombs & other)
{
}
//==================================================================
void Door::collide(Door & other)
{
}
//==================================================================
void Door::collide(Gifts & other)
{
}
//==================================================================
void Door::collide(Object & other)
{
	other.collide(*this);
}
//==================================================================
void Door::collide(Player & other)
{
	//std::cout << "KANES\n";
	m_nextLevelDoor = true;
	//std::cout << "DELET " << m_nextLevelDoor << std::endl;
}
//==================================================================
void Door::collide(RandoGuard & other)
{
}
//==================================================================
void Door::collide(Stones & other)
{
}
//==================================================================
void Door::collide(Walls & other)
{
}
