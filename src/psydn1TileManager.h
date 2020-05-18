#pragma once

#include "TileManager.h"
#include "psydn1Animator.h"
#include <vector>


class Psydn1TileManager :
	public TileManager
{
public:
	Psydn1TileManager();
	~Psydn1TileManager();

	

	SimpleImage image = ImageManager::loadImage("brick.png", false);
	SimpleImage image2 = ImageManager::loadImage("brick2.png", false);

	std::vector<SimpleImage> bricks;

	virtual void virtDrawTileAt(
		BaseEngine* pEngine,
		DrawingSurface* pSurface,
		int iMapX, int iMapY,
		int iStartPositionScreenX, int iStartPositionScreenY, int state) const;

	virtual void redrawTile(
		BaseEngine* pEngine,
		DrawingSurface* pSurface,
		int iMapX, int iMapY,
		int iStartPositionScreenX, int iStartPositionScreenY);

};

