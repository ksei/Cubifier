

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include <list>
#include <fstream>
#include <iostream>
#include <vector>


#ifndef GAMEFINISHED_H
#define GAMEFINISHED_H



class GameFinished
{

public:
	enum MenuResult { Nothing,  Exit };

	struct MenuItem
	{
	public:
		sf::Rect<int> rect;
		MenuResult action;
	};

	MenuResult Show(sf::RenderWindow& window, int);

private:
	MenuResult GetMenuResponse(sf::RenderWindow& window);
	MenuResult HandleClick(int x, int y);
	std::list<MenuItem> _menuItems;
	void writeHighScore(int);
	sf::Text level;
	sf::Font font;
	
};

#endif 

