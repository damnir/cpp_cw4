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
	
	getEngine()->drawForegroundRectangle(
		m_iCurrentScreenX, m_iCurrentScreenY,
		m_iCurrentScreenX + m_iDrawWidth - 1,
		m_iCurrentScreenY + m_iDrawHeight - 1,
		0xffffff);
	setVisible(true);
		

}

void Psydn1BarObject::virtDoUpdate(int iCurrentTime)
{
	bool thing = true;
	if (getEngine()->isPaused())
		return;

	if (getEngine()->isKeyPressed(SDLK_LEFT))
		m_iCurrentScreenX -= 8;
	if (getEngine()->isKeyPressed(SDLK_RIGHT))
		m_iCurrentScreenX += 8;
	if (getEngine()->isKeyPressed(SDLK_UP) && thing)
	{
		m_iDrawWidth = m_iDrawWidth + 40;
		thing = false;
	}

	if (m_iCurrentScreenX < 0)
		m_iCurrentScreenX = 0;
	if (m_iCurrentScreenX >= getEngine()->getWindowWidth() - m_iDrawWidth)
		m_iCurrentScreenX = getEngine()->getWindowWidth() - m_iDrawWidth;

	this->redrawDisplay();
}
