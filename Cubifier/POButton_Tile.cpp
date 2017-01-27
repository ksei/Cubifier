#include "POButton_Tile.h"
#include <iostream>


POButton_Tile::POButton_Tile()
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

POButton_Tile::POButton_Tile(int a, int b, int c, int d)
{
	if (!TileTexture.loadFromFile("POBTile.png"))
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


void POButton_Tile::EventLauncher(Game & a)
{
	if (!a.cuboid.getContactFace())
	a.getTileMap()[x][y]->changeActive();
}

