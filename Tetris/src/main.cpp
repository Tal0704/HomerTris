#include <SFML/Graphics.hpp>
#include <memory>
#include <Tetromino.h>

#if defined(_DEBUG)
#include <iostream>
#endif

int main()
{
	sf::RenderWindow gameWindow(sf::VideoMode(300, 510), "Taltris");
	sf::Event event;

	sf::Texture texture;
	if (!texture.loadFromFile("media/tetros/blue.png"))
		return -1;

	sf::Sprite sprite(texture);

	Tetromino tetro(Tetromino::Shape::T);

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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			tetro.move(0, -1);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			tetro.move(0, 1);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			tetro.move(1, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			tetro.move(-1, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			tetro.rotate(90.0f);
			sf::sleep(sf::milliseconds(100));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			tetro.rotate(-90.0f);
			sf::sleep(sf::milliseconds(100));
		}

		gameWindow.clear();
		gameWindow.draw(tetro);
		gameWindow.display();
	}

	return 0;
}
