#include "Regular_Tile.h"

#ifndef BCONTROLLEDTILE_H
#define BCONTROLLEDTILE_H
class BControlled_Tile : public Regular_Tile
{
public:
	BControlled_Tile();
	BControlled_Tile(int a, int b);

	void EventLauncher(Game & a);
	void changeActive();
};
#endif