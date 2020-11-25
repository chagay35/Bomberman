#pragma once
#include "Moving.h"

class Guards:public Moving//לא הצלחתי לממש את כל המחלקה הזו
{
public:
	Guards(sf::Vector2f,sf::Vector2f,const char*);//c-tor
	~Guards();//d-tor
	void update(float,vector<Object*>&);//other name for move
protected:
	int m_speed = 200;//the speed
};

