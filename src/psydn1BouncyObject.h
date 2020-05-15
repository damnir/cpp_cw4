#pragma once

#include "BaseEngine.h"
#include "TileManager.h"
#include "DisplayableObject.h"
#include "CollisionDetection.h"
#include "Psydn1Engine.h"

using namespace std;

class Psydn1BouncyObject : public DisplayableObject
{
private:
	double m_dSX;
	double m_dSY;
	double m_dX;
	double m_dY;

	Psydn1Engine* m_pMainEngine;
	Psydn1TileManager& tm = m_pMainEngine->GetTileManager();

public:
	// Constructor
	Psydn1BouncyObject(Psydn1Engine* pEngine)
		: DisplayableObject(pEngine, 30, 30, false)
		, m_pMainEngine(pEngine)

	{
		// Spawn coordinates
		m_dX = m_iCurrentScreenX = 650;
		m_dY = m_iCurrentScreenY = 735;
		// Speed
		m_dSX = 3;
		m_dSY = 5;
		
		setVisible(true);
	}

	void virtDraw() override
	{
		
		getEngine()->drawForegroundOval(
			m_iCurrentScreenX - m_iDrawWidth / 2 + 1,
			m_iCurrentScreenY - m_iDrawHeight / 2 + 1,
			m_iCurrentScreenX + m_iDrawWidth / 2 - 1,
			m_iCurrentScreenY + m_iDrawHeight / 2 - 1,
			0xffffff);


	}

	void virtDoUpdate(int iCurrentTime) override
	{
		if (getEngine()->isPaused())
			return;

		// Alter position for speed
		m_dX += m_dSX;
		m_dY += m_dSY;

		DisplayableObject* pObject;
		DisplayableObject* pObject2;

		pObject = getEngine()->getDisplayableObject(0);
		pObject2 = getEngine()->getDisplayableObject(1);

		int xx = 0;
		int yy = 120;

		bool deadTile = false;

		if (tm.isValidTilePosition(pObject->getXCentre(), pObject->getYCentre()-40))
		{
			int mapX = tm.getMapXForScreenX(pObject->getXCentre()); // X pos
			int mapY = tm.getMapYForScreenY(pObject->getYCentre()-40); // Y pos
			int value = tm.getMapValue(mapX, mapY);

			if (value == 0)
				deadTile = true;
			//printf("\n%d\n", value);
			switch (deadTile)
			{
			case true:
				break;
			case false:
				tm.setAndRedrawMapValueAt(mapX, mapY, 0, m_pMainEngine, m_pMainEngine->getBackgroundSurface());
				tm.redrawTile(m_pMainEngine, m_pMainEngine->getBackgroundSurface(), mapX, mapY, xx+tm.getTileWidth()*mapX, yy+tm.getTileHeight()*mapY);
				m_pMainEngine->increaseTiles();
				m_dY = -m_iStartDrawPosY + pObject->getYCentre() + 20;
				m_dSY = -m_dSY;
			}
		}

		// Edge detection
		if ((m_dX + m_iStartDrawPosX) < 0)
		{
			m_dX = -m_iStartDrawPosX;
			if (m_dSX < 0)
				m_dSX = -m_dSX;
		}
		if ((m_dX + m_iStartDrawPosX + m_iDrawWidth) > (getEngine()->getWindowWidth() - 1))
		{
			m_dX = getEngine()->getWindowWidth() - 1 - m_iStartDrawPosX - m_iDrawWidth;
			if (m_dSX > 0)
				m_dSX = -m_dSX;
		}
		if ((m_dY + m_iStartDrawPosY) < 0)
		{
			m_dY = -m_iStartDrawPosY;
			if (m_dSY < 0)
				m_dSY = -m_dSY;
		}
		if ((m_dY + m_iStartDrawPosY + m_iDrawHeight) > (getEngine()->getWindowHeight() - 1))
		{
			m_dY = 735;
			if (m_dSY > 0)
				m_dSY = -m_dSY;
			m_dX = pObject2->getXCentre();
			m_pMainEngine->increaseDeaths();
		}
		if (CollisionDetection::checkRectangles(
			pObject->getXCentre() - 100, pObject->getXCentre() + 100,
			pObject->getYCentre() - 15, pObject->getYCentre() + 15,
			pObject2->getXCentre() - 15, pObject2->getXCentre() + 15,
			pObject2->getYCentre() - 15, pObject2->getYCentre() + 15))
		{
			m_dY = getEngine()->getWindowHeight() - 1 - m_iStartDrawPosY - m_iDrawHeight - 50;
			if (m_dSY > 0)
				m_dSY = -m_dSY;
		}

		// set current position
		m_iCurrentScreenX = (int)(m_dX + 0.5);
		m_iCurrentScreenY = (int)(m_dY + 0.5);

		redrawDisplay();
	}
};
