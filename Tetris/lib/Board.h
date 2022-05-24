#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <Tetromino.h>
#include <string>
#include <random>

class Board : public sf::Drawable
{
public:
	Board();
	~Board();
	 
	void drop();

	void rotate(const float angle);

	bool isGameOver();
	
private:
	bool m_gameOver;
	Tetromino* m_currentShape;
	sf::Sprite m_background;
	sf::Texture m_bgTexture;
	std::vector<sf::Sprite> m_blocks;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

