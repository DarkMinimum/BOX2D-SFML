#include "NPC.h"

NPC::NPC(b2World* world, phMainEntityConfig conf, float SizeX, float SizeY, int type, grObj* sp) : entityBaseObj(world, conf, SizeX, SizeY, type, sp) {};

void NPC::setBoardesNPC(sf::Vector2i bordes)
{
	this->bordes = bordes;
}

void NPC::playAnimation(int i)
{

}

void NPC::cycleMovomentNPC(b2World& world)
{
	b2Body* player = NULL;

	for (b2Body* BodyIterator = world.GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
	{
		if ((int)BodyIterator->GetUserData() == 0) player = BodyIterator;


	}
	if (player != NULL)
	{
		if (getInteractFlag() && abs(player->GetLinearVelocity().x) > 3.0) setWaiting();


		if ((bordes.x / SCALE) - 10 > this->getBody()->GetPosition().x || (bordes.y / SCALE) + 10 < this->getBody()->GetPosition().x)
			this->getBody()->SetTransform(b2Vec2((bordes.x / SCALE + bordes.y / SCALE) / 2, 30), 0);
	}

	//int cond = 0;
	if (!isInteract)
	{


		//smartMoving
		switch (cond)
		{

		case npcCondition::goRight:
		{


			if (entityBaseObj::getBody()->GetLinearVelocityFromLocalPoint(entityBaseObj::getBody()->GetPosition()).x < 8.0f)
				entityBaseObj::getBody()->ApplyLinearImpulse(b2Vec2(IMP2, 0), entityBaseObj::getBody()->GetWorldCenter(), 1);


			if (entityBaseObj::getBody()->GetPosition().x * SCALE >= bordes.y - randstep)
			{
				isReach = 1;
				randstep = (rand() % 3) * 100;
				cond = npcCondition::startTimer;


			}

			break;
		};
		case npcCondition::goLeft:
		{

			if (entityBaseObj::getBody()->GetLinearVelocityFromLocalPoint(entityBaseObj::getBody()->GetPosition()).x > -8.0f)
				entityBaseObj::getBody()->ApplyLinearImpulse(b2Vec2(-IMP2, 0), entityBaseObj::getBody()->GetWorldCenter(), 1);


			if (entityBaseObj::getBody()->GetPosition().x * SCALE <= bordes.x + randstep)
			{
				isReach = 0;
				randstep = (rand() % 3) * 100;
				cond = npcCondition::startTimer;
			}

			break;
		};
		case npcCondition::startTimer:
		{
			timeEntity = entityClock.restart();
			waitingTime = rand() % 3 + 2;
			cond = npcCondition::isWaiting;
			break;
		};
		case npcCondition::isWaiting:
		{
			timeEntity = entityClock.getElapsedTime();
			if (timeEntity.asSeconds() >= waitingTime)
				isReach == 0 ? cond = npcCondition::goRight : cond = npcCondition::goLeft;
			break;
		};

		}
	}
}

void NPC::setInteractFlag(bool flag)
{
	isInteract = flag;
}

bool NPC::getInteractFlag()
{
	return this->isInteract;
}

void NPC::setWaiting()
{
	isInteract = 0;
	this->cond = npcCondition::startTimer;

}

void NPC::anim(float time, b2World& world)
{


	CurrentFrame += 0.009 * time;
	if (CurrentFrame > 18) CurrentFrame -= 18;
	entityBaseObj::getSprite()->objSprite().setTextureRect(sf::IntRect(226 * int(CurrentFrame), 0, 227, 227));

	///animation
	if (!isInteract)
	{
		(getBody()->GetLinearVelocity().x <= 0) ? entityBaseObj::getSprite()->objSprite().setScale(-0.75, 0.75) : entityBaseObj::getSprite()->objSprite().setScale(0.75, 0.75);





		if (getBody()->GetLinearVelocity().x != 0)
		{
			CurrentFrame += 0.009 * time;
			if (CurrentFrame > 12) CurrentFrame -= 12;
			entityBaseObj::getSprite()->objSprite().setTextureRect(sf::IntRect(226 * int(CurrentFrame), 227, 227, 227));
		}
	}
}