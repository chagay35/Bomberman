#include "Player.h"
#include "NonMoving.h"



Player::Player(sf::Vector2f pos,sf::Vector2f size,const char* path):Moving(pos,size,path){}
//======================================================================
Player::~Player(){}
//======================================================================
void Player::update(float deltaTime,vector<Object*>&m_object)
{
	sf::Vector2f movment(0.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		movment.x += m_speed * deltaTime;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		movment.x -= m_speed * deltaTime;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		movment.y -= m_speed * deltaTime;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		movment.y += m_speed * deltaTime;
	getObj().move(movment);
	if (checkCollision(m_object))
	{
		getObj().move(-movment);
	}
}
//======================================================================
std::string Player::getName()
{
	return m_name;
}
//======================================================================
void Player::die()
{
	m_alive = 0;
}
//======================================================================
int Player::getAlife()
{
	return m_life;
}
//======================================================================
void Player::setLife(int l)
{
	m_life = l;
}
//======================================================================
void Player::resuraction()
{
	m_alive = 1;
}
//======================================================================
bool Player::isAlive()
{
	return m_alive;
}
//======================================================================
void Player::collide(AlgoGuard & other)
{
}
//======================================================================
void Player::collide(Bombs & other)
{
}
//======================================================================
void Player::collide(Door & other)
{
	//std::cout << "NEXT LEVEL!!!\n";
}
//======================================================================
void Player::collide(Gifts & other)
{
}
//======================================================================
void Player::collide(Object & other)
{
	other.collide(*this);
}
//======================================================================
void Player::collide(Player & other)
{
}
//======================================================================
void Player::collide(RandoGuard & other)
{
	//std::cout << "YOU ARE C DEAD!!\n";
	die();
}
//======================================================================
void Player::collide(Stones & other)
{
}
//======================================================================
void Player::collide(Walls & other)
{
}

