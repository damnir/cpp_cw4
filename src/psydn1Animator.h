#pragma once
#include "DisplayableObject.h"
#include "ImageObject.h"
#include "Psydn1Engine.h"

class psydn1Animator :
	public DisplayableObject
{
public:

	psydn1Animator(BaseEngine* pEngine);
	~psydn1Animator();

	void virtDraw() override;
	void virtDoUpdate(int iCurrentTime) override;

	/*
	SimpleImage images[14] = { ImageManager::loadImage("backgroundf1.png", false),
	ImageManager::loadImage("backgroundf2.png", false), 
	ImageManager::loadImage("backgroundf3.png", false),
	ImageManager::loadImage("backgroundf4.png", false),
	ImageManager::loadImage("backgroundf5.png", false),
	ImageManager::loadImage("backgroundf6.png", false),
	ImageManager::loadImage("backgroundf7.png", false),
	ImageManager::loadImage("backgroundf8.png", false),
	ImageManager::loadImage("backgroundf9.png", false),
	ImageManager::loadImage("backgroundf10.png", false),
	ImageManager::loadImage("backgroundf11.png", false),
	ImageManager::loadImage("backgroundf12.png", false),
	ImageManager::loadImage("backgroundf13.png", false)};
	*/


	SimpleImage images[6] = { (ImageManager::loadImage("lightningf1.png", false)),
	(ImageManager::loadImage("lightningf2.png", false)),
	(ImageManager::loadImage("lightningf3.png", false)) ,
	(ImageManager::loadImage("lightningf4.png", false)) ,
	(ImageManager::loadImage("lightningf5.png", false)) };
	SimpleImage light = ImageManager::loadImage("lightningm1.png", false);

	SimpleImage bricks[4] = { (ImageManager::loadImage("cutebrick1.png", false)),
	(ImageManager::loadImage("cutebrick2.png", false)),
	(ImageManager::loadImage("cutebrick3.png", false))};


	SimpleImage currentImage;
	SimpleImage currentBrick;

	int x = 0;
	int y = 0;
	int frames = 10;

	int randX;
	int randY;
};

