#pragma once
#include "entityBaseObj.h"
#include "projectaile.h"
#include "RayCastClosestCallback.h"

class Enemy : public entityBaseObj
{
private:
	/*For cycle movoment*/

	sf::Time timeEntity; // stop on the edges
	sf::Clock entityClock;
	sf::Clock cl;


	enum npcCondition { goRight, goLeft, startTimer, isWaiting }; // obvious tags

	sf::Vector2i bordes; // staff for movoment
	bool isReach = 0;
	int randstep = 0;
	float waitingTime = 0;

	int cond = 0;
	float IMP2 = 14;
	bool thrown = 0;

	std::vector<projectaile> stone;

public:
	Enemy(b2World* world, phMainEntityConfig conf, float SizeX, float SizeY, int type, grObj* sp);

	void attack(b2World& world, phMainEntityConfig conf);

	void setBoardesNPC(sf::Vector2i bordes);

	void cycleMovomentNPC();

	void anim(float time, b2World& world, phMainEntityConfig conf);

	void playAnimation(int i);

};
