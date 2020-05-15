#include "header.h"
#include "Psydn1TileManager.h"

Psydn1TileManager::Psydn1TileManager()
	: TileManager(40, 100, 15, 7) {}

Psydn1TileManager::~Psydn1TileManager(){}


void Psydn1TileManager::virtDrawTileAt(
	BaseEngine* pEngine,
	DrawingSurface* pSurface,
	int iMapX, int iMapY,
	int iStartPositionScreenX, int iStartPositionScreenY) const

{
	SimpleImage image = ImageManager::loadImage("brick.png", false);
	image.renderImage(pSurface, iStartPositionScreenX, iStartPositionScreenY, iStartPositionScreenX, iStartPositionScreenY + getTileHeight(), getTileWidth(), getTileHeight());

}







