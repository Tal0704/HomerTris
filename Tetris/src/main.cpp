#include <SFML/Graphics.hpp>
#include <memory>
#include <Board.h>

#if defined(_DEBUG)
#include <iostream>
#endif

int main()
{
	Board gameWindow(sf::VideoMode(300, 510), "Taltris");
	sf::Event event;

	sf::Texture texture;
	if (!texture.loadFromFile("media/tetros/blue.png"))
		return -1;
	sf::RectangleShape shape(sf::Vector2f(50.0f, 50.0f));

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

		gameWindow.clear(sf::Color::Green);
		gameWindow.draw(shape);
		gameWindow.display();
	}

	return 0;
}
