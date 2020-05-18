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
	SimpleImage image = ImageManager::loadImage("brick2.png", true);
	SimpleImage images[6] = { (ImageManager::loadImage("lightningf1.png", true)), 
		(ImageManager::loadImage("lightningf2.png", true)),
		(ImageManager::loadImage("lightningf3.png", true)) ,
		(ImageManager::loadImage("lightningf4.png", true)) ,
		(ImageManager::loadImage("lightningf5.png", true))};
	SimpleImage bomb;

	int x = 0;
	int frames = 10;
};

