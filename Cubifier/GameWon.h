

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include <list>


#ifndef GAMEWON_H
#define GAMEWON_H



class GameWon
{

public:
	enum MenuResult { Nothing, Next, Exit };

	struct MenuItem
	{
	public:
		sf::Rect<int> rect;
		MenuResult action;
	};

	MenuResult Show(sf::RenderWindow& window, int );

private:
	MenuResult GetMenuResponse(sf::RenderWindow& window);
	MenuResult HandleClick(int x, int y);
	std::list<MenuItem> _menuItems;
	sf::Text level;
	sf:: Font font;
};

#endif 

