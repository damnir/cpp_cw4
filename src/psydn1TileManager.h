#pragma once

#include "TileManager.h"
#include <vector>


class Psydn1TileManager :
	public TileManager
{
public:
	Psydn1TileManager();
	~Psydn1TileManager();

	SimpleImage image = ImageManager::loadImage("brick.png", true);
	SimpleImage image2 = ImageManager::loadImage("brickdead.png", true);

	std::vector<SimpleImage> bricks;



	virtual void virtDrawTileAt(
		BaseEngine* pEngine,
		DrawingSurface* pSurface,
		int iMapX, int iMapY,
		int iStartPositionScreenX, int iStartPositionScreenY) const;

	virtual void redrawTile(
		BaseEngine* pEngine,
		DrawingSurface* pSurface,
		int iMapX, int iMapY,
		int iStartPositionScreenX, int iStartPositionScreenY);

};

