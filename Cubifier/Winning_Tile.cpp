#include "Winning_Tile.h"
#include <iostream>


Winning_Tile::Winning_Tile()
{
	if (!TileTexture.loadFromFile("WinTileTexture.png"))
	{
		cout << "Error Loading file!" << endl;

	}

	TileSprite.setTexture(TileTexture);
	TileSprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
	TileSprite.setOrigin(25, 25);
	TileSprite.setPosition(25, 25);
}

Winning_Tile::Winning_Tile(int a, int b)
{
	if (!TileTexture.loadFromFile("WinTileTexture.png"))
	{
		cout << "Error Loading file!" << endl;

	}

	TileSprite.setTexture(TileTexture);
	TileSprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
	TileSprite.setOrigin(25, 25);
	TileSprite.setPosition(a, b);
}


void Winning_Tile :: EventLauncher(Game & a)
{
	
	if (!a.cuboid.getContactFace())
	{
		a.incrementIndex();
		a.setGameState(Game::Won);
	}
	
}