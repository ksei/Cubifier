#include "Button_Tile.h"
#include <iostream>


Button_Tile::Button_Tile()
{
	if (!TileTexture.loadFromFile("BTile.png"))
	{
		cout << "Error Loading file!" << endl;
		
	}

	TileSprite.setTexture(TileTexture);
	TileSprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
	TileSprite.setOrigin(25, 25);
	TileSprite.setPosition(25, 25);
	active = 0;
}

Button_Tile::Button_Tile(int a, int b, int c, int d)
{
	if (!TileTexture.loadFromFile("BTile.png"))
	{
		cout << "Error Loading file!" << endl;

	}

	TileSprite.setTexture(TileTexture);
	TileSprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
	TileSprite.setOrigin(25, 25);
	TileSprite.setPosition(a, b);

	x = c;
	y = d;

	
}


void Button_Tile::EventLauncher(Game & a)
{
	a.getTileMap()[x][y]->changeActive();
}

