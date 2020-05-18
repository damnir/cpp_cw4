#include "header.h"
#include "BaseEngine.h"
#include "psydn1BombObject.h"

psydn1BombObject::psydn1BombObject(BaseEngine* pEngine)
	: DisplayableObject(550, 500, pEngine, 300, 300, true) {
	bomb = images[x];
}

psydn1BombObject::~psydn1BombObject() {}

void psydn1BombObject::virtDraw()
{
	if (!isVisible())
		return;


	bomb.renderImageWithMaskAndTransparency(m_pEngine->getForegroundSurface(),
		0,
		0,
		0,
		780,
		1300, 20, 0, 100);
	/*
	bomb = images[iCurrentTime % 2];
	bomb.renderImageWithMaskAndTransparency(m_pEngine->getForegroundSurface(),
		0,
		0,
		m_iCurrentScreenX,
		m_iCurrentScreenY,
		200, 30, 0, 100);
		*/
}

void psydn1BombObject::virtDoUpdate(int iCurrentTime)
{
	if (getEngine()->isPaused())
		return;
	getEngine()->getBackgroundSurface()->mySDLLockSurface();

	bomb = images[x];
	getEngine()->lockAndSetupBackground();
	redrawDisplay();
	getEngine()->getBackgroundSurface()->mySDLUnlockSurface();


	frames--;
	if (frames == 0)
	{
		x++;
		if (x == 5)
		{
			x = 0;
		}

		frames = 10;
		light.renderImageWithMaskAndTransparency(m_pEngine->getForegroundSurface(),
			0,
			0,
			0,
			0,
			296, 675, 0, 100);
		std::cout << "rendered";
	}

	this->redrawDisplay();
}

