#include "Tile.h"
#include "Game.h"
#include <SFML/Audio.hpp>

#ifndef REGTILE_H
#define REGTILE_H
using namespace std;

class Regular_Tile : public Tile
{
public:
	Regular_Tile();
	Regular_Tile(int a, int b);
	virtual void  EventLauncher(Game & a);
	

	

};



#endif