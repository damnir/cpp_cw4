#pragma once
#include "DisplayableObject.h"
#include "Psydn1Engine.h"

class Psydn1BarObject :
	public DisplayableObject
{
public:

	Psydn1BarObject(BaseEngine* pEngine);
	~Psydn1BarObject();

	void virtDraw() override;
	void virtDoUpdate(int iCurrentTime) override;
};

