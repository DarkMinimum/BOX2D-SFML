#pragma once
#include "phObj.h"

class projectaile : public phObj
{
private:


public:
	//scaled entity

	projectaile(phMainEntityConfig conf, b2World* world, float SizeX, float SizeY, int type, b2Vec2 i);

	void throwPro(b2Vec2 v);

	~projectaile();



};

