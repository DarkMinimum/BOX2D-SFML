#pragma once
#include "phObj.h"
#include "grObj.h"

class entityBaseObj : public phObj
{
private:

	//b2Body* body;
	sf::RectangleShape spriteD;
	grObj* sp;


protected:
	float CurrentFrame = 0;

	int hp = 100;
	int armor = 100;
	int power = 10;
	bool alive = 1;

	int isAnimationInProcess = 0;
	sf::Clock clock;

	//for idk
	unsigned int x;
	unsigned int y;



public:
	entityBaseObj(b2World* world, phMainEntityConfig conf, float SizeX, float SizeY, int type, grObj* sprite);
	entityBaseObj(b2World* world, phMainEntityConfig conf, float SizeX, float SizeY, int type, grObj* sprite, bool i);
	b2Body* operator * ();
	int getHP() const;
	int getArmor() const;
	int getPower() const;
	sf::RectangleShape& getDebugSprite();
	grObj* getSprite();

	//virtual void anim(float time, b2World& world);
	//virtual void playAnimation(int i);

	bool isAlive() const;
	void setAlive(bool i);
	bool isAmipPlays() const;


};
