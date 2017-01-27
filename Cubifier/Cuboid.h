#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

#ifndef CUBOID_H
#define CUBOID_H

class Cuboid 
{
private:
	const int side = 2;
	bool orientation;      // 0 if cuboid is oriented South-North; 1 if cuboid is facing East-West
	bool ContactFaceState;      // 0 if cuboid is lying on the square side or 1 if cuboid is lying on the rectangular face

	sf::Sprite contactFace;
	sf::Sprite Square;
	sf::Sprite Rect;
	
	sf::Texture cuboidTexture;

public:

	Cuboid();
	void update(float dt);
	void draw(sf::RenderWindow &window);
	void move( sf::Event curEvent);
	void swapFace();
	int getPosX();
	int getPosY();
	bool getContactFace();
	bool getOrientation();
	void resetPosition(int a, int b);
};

#endif