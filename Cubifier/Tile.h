#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Game.h"


using namespace std;

#ifndef TILE_H
#define TILE_H

class Game;

class Tile
{
protected:
	const int side = 2;
	bool active;
	sf::Texture TileTexture;
	
	

public:
	sf::Sprite TileSprite;
	virtual void EventLauncher(Game & a) = 0;
	void draw(sf::RenderWindow &window)
	{
		{
			window.draw(TileSprite);

		}
	};
	bool getAct()
	{
		return active;
	}
	virtual void changeActive()
	{
		active = !active;
	}
};






#endif