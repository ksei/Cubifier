
#include "Game.h"

#include <iostream>
#include <vector>



void Game::setGameState(GameState gs)
{
	gameState = gs;
}

void Game::Start(void)
{
	if (gameState != Uninitialized)
		return;

	gameWindow.setFramerateLimit(60);
	gameWindow.create(sf::VideoMode(1000, 600, 32), "Cubifier!");
	gameState = Game::ShowingWelcome;
	
	
	if (!font1.loadFromFile("BuxtonSketch.ttf"))
	{
		cout << "error loading font";
	};
	
	moves.setFont(font1);
	moves.setPosition(800, 7);
	level.setFont(font1);
	level.setPosition(50, 7);

    index = 0;
	vec = createTileVec(level1Config[index]);
	
	

	while (!this->IsExiting())
	{
		if (index == 10) gameState = Game::Finished;
		GameLoop();
		
	
	}

	gameWindow.close();
}

void Game::GameLoop()
{
	sf::Event currentEvent;


	bool keyState = 0;
	
	string move = "Your moves: " + to_string(count) ; 
	
	moves.setString(move);

	level.setString("Level: " + to_string(index + 1));


	while (gameWindow.pollEvent(currentEvent))
	{
		
		
		switch (gameState)
		{
		case Game::Finished:
		{
			ShowFinished();
			break;
		}
		case Game::ShowingMenu:
		{
			ShowMenu();
			break;
		}
		case Game::ShowingWelcome: 
		{
			ShowWelcome();
			break;
		}
		case Game::Lost:
		{
			ShowGameLost();

			break;
		}
		case Game::Won:
		{
			ShowGameWon();

			break;
		}
		case Game::Playing:
		{
			if (currentEvent.type == sf::Event::KeyPressed)
			{
				cuboid.move(currentEvent);
				keyState = 1;
			}

			if (currentEvent.type == sf::Event::KeyReleased)
				keyState = 0;
			
			
			
			if (memory != (cuboid.getPosY()) *(cuboid.getPosX() ) )
			{
				count++;
				vec[(cuboid.getPosY() - 25) / 50][(cuboid.getPosX() - 25) / 50]->EventLauncher(*this);
				cout << "initial" << endl;
				
				if (cuboid.getContactFace())
				{
					if (cuboid.getOrientation())
					{
						vec[(cuboid.getPosY() - 25) / 50][((cuboid.getPosX() - 25) / 50) + 1]->EventLauncher(*this);
						cout << "Horizontal" << endl;
					}

					else
					{
						vec[((cuboid.getPosY()  - 25) / 50) + 1][(cuboid.getPosX() - 25) / 50]->EventLauncher(*this);
						cout << "Vertical" << endl;
					}
				}
				memory = ((cuboid.getPosY()) *(cuboid.getPosX()));
				
			}
			gameWindow.clear();
			for (int i = 0; i < 12; i++)
			{
				for (int j = 0; j < 20; j++)
					vec[i][j]->draw(gameWindow);
			}
			cuboid.draw(gameWindow);
			gameWindow.draw(level);
			gameWindow.draw(moves);
			gameWindow.display();

			if (currentEvent.type == sf::Event::Closed)
			{
				gameState = Game::Exiting;
			}
			break;
		}
		

		}
	}
}



bool Game::IsExiting()
{
	if (gameState == Game::Exiting)
		return true;
	else
		return false;
}

vector<vector<Tile*>> Game :: createTileVec(string a)
{
	vector<vector<Tile*>> vec;

	for (int i = 0; i < 12; i++)
	{
		vector<Tile*> temp; // create an array, don't work directly on buff yet.
		for (int j = 0; j < 20; j++)
		{
			if (a.at(i * 20 + j) == '1')
			{
				temp.push_back(new Regular_Tile(j * 50 + 25, i * 50 + 25));
			}

			else if (a.at(i * 20 + j) == '0')
			{
				temp.push_back(new Empty_Tile(j * 50 + 25, i * 50 + 25));
			}
			else if (a.at(i * 20 + j) == '2')
			{
				temp.push_back(new Winning_Tile(j * 50 + 25, i * 50 + 25));
			}
			else if (a.at(i * 20 + j) == '3')
			{
				temp.push_back(new PositionOriented_Tile(j * 50 + 25, i * 50 + 25));
			}
			else if (a.at(i * 20 + j) == '4')
			{
				temp.push_back(new Button_Tile(j * 50 + 25, i * 50 + 25, stoi(a.substr(i * 20 + j + 2 , 2)), stoi(a.substr(i * 20 + j + 4, 2))));
				a.erase(a.begin() + i * 20 + j + 1, a.begin() + i * 20 + j + 7);
			}
			else if (a.at(i * 20 + j) == '5')
			{
				temp.push_back(new BControlled_Tile(j * 50 + 25, i * 50 + 25));
			}
			else if (a.at(i * 20 + j) == '6')
			{
				temp.push_back(new POButton_Tile(j * 50 + 25, i * 50 + 25, stoi(a.substr(i * 20 + j + 2, 2)), stoi(a.substr(i * 20 + j + 4, 2))));
				a.erase(a.begin() + i * 20 + j + 1, a.begin() + i * 20 + j + 7);
			}
		}

		vec.push_back(temp); // Store the array in the buffer
	}

	return vec;
}

Game::GameState Game::gameState = Uninitialized;
sf::RenderWindow Game::gameWindow;

void Game::ShowWelcome()
{
	Welcome welcome;
	welcome.Show(gameWindow);
	gameState = Game::ShowingMenu;
}

void Game::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(gameWindow);
	switch (result)
	{
	case MainMenu::Exit:
		gameState = Game::Exiting;
		break;
	case MainMenu::Play:
	{
		
		gameState = Game::Playing;
		break;
	}
	}
}

void Game::ShowGameLost()
{
	vec = createTileVec(level1Config[index]);
	GameLost gameLost;
	GameLost::MenuResult result = gameLost.Show(gameWindow);

	switch (result)
	{
	case GameLost::Exit:
		gameState = Game::Exiting;
		break;
	case GameLost::Replay:
	{
		
		cuboid.resetPosition(stoi(level1Config[index].substr(level1Config[index].length() - 4, 2)), stoi(level1Config[index].substr(level1Config[index].length() - 2, 2)));
		gameState = Game::Playing;
		break;
	}
	}

}

void Game::ShowGameWon()
{
	vec = createTileVec(level1Config[index]);
	cuboid.resetPosition(stoi(level1Config[index].substr(level1Config[index].length() - 4, 2)), stoi(level1Config[index].substr(level1Config[index].length() - 2, 2)));
	GameWon gameWon;
	GameWon::MenuResult result = gameWon.Show(gameWindow, index);
	switch (result)
		{
		case GameWon::Exit:
			gameState = Game::Exiting;
			break;

		case GameWon::Next:
		{

			gameState = Game::Playing;
			break;
		}
		}
	} 

	
vector<vector<Tile*>> Game::getTileMap()
{
	return vec;
}

void Game::incrementIndex()
{
	index++;
}

void Game::ShowFinished()
{
	GameFinished gameF;
	GameFinished::MenuResult result = gameF.Show(gameWindow, count);
	switch (result)
	{
	case GameFinished::Exit:
		gameState = Game::Exiting;
		break;

	}

}
