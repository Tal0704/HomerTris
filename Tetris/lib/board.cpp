#include "board.h"

#if defined(_DEBUG)
#include <debugging.h>
#endif

#define POS_TO_INDEX(x) \
	(x - BLOCK_LENGTH / 2) / BLOCK_LENGTH

Board::Board()
	: m_blocks(0), m_shape(nullptr), m_topBlocks()
{
	this->m_shape = new Tetromino();
	for (size_t i = 0; i < this->m_topBlocks.size(); i++)
	{
		auto& block = this->m_topBlocks[i];
		block = sf::Vector2f(BLOCK_LENGTH / 2 + BLOCK_LENGTH * i, 525.0f);
	}
}

void Board::fall()
{
	if (this->isDown())
	{
		this->blockIsDown();
		return;
	}
	
	this->m_shape->move(0, BLOCK_LENGTH);
}

void Board::moveLeft()
{
	bool inBounds = true;
	for (size_t i = 0; i < 4; i++)
	{
		if (this->m_shape->getPosition(i).x - BLOCK_LENGTH < 0)
		{
			inBounds = false;
			break;
		}
	}

	if(inBounds)
		this->m_shape->move(-BLOCK_LENGTH, 0);
}

void Board::moveRight()
{
	bool inBounds = true;
	for (size_t i = 0; i < 4; i++)
	{
		if ((this->m_shape->getPosition(i).x + BLOCK_LENGTH) > 300)
		{
			inBounds = false;
			break;
		}
	}

	if(inBounds)
		this->m_shape->move(BLOCK_LENGTH, 0);
}

void Board::rotate(float ang)
{
	this->m_shape->rotate(ang);
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
#if defined(_DEBUG)
	if (this->m_shape)
		for (const auto& block : this->m_blocks)
			target.draw(block, states);
	else
		std::cout << "shape is null\n";
#else
		for (const auto& block : this->m_blocks)
			target.draw(block, states);
#endif
	target.draw(*this->m_shape);
}

void Board::blockIsDown()
{
	for (size_t i = 0; i < 4; i++)
		this->m_blocks.push_back(this->m_shape->getBlock(i));
	this->m_shape = new Tetromino;
	this->updateTopBlocks();
}

void Board::updateTopBlocks()
{
	for (const auto& block : this->m_blocks)
	{
		const auto& pos = block.getPosition();
		size_t index = POS_TO_INDEX(pos.x);
		if (pos.y < this->m_topBlocks[index].y)
			this->m_topBlocks[index] = pos;
	}

#if defined (_DEBUG)
	for (const auto& block : this->m_topBlocks)
		std::cout << "top Block: " << block << "\n";
#endif
}

bool Board::isDown()
{
	for (const auto topBlock : this->m_topBlocks)
	{
		for (size_t i = 0; i < 4; i++)
		{
			sf::Vector2f nextPos = this->m_shape->getPosition(i);
			nextPos.y += BLOCK_LENGTH;
			if (nextPos == topBlock)
				return true;
		}
	}
	return false;
}
