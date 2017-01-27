#include "Button_Tile.h"

#ifndef POBUTTONTILE_H
#define POBUTTONTILE_H

class POButton_Tile : public Regular_Tile
{
	int x;
	int y;

public:
	POButton_Tile();
	POButton_Tile(int a, int b, int x, int y);

	void EventLauncher(Game & a);

};
#endif