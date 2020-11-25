#include "Controller.h"
#include <iostream>
#include <string>

static const float HEIGHT = 614.0f;
static const float WIDTH = 614.0f;

Controller::Controller()
{
	m_window.create(sf::VideoMode((unsigned int)WIDTH,(unsigned int) HEIGHT), "BOMBERMAN", sf::Style::Default);
}
//===================================================================
Controller::~Controller(){}
//===================================================================
void Controller::run()
{
	sf::View view(sf::Vector2f(WIDTH / 2, HEIGHT / 2), sf::Vector2f(WIDTH, HEIGHT));
	sf::Clock tik;
	deltaTime = 0.0f;
	setLevl();
	while (m_window.isOpen() && m_rob && m_rob->getAlife())
	{
		m_firsTime = 1;
		deltaTime = tik.restart().asSeconds();
		sf::Event eve;
		while (m_window.pollEvent(eve))
		{
			switch (eve.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::Resized:
				resizeView(view);
				break;
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					//std::cout << (int)'D' << std::endl;
					death();
				}
			}
		}
		if ((m_firsTime && !m_rob->isAlive()))
		{
			death();
		}
		m_rob->update(deltaTime,m_objects);
		for (size_t i = 0; i < m_objects.size(); i++)
		{
			if (typeid(*m_objects[i]) == typeid(RandoGuard))
			{
				m_objects[i]->update(deltaTime,m_objects);
			}
			if (typeid(*m_objects[i]) == typeid(Door))
			{
				if (m_objects[i]->nextLevelDoor())
				{
					m_level++;
					//std::cout << "CONTROLLER  typ  " << m_rob->nextLevelDoor() << std::endl;
					m_score += 20 * m_numGuards;
					m_numGuards = 0;
					m_objects.clear();
					setLevl();
				}
			}
		}
		m_window.setView(view);
		m_window.clear(sf::Color::White);
		for (auto m : m_objects)
			m_window.draw(m->getObj());
		bar();
		m_window.display();
	}
	//std::cout << "\n       !!!GAME OVER!!!\n"  ;
	//waitForEnter();
}
//=========================================================================
void Controller::setLevl()
{
	m_board.readFile(m_objects, m_window.getSize());
	m_rob = m_board.initRob(m_objects);
	if (!m_rob)
	{
		return;
	}
	m_rob->setLife(m_rob->getAlife());
	m_rob->resuraction();
	m_rob->setNextLevelDoor(0);
	m_numGuards = m_board.getNumGuards();
	//std::cout <<"STLVL"<< m_rob->nextLevelDoor() << std::endl;
}
//=========================================================================
void Controller::resizeView(sf::View & view)
{
	float aspectRatio = float(m_window.getSize().x / float(m_window.getSize().y));
	view.setSize(HEIGHT * aspectRatio, HEIGHT);
}
//=========================================================================
void Controller::death()
{
	m_firsTime = 0;
	for (size_t i = 0; i < m_objects.size(); i++)
	{
		if (typeid(*m_objects[i]) == typeid(RandoGuard) || typeid(*m_objects[i]) == typeid(Player))
		{
			m_objects[i]->reSet();
		}
	}
	m_rob->setLife(m_rob->getAlife() - 1);
	m_robLife = m_rob->getAlife();
	//std::cout << m_rob->getAlife() << std::endl;
	m_rob->resuraction();
}
//=========================================================================
void Controller::bar()
{
	std::string str = " ";
	str += "LEVEL: " + std::to_string(m_level) + "|| LIFE: " + std::to_string(m_robLife) + "||  SCORE: " + std::to_string(m_score);
	sf::Font f;
	f.loadFromFile("arial.ttf");
	sf::Text t;
	t.setFont(f);
	t.setString(str);
	t.setFillColor(sf::Color::Green);
	m_window.draw(t);
}
//=========================================================================
void Controller::waitForEnter()
{
	std::cout << "Press Enter to continue...\n";
	std::string line;
	std::getline(std::cin, line);
}

