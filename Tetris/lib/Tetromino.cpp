#include "Tetromino.h"
#include <random>

#define BLOCK_LENGTH 30.0f
#define PI 3.14159265358979323846  

Tetromino::Tetromino()
	: m_middle(sf::PrimitiveType::Points, 1)
{
	for (auto& tetro : this->m_tetro)
	{
		tetro.setOrigin(15.0f, 15.0f);
	}

	std::random_device device;
    std::mt19937 rng(device());
    std::uniform_int_distribution<std::mt19937::result_type> createTetro(0,6);

	auto shape = static_cast<Tetromino::Shape>(createTetro(rng));

	std::array<sf::Vector2f, 4> positions;
	switch (shape)
		{
		case Tetromino::Shape::O:
			this->m_texture.loadFromFile("media/tetros/blue.png");

			positions = {
				sf::Vector2f(BLOCK_LENGTH / 2, BLOCK_LENGTH / 2),    // top left
				sf::Vector2f(BLOCK_LENGTH * 1.5 , BLOCK_LENGTH / 2), // top right
				sf::Vector2f(BLOCK_LENGTH / 2, BLOCK_LENGTH * 1.5),  // bottom left
				sf::Vector2f(BLOCK_LENGTH * 1.5, BLOCK_LENGTH * 1.5) // bottom right
			};

			this->m_origin = sf::Vector2f(30.0f, 30.0f);

			break;
		case Tetromino::Shape::L:
			this->m_texture.loadFromFile("media/tetros/green.png");

			for (size_t i = 0; i < 3; i++)
			{
				positions[i] = sf::Vector2f(BLOCK_LENGTH / 2, BLOCK_LENGTH / 2 + BLOCK_LENGTH * i);
			}
			positions[3] = sf::Vector2f(BLOCK_LENGTH * 1.5, 2 * BLOCK_LENGTH + BLOCK_LENGTH / 2);
			 
			positions = {
				sf::Vector2f(BLOCK_LENGTH / 2, BLOCK_LENGTH / 2),					  // top
				sf::Vector2f(BLOCK_LENGTH / 2, BLOCK_LENGTH / 2 + BLOCK_LENGTH),	  // middle
				sf::Vector2f(BLOCK_LENGTH / 2, BLOCK_LENGTH / 2 + BLOCK_LENGTH * 2),  // bottom left
				sf::Vector2f(BLOCK_LENGTH * 1.5, 2 * BLOCK_LENGTH + BLOCK_LENGTH / 2) // bottom right
			};

			this->m_origin = sf::Vector2f(15.0f, 45.0f);

			break;
		case Tetromino::Shape::J:
			this->m_texture.loadFromFile("media/tetros/orange.png");

			positions = {
				sf::Vector2f(BLOCK_LENGTH * 1.5, BLOCK_LENGTH / 2),					    // top
				sf::Vector2f(BLOCK_LENGTH * 1.5, BLOCK_LENGTH / 2 + BLOCK_LENGTH),	    // middle
				sf::Vector2f(BLOCK_LENGTH * 1.5, BLOCK_LENGTH / 2 + BLOCK_LENGTH * 2),  // bottom left
				sf::Vector2f(BLOCK_LENGTH / 2, 2 * BLOCK_LENGTH + BLOCK_LENGTH / 2)	    // bottom right
			};

			this->m_origin = sf::Vector2f(45.0f, 45.0f);

			break;
		case Tetromino::Shape::S:
			this->m_texture.loadFromFile("media/tetros/purple.png");
			 
			positions = {
				sf::Vector2f(BLOCK_LENGTH * 2 + BLOCK_LENGTH / 2, BLOCK_LENGTH / 2), // top right
				sf::Vector2f(BLOCK_LENGTH * 1.5, BLOCK_LENGTH / 2),					 // top left
				sf::Vector2f(BLOCK_LENGTH * 1.5, BLOCK_LENGTH * 1.5),				 // bottom right
				sf::Vector2f(BLOCK_LENGTH / 2, BLOCK_LENGTH * 1.5)					 // bottom left
			};

			this->m_origin = sf::Vector2f(45.0f, 45.0f);

			break;
		case Tetromino::Shape::I:
			this->m_texture.loadFromFile("media/tetros/red.png");

			positions = {
				sf::Vector2f(BLOCK_LENGTH / 2, BLOCK_LENGTH / 2),					  // top
				sf::Vector2f(BLOCK_LENGTH / 2, BLOCK_LENGTH / 2 + BLOCK_LENGTH),	  // middle
				sf::Vector2f(BLOCK_LENGTH / 2, BLOCK_LENGTH / 2 + BLOCK_LENGTH * 2),  // bottom left
				sf::Vector2f(BLOCK_LENGTH / 2, BLOCK_LENGTH / 2 + BLOCK_LENGTH * 3)  // bottom left
			};
			
			this->m_origin = sf::Vector2f(30.0f, 60.0f);

			break;
		case Tetromino::Shape::Z:
			this->m_texture.loadFromFile("media/tetros/teal.png");

			positions = {
				sf::Vector2f(BLOCK_LENGTH / 2, BLOCK_LENGTH / 2),					  // top left
				sf::Vector2f(BLOCK_LENGTH * 1.5, BLOCK_LENGTH / 2),					  // top right
				sf::Vector2f(BLOCK_LENGTH * 1.5, BLOCK_LENGTH * 1.5),				  // bottom left
				sf::Vector2f(BLOCK_LENGTH * 2 + BLOCK_LENGTH / 2, BLOCK_LENGTH * 1.5) // bottom right
			};

			this->m_origin = sf::Vector2f(45.0f, 45.0f);

			break;
		case Tetromino::Shape::T:
			this->m_texture.loadFromFile("media/tetros/yellow.png");

			positions = {
				sf::Vector2f(BLOCK_LENGTH * 0 + BLOCK_LENGTH / 2, BLOCK_LENGTH * 1.5),
				sf::Vector2f(BLOCK_LENGTH * 1 + BLOCK_LENGTH / 2, BLOCK_LENGTH * 1.5),
				sf::Vector2f(BLOCK_LENGTH * 2 + BLOCK_LENGTH / 2, BLOCK_LENGTH * 1.5),
				sf::Vector2f(BLOCK_LENGTH * 1.5, BLOCK_LENGTH / 2)
			};

			this->m_origin = sf::Vector2f(45.0f, 45.0f);

			break;
		default:
			break;
		}

		for (size_t i = 0; i < this->m_tetro.size(); i++)
		{
			auto& tetro = this->m_tetro[i];
			tetro.setTexture(this->m_texture);
			tetro.setPosition(positions[i]);
		}

#if defined(_DEBUG)
		this->m_middle[0].position = this->m_origin;
		this->m_middle[0].color = sf::Color::Green;
#endif
}

