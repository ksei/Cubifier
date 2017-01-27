#include "Empty_Tile.h"
#include <iostream>

using namespace std;

Empty_Tile::Empty_Tile()
{
	if (!TileTexture.loadFromFile("EmptyTile.png"))
	{
		cout << "Error Loading file!" << endl;

	}

	TileSprite.setTexture(TileTexture);
	TileSprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
	TileSprite.setOrigin(25, 25);
	TileSprite.setPosition(75, 75);

}

Empty_Tile::Empty_Tile(int x, int y)
{
	if (!TileTexture.loadFromFile("EmptyTile.png"))
	{
		cout << "Error Loading file!" << endl;

	}

	TileSprite.setTexture(TileTexture);
	TileSprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
	TileSprite.setOrigin(25, 25);
	TileSprite.setPosition(x, y);

}

void Empty_Tile::EventLauncher(Game & a)
{
	a.setGameState(Game::Lost);
}