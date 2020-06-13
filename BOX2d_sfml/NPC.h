#pragma once
#include "EntityBaseObj.h"
class NPC : public entityBaseObj
{
private:
	/* Intaraction staff */
	bool isInteract = 0;




	/*For cycle movoment*/

	sf::Time timeEntity; // stop on the edges
	sf::Clock entityClock;


	enum npcCondition { goRight, goLeft, startTimer, isWaiting }; // obvious tags

	sf::Vector2i bordes; // staff for movoment
	bool isReach = 0;
	int randstep = 0;
	float waitingTime = 0;

	int cond = 0;
	float IMP2 = 7;


public:
	NPC(b2World* world, phMainEntityConfig conf, float SizeX, float SizeY, int type, grObj* sp);
	

	void setBoardesNPC(sf::Vector2i bordes);

	void playAnimation(int i);

	void cycleMovomentNPC(b2World& world);

	void setInteractFlag(bool flag);

	bool getInteractFlag();

	void setWaiting();

	virtual void anim(float time, b2World& world);
};