void Tetromino::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (const auto& tetro: this->m_tetro)
		target.draw(tetro, states);
#if defined(_DEBUG)
	target.draw(m_middle);
#endif
}

void Tetromino::move(const sf::Vector2f& offset)
{
	for (auto& tetro : this->m_tetro)
		tetro.move(offset);
	this->m_origin += offset;
#if defined(_DEBUG)
	this->m_middle[0].position = this->m_origin;
#endif
}

void Tetromino::move(float x, float y)
{
	for (auto& tetro : this->m_tetro)
		tetro.move(x, y);
	this->m_origin += sf::Vector2f(x, y);
#if defined(_DEBUG)
	this->m_middle[0].position = this->m_origin;
#endif
}

inline float angToRad(float angle)
{
	return angle * (PI / 180);
}

void Tetromino::rotate(float angle)
{
	sf::Transform transform;
	transform.rotate(angle, this->m_origin);
	for (auto& tetro : this->m_tetro)
	{
		tetro.setPosition(transform.transformPoint(tetro.getPosition()));
	}
}

const sf::Vector2f& Tetromino::getPosition(const size_t i)
{
	return this->m_tetro[i].getPosition();
}

const sf::Sprite& Tetromino::getBlock(const size_t i)
{
	return this->m_tetro[i];
}
