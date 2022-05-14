#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <Tetromino.h>
#include <string>

class Board : public sf::RenderWindow
{
public:
	static Board* getInstance()
	{
		if (!m_instance)
			m_instance = new Board;
		return m_instance;
	}
	 
	void fall();
	
private:
	Tetromino* m_currentShape;

	Board();

	std::vector<sf::Sprite> m_blocks;
	static Board* m_instance;
};

