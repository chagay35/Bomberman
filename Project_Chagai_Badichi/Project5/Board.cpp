#include "Board.h"




Board::Board()
{
	m_file.open("Board.txt");
}
//=================================================================
Board::~Board()
{
	m_file.close();
}
//=================================================================
void Board::readFile(vector<Object*>&m_objects, sf::Vector2u winSize)
{
	
	std::string line;
	if (m_file.is_open())
	{
		getline(m_file, line);
		std::istringstream iss(line);
		iss.clear();
		iss >> m_width >> m_height;
		cellSize = { (float)winSize.x / m_width, (float)winSize.y / m_height };
		m_numGuards = 0;
		for (size_t i = 0; i < m_height; i++)
		{
			for (size_t j = 0; j < m_width; j++)
			{
				switch (m_file.get())
				{
				case'#':
					m_objects.push_back(new Walls({ (cellSize.x) * j,(cellSize.y) * i }, cellSize, "wall.jpg"));
					//std::cout << m_objects.size() << ' ';
					break;
				case '@':
					m_objects.push_back(new Stones({ (cellSize.x) * j,(cellSize.y) * i }, cellSize, "stone.jpg"));
					break;
				case '&':
					m_objects.push_back(new Gifts({ (cellSize.x) * j,(cellSize.y) * i }, cellSize, "gift.jpg"));
					break;
				case 'D':
					m_objects.push_back(new Door({ (cellSize.x) * j,(cellSize.y) * i }, cellSize, "door.jpg"));
					break;
				case '/':
					m_objects.push_back(new Player({ (cellSize.x) * j,(cellSize.y) * i }, cellSize, "qt.jpg"));
					break;
				case '!':
					m_objects.push_back(new RandoGuard({ (cellSize.x) * j,(cellSize.y) * i }, cellSize, "terminator02.jpg"));
					m_numGuards++;
					break;
				}
			}
			m_file.get();
		}
	}
}
//=================================================================
Player * Board::initRob(vector<Object*>& m_object)
{
	for (auto a : m_object)
	{
		if (typeid(*a) == typeid(Player))
		{
			Player* temp = dynamic_cast<Player*>(a);
			return temp;
		}
	}
	return nullptr;
}
//=================================================================
int Board::getNumGuards()
{
	return m_numGuards;
}