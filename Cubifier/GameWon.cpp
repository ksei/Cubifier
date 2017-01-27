
#include "GameWon.h"
#include <string>


GameWon::MenuResult GameWon::Show(sf::RenderWindow& window, int index)
{

	//Load menu image from file
	sf::Texture image;
	image.loadFromFile("GameWon.png");
	sf::Sprite sprite;

	if (!font.loadFromFile("BuxtonSketch.ttf"))
	{
		
	};

	level.setFont(font);
	level.setPosition(380, 387);
	level.setString(std::to_string(index + 1));
	level.setColor(sf::Color::Black);
	level.setCharacterSize(50);

	sprite.setTexture(image);

	//Setup clickable regions

	//Play menu item coordinates
	MenuItem playButton;
	playButton.rect.top = 480;
	playButton.rect.height = 60;
	playButton.rect.left = 730;
	playButton.rect.width = 55;
	playButton.action = Next;

	

	_menuItems.push_back(playButton);
	

	window.draw(sprite);
	window.draw(level);
	window.display();

	return GetMenuResponse(window);
}

GameWon::MenuResult GameWon::HandleClick(int x, int y)
{
	std::list<MenuItem>::iterator it;

	for (it = _menuItems.begin(); it != _menuItems.end(); it++)
	{
		sf::Rect<int> menuItemRect = (*it).rect;
		if (menuItemRect.top + menuItemRect.height > y
			&& menuItemRect.top < y
			&& menuItemRect.left < x
			&& menuItemRect.left + menuItemRect.width > x)
		{
			return (*it).action;
		}
	}

	return Nothing;
}

GameWon::MenuResult  GameWon::GetMenuResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;

	while (42 != 43)
	{

		while (window.pollEvent(menuEvent))
		{
			if (menuEvent.type == sf::Event::MouseButtonPressed)
			{
				return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			}
			if (menuEvent.type == sf::Event::Closed)
			{
				return Exit;
			}
		}
	}
}