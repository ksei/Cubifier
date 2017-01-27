#include "Regular_Tile.h"

#ifndef BUTTONTILE_H
#define BUTTONTILE_H
class Button_Tile : public Regular_Tile
{
	int x;
	int y;
	
public:
	Button_Tile();
	Button_Tile(int a, int b, int x, int y);

	virtual void EventLauncher(Game & a);
	
};
#endif