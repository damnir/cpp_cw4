#pragma once

#include "BaseEngine.h"
#include "Psydn1TileManager.h"
#include <fstream>
#include <iostream>

class Psydn1Engine :
	public BaseEngine
{
public:
	Psydn1Engine();
	~Psydn1Engine();
	void virtSetupBackgroundBuffer();
	int virtInitialiseObjects() override;
	void virtDrawStringsOnTop() override;
	void virtDrawStringsUnderneath() override;
	void virtMouseDown(int iButton, int iX, int iY) override;
	virtual void virtKeyDown(int iKeyCode) override;

	void increaseTiles() { tiles++; }
	void increaseDeaths() { deaths++; }
	void hitDetected() {
		gState = s_main;
		lockAndSetupBackground();
		redrawDisplay();
	}

	SimpleImage background = ImageManager::loadImage("background.jpg", true);
	Psydn1TileManager& GetTileManager() { return tm; }

	void saveGame() 
	{
		std::ofstream outfile;
		outfile.open("game.txt");

		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				int value = tm.getMapValue(j, i);
				outfile << j << std::endl;
				outfile << i << std::endl;
				outfile << value << std::endl;
			}
		}
		outfile << "900" << std::endl;
		outfile.close();
	}
	// ***** SAVE AND LOAD SCORE AND DEATHS ETC PLS THX
	void loadGame()
	{
		std::ifstream infile;
		infile.open("game.txt");

		int i;
		int j;
		int value;

		while (true)
		{
			infile >> i;
			if (i == 900)
				return;
			infile >> j;
			infile >> value;
			std::cout << i << ' ' << j << ' ' << value << std::endl;
			tm.setMapValue(i, j, value);
		}

		printf("Loaded successfullyfa");
	}

protected:
public:
	int tiles = 0;
	int deaths = 0;
	bool start = false;

	//user input variables
	char name[10] = ("---------");
	int nameChars = 0;
	bool validName = true;
	
	Psydn1TileManager tm;

	enum State {s_init, s_main, s_paused, s_nickname};
	State gState;

private:
};

