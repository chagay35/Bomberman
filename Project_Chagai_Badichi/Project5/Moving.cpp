#include "Moving.h"



Moving::Moving(sf::Vector2f pos, sf::Vector2f size, const char* path):Object(pos,size,path){}
//=================================================================
Moving::~Moving(){}
//=================================================================
void Moving::update(float)
{
}
//=================================================================
void Moving::reSet()
{
	m_7up.setPosition(origPos);
}
