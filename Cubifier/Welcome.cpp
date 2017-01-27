#include "Welcome.h"


void Welcome::Show(sf::RenderWindow & renderWindow)
{
	sf::Texture image;
	if (image.loadFromFile("Welcome.png") != true)
	{
		return;
	}

	sprite.setTexture(image);
	sprite.setTextureRect(sf::IntRect(0, 0, 1200, 600));
	

	renderWindow.draw(sprite);
	renderWindow.display();

	sf::Event event;
	while (true)
	{
		while (renderWindow.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::KeyPressed
				|| event.type == sf::Event::EventType::MouseButtonPressed
				|| event.type == sf::Event::EventType::Closed)
			{
				return;
			}
		}
	}
}


