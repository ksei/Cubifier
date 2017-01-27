#include "Regular_Tile.h"
#include <iostream>


using namespace std;

Regular_Tile::Regular_Tile()
{
	if (!TileTexture.loadFromFile("TileTexture.png"))
	{
		cout << "Error Loading file!" << endl;

	}

	TileSprite.setTexture(TileTexture);
	TileSprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
	TileSprite.setOrigin(25, 25);
	TileSprite.setPosition(25, 25);
	
}

Regular_Tile::Regular_Tile(int x, int y)
{
	if (!TileTexture.loadFromFile("TileTexture.png"))
	{
		cout << "Error Loading file!" << endl;

	}

	TileSprite.setTexture(TileTexture);
	TileSprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
	TileSprite.setOrigin(25, 25);
	TileSprite.setPosition(x, y);
}

void Regular_Tile :: EventLauncher(Game & a)
{

}

