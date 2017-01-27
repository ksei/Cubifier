

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include <list>

#ifndef GAMELOST_H
#define GAMELOST_H



class GameLost
{

public:
	enum MenuResult { Nothing, Exit, Replay };

	struct MenuItem
	{
	public:
		sf::Rect<int> rect;
		MenuResult action;
	};

	MenuResult Show(sf::RenderWindow& window);

private:
	MenuResult GetMenuResponse(sf::RenderWindow& window);
	MenuResult HandleClick(int x, int y);
	std::list<MenuItem> _menuItems;
};

#endif 

