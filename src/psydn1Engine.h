#pragma once

#include "BaseEngine.h"
#include "Psydn1TileManager.h"
#include <fstream>
#include <iostream>
#include <vector>


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

	void saveGame(std::string filename) 
	{
		std::ofstream outfile;
		outfile.open(filename+".txt");
		outfile << name << std::endl;

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
		outfile << 64 << std::endl;
		outfile << tiles << std::endl;
		outfile << deaths << std::endl;
		outfile.close();
	}
	// ***** SAVE AND LOAD SCORE AND DEATHS ETC PLS THX
	//Do save1.txt save2.txt save3.txt ....etc add 5 slots
	void loadGame(std::string filename)
	{
		std::ifstream infile;
		infile.open(filename+".txt");

		int i;
		int j;
		int value;
		std::string loadName;
		infile >> loadName;

		while (true)
		{
			infile >> i;
			if (i == 64)
				break;
			infile >> j;
			infile >> value;
			std::cout << i << ' ' << j << ' ' << value << std::endl;
			tm.setMapValue(i, j, value);
		}

		printf("Loaded successfullyfa");
		infile >> tiles;
		infile >> deaths;
		name = loadName;
		infile.close();
	}
	void loadSaveData()
	{
		names.clear();
		std::string loadName;
		for (int i = 1; i < 6; i++)
		{
			std::ifstream infile;
			infile.open("saveslot" + std::to_string(i) + ".txt");
			infile >> loadName;

			//check if save file empty
			if (infile.peek() == std::ifstream::traits_type::eof())
				loadName = "Empty Slot";
			else //filter names for '-'
				for (int j = 0; j < 10; j++)
					if (loadName[j] == 45)
						loadName[j] = ' ';

			names.push_back("[" + std::to_string(i) + "] " +loadName);
			std::cout << loadName;
			infile.close();
		}
	}
	void resetGameData() { tiles = 0; deaths = 0; };

protected:
public:
	int tiles = 0;
	int deaths = 0;
	bool start = false;

	std::vector<std::string> names;
	std::string name = ("----------");
	void clearName(){name = ("----------");}

	int nameChars = 0;
	bool validName = true;
	bool validLoad = true;
	
	Psydn1TileManager tm;

	enum State {s_init, s_main, s_paused, s_nickname, s_loadscreen, s_savescreen};
	State gState;

private:
};

