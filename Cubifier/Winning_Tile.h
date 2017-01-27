#include "Regular_Tile.h"

#ifndef WINNINGTILE_H
#define WINNINGTILE_H
class Winning_Tile : public Regular_Tile
{
public:
	Winning_Tile();
	Winning_Tile(int a, int b);

	void EventLauncher(Game & a);
	
};
#endif