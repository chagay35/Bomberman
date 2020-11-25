#include "RandoGuard.h"
#include "NonMoving.h"



RandoGuard::RandoGuard(sf::Vector2f pos,sf::Vector2f size,const char* path):Guards(pos,size,path){}
//==================================================================================
RandoGuard::~RandoGuard(){}
//==================================================================================
void RandoGuard::update(float deltaTime,vector<Object*>& m_object)
{
	int t = rand() % 5;
	sf::Vector2f movment(0.0f, 0.0f);
	switch (t)
	{
	case 1:
		movment.x += m_speed * deltaTime;
		break;
	case 2:
		movment.x -= m_speed * deltaTime;
		break;
	case 3:
		movment.y -= m_speed * deltaTime;
		break;
	case 4:
		movment.y += m_speed * deltaTime;
		break;
	}
	getObj().move(movment);
	if (checkCollision(m_object))
	{
		getObj().move(-movment);
		if (typeid(m_object) == typeid(Player))
		{
			
			//std::cout << "YOU ARE DEAD!!\n";
		}
	}
}
//==================================================================================
void RandoGuard::collide(AlgoGuard & other)
{
}
//==================================================================================
void RandoGuard::collide(Bombs & other)
{
}
//==================================================================================
void RandoGuard::collide(Door & other)
{
}
//==================================================================================
void RandoGuard::collide(Gifts & other)
{
}
//==================================================================================
void RandoGuard::collide(Object & other)
{
	other.collide(*this);
}
//==================================================================================
void RandoGuard::collide(Player & other)
{
	//std::cout << "YOU ARE WW DEAD!!!\n";
}
//==================================================================================
void RandoGuard::collide(RandoGuard & other)
{
}
//==================================================================================
void RandoGuard::collide(Stones & other)
{
}
//==================================================================================
void RandoGuard::collide(Walls & other)
{
}
