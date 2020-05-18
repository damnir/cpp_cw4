#pragma once
#include "DisplayableObject.h"
#include "ImageObject.h"
#include "Psydn1Engine.h"

class psydn1BombObject :
	public DisplayableObject
{

public:
	psydn1BombObject(BaseEngine* pEngine);
	~psydn1BombObject();

	void virtDraw() override;
	void virtDoUpdate(int iCurrentTime) override;
	SimpleImage light = ImageManager::loadImage("lightningm1.png", false);
	SimpleImage images[6] = { (ImageManager::loadImage("lightningf1.png", false)), 
		(ImageManager::loadImage("lightningf2.png", false)),
		(ImageManager::loadImage("lightningf3.png", false)) ,
		(ImageManager::loadImage("lightningf4.png", false)) ,
		(ImageManager::loadImage("lightningf5.png", false))};
	SimpleImage bomb;

	int x = 0;
	int frames = 10;
};

