#include "header.h"
#include "BaseEngine.h"
#include "Psydn1BarObject.h"


Psydn1BarObject::Psydn1BarObject(BaseEngine* pEngine)
	: DisplayableObject(550, 750, pEngine, 200, 30, true) {}

Psydn1BarObject::~Psydn1BarObject() {}

void Psydn1BarObject::virtDraw()
{
	if (!isVisible())
		return;

	image.renderImageWithMaskAndTransparency(m_pEngine->getForegroundSurface(),
		0,
		0,
		m_iCurrentScreenX,
		m_iCurrentScreenY,
		m_iDrawWidth, m_iDrawHeight, 0, 100);
}

void Psydn1BarObject::virtDoUpdate(int iCurrentTime)
{
	bool thing = true;
	if (getEngine()->isPaused())
		return;



	frames--;
	if (frames == 0)
	{
		
		getEngine()->getBackgroundSurface()->mySDLLockSurface();
		image = images[x];
		getEngine()->getBackgroundSurface()->mySDLUnlockSurface();
		

		x--;
		if (x == 0)
		{
			x = 9;
		}

		frames = 5;

	}

	if (getEngine()->isKeyPressed(SDLK_LEFT))
		m_iCurrentScreenX -= 6;
	if (getEngine()->isKeyPressed(SDLK_RIGHT))
		m_iCurrentScreenX += 6;

	if (m_iCurrentScreenX < 0)
		m_iCurrentScreenX = 0;
	if (m_iCurrentScreenX >= getEngine()->getWindowWidth() - m_iDrawWidth)
		m_iCurrentScreenX = getEngine()->getWindowWidth() - m_iDrawWidth;

	this->redrawDisplay();
}
