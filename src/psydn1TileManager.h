#pragma once

#include "TileManager.h"

class Psydn1TileManager :
	public TileManager
{
public:
	Psydn1TileManager();
	~Psydn1TileManager();

	virtual void virtDrawTileAt(
		BaseEngine* pEngine,
		DrawingSurface* pSurface,
		int iMapX, int iMapY,
		int iStartPositionScreenX, int iStartPositionScreenY) const;

};

