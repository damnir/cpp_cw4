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
	//image.renderImage(pSurface, iStartPositionScreenX, iStartPositionScreenY, iStartPositionScreenX, iStartPositionScreenY + getTileHeight(), getTileWidth(), getTileHeight());
	image.renderImageWithMaskAndTransparency(pSurface, iStartPositionScreenX, iStartPositionScreenY, iStartPositionScreenX, iStartPositionScreenY + getTileHeight(), getTileWidth(), getTileHeight(), 0, 100);
	//image2.renderImageWithMaskAndTransparency(pSurface, iStartPositionScreenX, iStartPositionScreenY, iStartPositionScreenX, iStartPositionScreenY + getTileHeight(), getTileWidth(), getTileHeight(), 0, 60);

}

void Psydn1TileManager::redrawTile(
	BaseEngine* pEngine,
	DrawingSurface* pSurface,
	int iMapX, int iMapY,
	int iStartPositionScreenX, int iStartPositionScreenY)

{
	pSurface->mySDLLockSurface();

	//pSurface->fillSurface(0);
	//image2.renderImage(pSurface, iStartPositionScreenX, iStartPositionScreenY, iStartPositionScreenX, iStartPositionScreenY + getTileHeight(), getTileWidth(), getTileHeight());
	image2.renderImageWithMaskAndTransparency(pSurface, iStartPositionScreenX, iStartPositionScreenY, iStartPositionScreenX, iStartPositionScreenY + getTileHeight(), getTileWidth(), getTileHeight(), 0, 60);
	//image2.resizeTo(20, 20);

	pSurface->mySDLUnlockSurface();


}









