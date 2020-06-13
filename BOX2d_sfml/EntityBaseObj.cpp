#include "EntityBaseObj.h"

entityBaseObj::entityBaseObj(b2World* world, phMainEntityConfig conf, float SizeX, float SizeY, int type, grObj* sprite) : phObj(world, SizeX, SizeY, conf, type, 1)
{

	spriteD.setSize(sf::Vector2f(SizeX, SizeY));
	spriteD.setFillColor(sf::Color::Blue);
	spriteD.setOrigin(SizeX / 2, SizeY / 2);
	phObj::getBody()->SetFixedRotation(1);

	sp = sprite;



}

entityBaseObj::entityBaseObj(b2World* world, phMainEntityConfig conf, float SizeX, float SizeY, int type, grObj* sprite, bool i) : phObj(world, SizeX, SizeY, conf, type, 0)
{

	spriteD.setSize(sf::Vector2f(SizeX, SizeY));
	spriteD.setFillColor(sf::Color::Blue);
	spriteD.setOrigin(SizeX / 2, SizeY / 2);

	

	sp = sprite;



}

b2Body* entityBaseObj::operator * ()
{
	return phObj::getBody();
}

int entityBaseObj::getHP() const
{
	return hp;
}
int entityBaseObj::getArmor() const
{
	return armor;
}
int entityBaseObj::getPower() const {
	return power;
}

sf::RectangleShape& entityBaseObj::getDebugSprite()
{
	return this->spriteD;
}


grObj* entityBaseObj::getSprite()
{
	return sp;
}

//virtual void anim(float time, b2World& world);
//virtual void playAnimation(int i);

bool entityBaseObj::isAlive() const
{
	return alive;
}

void entityBaseObj::setAlive(bool i)
{
	alive = i;
}

bool entityBaseObj::isAmipPlays() const
{
	return isAnimationInProcess;
}


