#pragma once
#include "DisplayableObject.h"
#include "ImageObject.h"

#include "Psydn1Engine.h"

class Psydn1BarObject :
	public DisplayableObject
{
public:

	Psydn1BarObject(BaseEngine* pEngine);
	~Psydn1BarObject();

	void virtDraw() override;
	void virtDoUpdate(int iCurrentTime) override;
	SimpleImage image = ImageManager::loadImage("bar_object.png", true);

	SimpleImage images[11] = { (ImageManager::loadImage("barf1.png", false)),
		(ImageManager::loadImage("barf2.png", false)),
		(ImageManager::loadImage("barf3.png", false)) ,
		(ImageManager::loadImage("barf4.png", false)) ,
		(ImageManager::loadImage("barf5.png", false)) ,
		(ImageManager::loadImage("barf6.png", false)) , 
		(ImageManager::loadImage("barf7.png", false)) , 
		(ImageManager::loadImage("barf8.png", false)) , 
		(ImageManager::loadImage("barf9.png", false)) , 
		(ImageManager::loadImage("barf10.png", false)) , };

	int x = 9;
	int frames = 5;

};

