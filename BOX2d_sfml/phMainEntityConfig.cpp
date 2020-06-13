#include "phMainEntityConfig.h"
phMainEntityConfig::phMainEntityConfig()
{
	this->bFix.friction = 1;
	this->bFix.density = 1;

	this->bdef.fixedRotation = 0;
	this->bFix.restitution = 0;
}

b2BodyDef& phMainEntityConfig::getDef()
{
	return bdef;
}
b2FixtureDef& phMainEntityConfig::getFix()
{
	return bFix;
}