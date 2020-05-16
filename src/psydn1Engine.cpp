#include "header.h" 
#include "Psydn1Engine.h"
#include "DisplayableObject.h"
#include "BaseEngine.h"
#include "Psydn1BouncyObject.h"
#include "Psydn1BarObject.h"

Psydn1Engine::Psydn1Engine() : gState(Sinit) { this->pause(); }

Psydn1Engine::~Psydn1Engine() {}

void Psydn1Engine::virtSetupBackgroundBuffer()
{

	fillBackground(0);
	drawBackgroundLine(0, 790, 1300, 790, 0xff0000); //red zone line
	
	int c = 1; //tile colours
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			tm.setMapValue(i, j, c);
		}
	}
	
	SimpleImage image = ImageManager::loadImage("background.png", false);
	image.renderImage(getBackgroundSurface(), 0, 0, 0, 0, image.getWidth(), image.getHeight());

	tm.setTopLeftPositionOnScreen(0, 120);
    tm.drawAllTiles(this, getBackgroundSurface());
	//tm.virtDrawTileAt(this, getBackgroundSurface(), 1, 1, NULL, 120);
}


int Psydn1Engine::virtInitialiseObjects()
{
	drawableObjectsChanged();

	destroyOldObjects(true);
	
	createObjectArray(2);
	storeObjectInArray(0, new Psydn1BouncyObject(this));
	storeObjectInArray(1, new Psydn1BarObject(this));

	setAllObjectsVisible(true);

	return 0;
}

void Psydn1Engine::virtDrawStringsOnTop()
{
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
		drawForegroundString(500, 400, "Press 'SPACE' to start.", 0xffffff, NULL);
	if (remainingTiles == 0)
	{
		setExitWithCode(0);
		return;
	}

}

void Psydn1Engine::virtDrawStringsUnderneath()
{
	drawForegroundString(600, 750, "Break0ut", 0xff00ff, NULL);
}

void Psydn1Engine::virtMouseDown(int iButton, int iX, int iY)
{
	if (this->isPaused() && start)
		this->unpause();
	else
		this->pause();
}

void Psydn1Engine::virtKeyDown(int iKeyCode)
{
	if (iKeyCode == SDLK_SPACE)
	{
		start = true;
		this->unpause();
	}
}