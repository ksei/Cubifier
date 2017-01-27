#include "PositionOriented_Tile.h"
#include <iostream>


PositionOriented_Tile::PositionOriented_Tile()
{
	if (!TileTexture.loadFromFile("POrientedTile.png"))
	{
		cout << "Error Loading file!" << endl;

	}

	TileSprite.setTexture(TileTexture);
	TileSprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
	TileSprite.setOrigin(25, 25);
	TileSprite.setPosition(25, 25);
}

PositionOriented_Tile::PositionOriented_Tile(int a, int b)
{
	if (!TileTexture.loadFromFile("POrientedTile.png"))
	{
		cout << "Error Loading file!" << endl;

	}

	TileSprite.setTexture(TileTexture);
	TileSprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
	TileSprite.setOrigin(25, 25);
	TileSprite.setPosition(a, b);
}


void PositionOriented_Tile::EventLauncher(Game & a)
{

	if (!a.cuboid.getContactFace())
		a.setGameState(Game::Lost);
}