#include "projectaile.h"
projectaile::projectaile(phMainEntityConfig conf, b2World* world, float SizeX, float SizeY, int type, b2Vec2 i) : phObj(world, SizeX, SizeY, conf, type, 0)
{
	conf.getDef().fixedRotation = 0;
	phObj::getBody()->SetTransform(i, 0);
	phObj::getBody()->SetBullet(true);

	//this->getBody()->SetUserData((void*)type);
}

void projectaile::throwPro(b2Vec2 v)
{
	phObj::getBody()->SetLinearVelocity(v);
}

projectaile::~projectaile()
{
	phObj::~phObj();
}
