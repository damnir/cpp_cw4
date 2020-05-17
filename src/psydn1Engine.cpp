#include "header.h" 
#include "Psydn1Engine.h"
#include "DisplayableObject.h"
#include "BaseEngine.h"
#include "Psydn1BouncyObject.h"
#include "Psydn1BarObject.h"
#include <iostream>

Psydn1Engine::Psydn1Engine() : gState(s_init) { this->pause(); }

Psydn1Engine::~Psydn1Engine() {}

void Psydn1Engine::virtSetupBackgroundBuffer()
{

	switch (gState)
	{
	case s_init:
	{
		//set all tiles to value 1
		int c = 1; 
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				tm.setMapValue(i, j, c);
			}
		}

		fillBackground(12); //background
		tm.setTopLeftPositionOnScreen(0, 120); //initial tiles position
		break;
	}
	

	case s_main:
	{
		//Show the objects
		setAllObjectsVisible(true);
		fillBackground(12);
		drawBackgroundLine(0, 790, 1300, 790, 0xff0000); //red zone line
		//top left position on screen
		int xx = 0;
		int yy = 120;

		//draw tiles that are not dead (value not 0)
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				int value = tm.getMapValue(j, i);
				if (value != 0)
				{
					tm.virtDrawTileAt(this, getBackgroundSurface(), j, i, xx + tm.getTileWidth()*j, yy + tm.getTileHeight()*i);
				}
			}
		}
		break;
	}

	case s_paused:
		/*fillBackground(0);
		std::cout << gState;
		*/
		break;
	}
}


int Psydn1Engine::virtInitialiseObjects()
{
	drawableObjectsChanged();

	destroyOldObjects(true);

	createObjectArray(2);
	storeObjectInArray(0, new Psydn1BouncyObject(this));
	storeObjectInArray(1, new Psydn1BarObject(this));
	setAllObjectsVisible(false);

	return 0;


}

void Psydn1Engine::virtDrawStringsOnTop()
{
	switch (gState)
	{
	case s_init:
		char newGame[128];
		char loadGame[128];
		char quitGame[128];

		sprintf(newGame, "[N] New Game");
		sprintf(loadGame, "[L] Load Game");
		sprintf(quitGame, "[Q] Quit Game");

		drawForegroundString(550, 350, newGame, 0xffffff, NULL);
		drawForegroundString(550, 390, loadGame, 0xffffff, NULL);
		drawForegroundString(550, 430, quitGame, 0xffffff, NULL);
		break;

	case s_nickname:
		char enterName[128];
		char nameField[128];
		char fieldValid[128];



		sprintf(enterName, "Enter Nickname");
		sprintf(fieldValid, "Please enter at least 3 characters.");
		sprintf(nameField, name);

		drawForegroundString(550, 350, enterName, 0xffffff, NULL);
		drawForegroundString(590, 390, nameField, 0xffffff, NULL);

		if (!validName)
		{
			drawForegroundString(420, 430, fieldValid, 0xff5555, NULL);
		}

		//getBackgroundSurface()->drawShortenedArrow(100, 100, 120, 120, 0, 0, 0, 2, 2);


		break;

	case s_main:
		int remainingTiles = (15 * 6 + 1) - tiles;
		// Build the string to print
		char buf1[128];
		char buf2[128];
		char buf3[128];

		sprintf(buf1, "Tiles: %d", tiles);
		sprintf(buf2, "Remaining Tiles: %d", remainingTiles);
		sprintf(buf3, "Deaths: %d", deaths);

		drawForegroundString(300, 40, buf1, 0xffffff, NULL);
		drawForegroundString(500, 40, buf2, 0xffffff, NULL);
		drawForegroundString(850, 40, buf3, 0xffffff, NULL);
		if (this->isPaused() && start)
			drawForegroundString(600, 400, "---PAUSED---", 0xff00ff, NULL);

		if (!start)
			drawForegroundString(500, 500, "Press 'SPACE' to start.", 0xffffff, NULL);
		if (remainingTiles == 0)
		{
			setExitWithCode(0);
			return;
		}
		break;

	}



}

void Psydn1Engine::virtDrawStringsUnderneath()
{
	switch (gState)
	{
	case s_main:
		drawForegroundString(600, 750, "Break0ut", 0xffffff, NULL);
	}
}

void Psydn1Engine::virtMouseDown(int iButton, int iX, int iY)
{
	
	
	if (this->isPaused() && start)
		this->unpause();
	else
		this->pause();
		
		
	/*
	gState = s_main;
	lockAndSetupBackground();
	redrawDisplay();
	//string s = to_string(gState);
	*/


}

void Psydn1Engine::virtKeyDown(int iKeyCode)
{
	switch (gState)
	{
	case (s_main):
		if (iKeyCode == SDLK_SPACE)
		{
			start = true;
			this->unpause();
		}
		break;
	case (s_init):
		if (iKeyCode == SDLK_n)
		{
			gState = s_nickname;
			lockAndSetupBackground();
			redrawDisplay();
		}
		break;
	case (s_nickname):
		
		validName = true;

		if (iKeyCode == SDLK_RETURN)
		{
			if (nameChars < 3)
				validName = false;
			else
				gState = s_main;

			lockAndSetupBackground();
			redrawDisplay();
			break;
		}
		if (nameChars < 10 && nameChars >= 0)
		{
			if (iKeyCode >= 97 && iKeyCode <= 122)
			{
				name[nameChars] = iKeyCode;
				nameChars++;
			}
		}
		if (nameChars > 0)
		{
			if (iKeyCode == SDLK_BACKSPACE || iKeyCode == SDLK_DELETE)
			{
				nameChars--;
				name[nameChars] = '-';
			}
		}
		gState = s_nickname;
		lockAndSetupBackground();
		redrawDisplay();
	}
}