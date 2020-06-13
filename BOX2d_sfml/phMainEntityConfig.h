#pragma once
#include "Box2D\Box2D.h"

//phisical configuration
class phMainEntityConfig
{
private:
	b2BodyDef bdef; // idk
	b2FixtureDef bFix; //fixture - density, friction, 
public:
	phMainEntityConfig();
	b2BodyDef& getDef();
	b2FixtureDef& getFix();
};


