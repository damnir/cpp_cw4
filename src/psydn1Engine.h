#pragma once

#include "BaseEngine.h"
#include "Psydn1TileManager.h"

class Psydn1Engine :
	public BaseEngine
{
public:
	Psydn1Engine();
	~Psydn1Engine();
	void virtSetupBackgroundBuffer();
	void virtDrawStringsOnTop() override;
	void virtDrawStringsUnderneath() override;
	void virtMouseDown(int iButton, int iX, int iY) override;
	virtual void virtKeyDown(int iKeyCode) override;

	void increaseTiles() { tiles++; }
	void increaseDeaths() { deaths++; }

	Psydn1TileManager& GetTileManager() { return tm; }

protected:
public:
	int tiles = 0;
	int deaths = 0;
	int virtInitialiseObjects();
	bool start = false;
	Psydn1TileManager tm;
};

