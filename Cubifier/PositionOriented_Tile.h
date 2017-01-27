#include "Regular_Tile.h"

#ifndef PORIENTEDTILE_H
#define PORIENTEDTILE_H
class PositionOriented_Tile : public Regular_Tile
{
public:
	PositionOriented_Tile();
	PositionOriented_Tile(int a, int b);

	void EventLauncher(Game & a);

};
#endif
