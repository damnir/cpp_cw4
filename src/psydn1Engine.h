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
	int virtInitialiseObjects() override;
	void virtDrawStringsOnTop() override;
	void virtDrawStringsUnderneath() override;
	void virtMouseDown(int iButton, int iX, int iY) override;
	virtual void virtKeyDown(int iKeyCode) override;

	void increaseTiles() { tiles++; }
	void increaseDeaths() { deaths++; }
	void hitDetected() {
		gState = s_main;
		lockAndSetupBackground();
		redrawDisplay();
	}

	Psydn1TileManager& GetTileManager() { return tm; }

protected:
public:
	int tiles = 0;
	int deaths = 0;
	bool start = false;
	char name[10] = ("---------");
	int nameChars = 0;
	bool validName = true;


	Psydn1TileManager tm;

	enum State {s_init, s_main, s_paused, s_nickname};
	State gState;

private:
};

