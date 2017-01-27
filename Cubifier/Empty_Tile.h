#include "Tile.h"
#include "Game.h"

#ifndef EMPTY_H
#define EMPTY_H
using namespace std;

class Empty_Tile : public Tile
{
public:
	Empty_Tile();
	Empty_Tile(int a, int b);
	void  EventLauncher(Game & a);


};



#endif