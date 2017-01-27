#include "GameFinished.h"

#include <string>
#include <algorithm>

using namespace std;

vector <int> Scores;
GameFinished::MenuResult GameFinished::Show(sf::RenderWindow& window, int count)
{
	string a,b;
	std::ifstream fin;
	fin.open("SaveGame.txt");

	

	writeHighScore(count);
	while (getline(fin, a))
	{
		Scores.push_back(stoi(a));
	}

	fin.close();
	sort(Scores.begin(), Scores.end());

	for (int i = 0; i < Scores.size(); i++)
	{
		b = b + to_string(Scores[i]);

		if (Scores[i] == 1) b += "       (Chuck Norris)";
		if (Scores[i] == count) b += " <- Your score";

		b += "\n";
	}


	//Load menu image from file
	sf::Texture image;
	image.loadFromFile("GameFinished.png");
	sf::Sprite sprite;

	if (!font.loadFromFile("BuxtonSketch.ttf"))
	{

	};

	level.setFont(font);
	level.setPosition(350, 100);
	level.setString(b);
	level.setColor(sf::Color::Black);
	level.setCharacterSize(40);

	sprite.setTexture(image);

	//Setup clickable regions

	//Play menu item coordinates
	MenuItem playButton;
	playButton.rect.top = 470;
	playButton.rect.height = 55;
	playButton.rect.left = 735;
	playButton.rect.width = 155;
	playButton.action = Exit;



	_menuItems.push_back(playButton);


	window.draw(sprite);
	window.draw(level);
	window.display();

	return GetMenuResponse(window);
}

GameFinished::MenuResult GameFinished::HandleClick(int x, int y)
{
	std::list<MenuItem>::iterator it;

	for (it = _menuItems.begin(); it != _menuItems.end(); it++)
	{
		sf::Rect<int> menuItemRect = (*it).rect;
		if (menuItemRect.top + menuItemRect.height > y
			&& menuItemRect.top < y
			&& menuItemRect.left < x
			&& menuItemRect.left + menuItemRect.width > x)
		{
			return (*it).action;
		}
	}

	return Nothing;
}

GameFinished::MenuResult  GameFinished::GetMenuResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;

	while (42 != 43)
	{

		while (window.pollEvent(menuEvent))
		{
			if (menuEvent.type == sf::Event::MouseButtonPressed)
			{
				return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			}
			if (menuEvent.type == sf::Event::Closed)
			{
				return Exit;
			}
		}
	}
}

void GameFinished::writeHighScore(int a)
{
	std::string buffer;
	std::ofstream myfile;
	std::ifstream fin;
	string f = "SaveGame.txt";
	fin.open(f.c_str());
	
	while (!fin.eof())
	{
		char c;
		fin.get(c);
		buffer += c;
	}
	buffer.erase(buffer.size() - 1);
	buffer += "\n";
	fin.close();

	myfile.open("SaveGame.txt");
	myfile <<buffer + to_string(a);
	myfile.close();
}

