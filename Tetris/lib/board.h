#pragma once
#include <vector>
#include <Tetromino.h>
#include <SFML/Graphics.hpp>
#include <array>

#if defined(_DEBUG)
#include <iostream>
#endif

class Board : public sf::Drawable
{
public:
	Board();

	void fall();
	
	void moveLeft();
	void moveRight();

	void rotate(float ang);


private:
	std::vector<sf::Sprite> m_blocks;
	Tetromino* m_shape;

	std::array<sf::Vector2f, 10> m_topBlocks;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void blockIsDown();
	void updateTopBlocks();
	bool isDown();
};

