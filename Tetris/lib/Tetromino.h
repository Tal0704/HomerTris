#pragma once

#include <SFML/Graphics.hpp>
#include <array>
#include <string>
#include <math.h>

#if defined(_DEBUG)
#include <iostream>
#endif

#define BLOCK_LENGTH 30.0f

class Tetromino : public sf::Drawable
{
public:
	enum class Shape
	{
		O = 0,
		L,
		J,
		S,
		I,
		Z,
		T
	};

	Tetromino();

	void move(const sf::Vector2f& offset);
	void move(float x, float y);

	void rotate(float angle);

	const sf::Vector2f& getPosition(const size_t i);
	
	const sf::Sprite& getBlock(const size_t i);

private:
	std::array<sf::Sprite, 4> m_tetro;
	sf::Texture m_texture;
	sf::Vector2f m_origin;
	sf::VertexArray m_middle;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
