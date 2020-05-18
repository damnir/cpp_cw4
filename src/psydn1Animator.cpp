#include "header.h"
#include "BaseEngine.h"
#include "psydn1Animator.h"
#include <stdio.h>
#include <stdlib.h>

psydn1Animator::psydn1Animator(BaseEngine* pEngine)
	: DisplayableObject(0, 0, pEngine, 0, 0, true) {
	currentImage = images[x], currentBrick = bricks[y]; 
}

psydn1Animator::~psydn1Animator() {}


void psydn1Animator::virtDraw()
{
	if (!isVisible())
		return;

	currentImage.renderImageWithMaskAndTransparency(m_pEngine->getForegroundSurface(),
		0,
		0,
		0,
		780,
		1300, 20, 0, 100);



	for (int i = 0; i < 1300; i += 150)
	{
		currentBrick.renderImageWithMaskAndTransparency(m_pEngine->getForegroundSurface(),
			0,
			0,
			i,
			550,
			100, 33, 0, 60);
	}

}

void psydn1Animator::virtDoUpdate(int iCurrentTime)
{
	if (getEngine()->isPaused())
		return;


	frames--;
	if (frames == 0)
	{
		getEngine()->getBackgroundSurface()->mySDLLockSurface();
		currentImage = images[x];
		currentBrick = bricks[y];
		getEngine()->getBackgroundSurface()->mySDLUnlockSurface();

		x++;
		y++;

		if (x == 5)
		{
			x = 0;
		}
		if (y == 3)
		{
			y = 0;
		}

		frames = 10;

	}

	this->redrawDisplay();
}


