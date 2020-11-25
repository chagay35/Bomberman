#include "Object.h"
#include "Moving.h"
#include "NonMoving.h"


Object::Object(sf::Vector2f pos, sf::Vector2f size, const std::string path)
{
	m_tex.loadFromFile(path);
	m_7up.setTexture(m_tex);
	m_7up.setPosition(pos);
	m_7up.scale({ size.x / m_7up.getGlobalBounds().width*0.996f,size.y / m_7up.getGlobalBounds().height*0.996f });
	origPos = pos;
}
//===========================================================================
Object::~Object(){}
//===========================================================================
sf::Sprite & Object::getObj()
{
	return m_7up;
}
//===========================================================================
bool Object::on()
{
	return false;
}
//===========================================================================
void Object::update(float,vector<Object*>&)
{
}
//===========================================================================
void Object::reSet()
{
}
//===========================================================================
sf::Vector2f Object::getPos()
{
	return m_7up.getPosition();
}
//===========================================================================
bool Object::retOn()
{
	return m_on;
}
//===========================================================================
void Object::setNextLevelDoor(bool n)
{
	m_nextLevelDoor = n;
}
//===========================================================================
bool Object::nextLevelDoor()
{
	return m_nextLevelDoor;
}
//===========================================================================
bool Object::checkCollision(std::vector<Object*>&m_object)
{
	for (auto& otherObj :m_object)
	{
		std::string name1 = typeid(otherObj).name();
		if (this == otherObj)
		{
			continue;
		}
		if (m_7up.getGlobalBounds().intersects(otherObj->m_7up.getGlobalBounds()))
		{
			this->collide(*otherObj);
			return true;
		}
	}
	return false;
}
