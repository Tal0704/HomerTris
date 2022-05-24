#include <SFML/Graphics.hpp>
#include <memory>
#include <Board.h>

#if defined(_DEBUG)
#include <iostream>
#endif

int main()
{
	sf::RenderWindow gameWindow(sf::VideoMode(310, 520), "Taltris");
	sf::Event event;
	Board board;

	while (gameWindow.isOpen())
	{
		while (gameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				gameWindow.close();
#if defined(_DEBUG)
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
				gameWindow.close();
#endif
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			board.drop();
			sf::sleep(sf::milliseconds(100));
		}

		gameWindow.clear();
		gameWindow.draw(board);
		gameWindow.display();
	}

	return 0;
}
