#include "Board.h"

#define BLOCK_LENGTH 30.0f

Board::Board()
    : m_blocks(), m_currentShape(nullptr)
{
	std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> distShape(0,6);

    this->m_currentShape = new Tetromino(static_cast<Tetromino::Shape>(distShape(dev)));

    this->m_bgTexture.loadFromFile("media/background/bg.png", sf::Rect<int>(0, 0, 300, 510));
    this->m_background.setTexture(this->m_bgTexture);
}

Board::~Board()
{
    delete this->m_currentShape;
}

void Board::drop()
{
	this->m_currentShape->move(0.0f, BLOCK_LENGTH);
    if (this->m_currentShape->isInBounds())
    {
        // check if needs update or game over
    }
}

void Board::rotate(const float angle)
{
	this->m_currentShape->rotate(angle);
    if (this->m_currentShape->isInBounds())
    {
    }
    
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->m_background);
    for (const auto& block : this->m_blocks)
        target.draw(block);
    target.draw(*this->m_currentShape);
}
