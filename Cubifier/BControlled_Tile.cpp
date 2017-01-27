#include "BControlled_Tile.h"
#include <iostream>


BControlled_Tile::BControlled_Tile()
{
	if (!TileTexture.loadFromFile("EmptyTile.png"))
	{
		cout << "Error Loading file!" << endl;

	}

	TileSprite.setTexture(TileTexture);
	TileSprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
	TileSprite.setOrigin(25, 25);
	TileSprite.setPosition(25, 25);
	active = 0;
}

BControlled_Tile::BControlled_Tile(int a, int b)
{
	if (!TileTexture.loadFromFile("EmptyTile.png"))
	{
		cout << "Error Loading file!" << endl;

	}

	TileSprite.setTexture(TileTexture);
	TileSprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
	TileSprite.setOrigin(25, 25);
	TileSprite.setPosition(a, b);
	active = 0;
}


void BControlled_Tile::EventLauncher(Game & a)
{

	if (!active)
		a.setGameState(Game::Lost);
}

void BControlled_Tile::changeActive()
{
	

	if (!active)
	{
		active = 1;
		if (!TileTexture.loadFromFile("TileTexture.png"))
		{
			cout << "Error Loading file!" << endl;

		}

		TileSprite.setTexture(TileTexture);
	}
	else if (active)
	{
		active = 0;
		if(!TileTexture.loadFromFile("EmptyTile.png"))
		{
			cout << "Error Loading file!" << endl;

		}

		TileSprite.setTexture(TileTexture);
	}
	
}