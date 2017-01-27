#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Cuboid.h"
#include <iostream>


using namespace std;

Cuboid::Cuboid()
{
	sf::Texture H;
	orientation = 1;
	ContactFaceState = 0;

	if (!cuboidTexture.loadFromFile("Box-Wood-Texture.png"))
	{
		cout << "Error Loading file!" << endl;

	}



	Rect.setTexture(cuboidTexture);
	Rect.setTextureRect(sf::IntRect(0,0, 100, 50));
	Rect.setOrigin(25, 25);
	Rect.setPosition(275, 125);
	
	

	Square.setTexture(cuboidTexture);
	Square.setTextureRect(sf::IntRect(0,0,50, 50));
	Square.setOrigin(25,25);
	Square.setPosition(325,225);
	
	contactFace = Square;
	

	

}

void Cuboid :: draw(sf::RenderWindow &window)
{
	window.draw(contactFace);
	
}

void Cuboid :: update(float dt)
{
    
}

void Cuboid::move( sf::Event curEvent)
{
	if (!ContactFaceState)
	{
		if (curEvent.type == sf::Event::KeyPressed && curEvent.key.code == sf::Keyboard::Right)
		{
			swapFace();
			contactFace.move(50, 0);
			cout << contactFace.getPosition().x << "," << contactFace.getPosition().y << endl;
			orientation = 1;
		}
		else if (curEvent.type == sf::Event::KeyPressed && curEvent.key.code == sf::Keyboard::Left)
		{
			swapFace();
			contactFace.move(-100, 0);
			orientation = 1;
			
		}
		else if (curEvent.type == sf::Event::KeyPressed && curEvent.key.code == sf::Keyboard::Up)
		{
			swapFace();
			contactFace.rotate(90);
			contactFace.move(0, -100);
			orientation = 0;
			
		}
		else if (curEvent.type == sf::Event::KeyPressed && curEvent.key.code == sf::Keyboard::Down)
		{
			swapFace();
			contactFace.rotate(90);
			contactFace.move(0, 50);
			cout << contactFace.getPosition().x << "," << contactFace.getPosition().y << endl;

			orientation = 0;
			
		}

	}
	else
	{
		if (orientation)
		{
			if (curEvent.type == sf::Event::KeyPressed && curEvent.key.code == sf::Keyboard::Right)
			{
				
				swapFace();
				contactFace.move(100, 0);
				
				
			}
			else if (curEvent.type == sf::Event::KeyPressed && curEvent.key.code == sf::Keyboard::Left)
			{
				swapFace();
				contactFace.move(-50, 0);
			}
			else if (curEvent.type == sf::Event::KeyPressed && curEvent.key.code == sf::Keyboard::Up)
			{
				contactFace.move(0, -50);
				
			}
			else if (curEvent.type == sf::Event::KeyPressed && curEvent.key.code == sf::Keyboard::Down)
			{
				contactFace.move(0, 50);

			}

		}
		else if (!orientation)
		{
			if (curEvent.type == sf::Event::KeyPressed && curEvent.key.code == sf::Keyboard::Right)
			{
				contactFace.move(50, 0);
				
			}
			else if (curEvent.type == sf::Event::KeyPressed && curEvent.key.code == sf::Keyboard::Left)
			{
				contactFace.move(-50, 0);
			}
			else if (curEvent.type == sf::Event::KeyPressed && curEvent.key.code == sf::Keyboard::Up)
			{
				swapFace();
				contactFace.move(0, -50);
			}
			else if (curEvent.type == sf::Event::KeyPressed && curEvent.key.code == sf::Keyboard::Down)
			{
				swapFace();
				contactFace.move(0, 100);
				
			}
		}
	}

}

void Cuboid::swapFace()
{
	if (ContactFaceState)
	{
		Square.setPosition(contactFace.getPosition().x, contactFace.getPosition().y);
		contactFace = Square;
		ContactFaceState = 0;
	}
	else if (!ContactFaceState)
	{
		Rect.setPosition(contactFace.getPosition().x, contactFace.getPosition().y);
		contactFace = Rect;
		ContactFaceState = 1;
	}
}

int Cuboid::getPosX()
{
	return contactFace.getPosition().x;
}
int Cuboid::getPosY()
{
	return contactFace.getPosition().y;
}

bool Cuboid::getContactFace()
{
	return ContactFaceState;
}

bool Cuboid::getOrientation()
{
	return orientation;
}

void Cuboid::resetPosition(int a, int b)
{
	orientation = 1;
	ContactFaceState = 0;
	Square.setPosition(a*50 + 25, b*50 + 25);
	contactFace = Square;
}
