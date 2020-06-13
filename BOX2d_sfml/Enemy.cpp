#include "Enemy.h"

Enemy::Enemy(b2World* world, phMainEntityConfig conf, float SizeX, float SizeY, int type, grObj* sp) : entityBaseObj(world, conf, SizeX, SizeY, type, sp)
{
	entityBaseObj::getDebugSprite().setFillColor(sf::Color::Red);

};

void Enemy::attack(b2World& world, phMainEntityConfig conf)
{
	int sign = 1;
	this->getSprite()->objSprite().getScale().x > 0 ? sign = 1 : sign = -1;

	b2Vec2 point1 = getBody()->GetPosition();

	b2Vec2 point2 = point1;
	b2Vec2 point3 = point1;
	///meele
	point2.x += 3.5 * sign;

	point1.y += 2;
	///
	point3.x += 25 * sign;


	RayCastClosestCallback cl2;
	//world.RayCast(&cl1, point1, point2);
	world.RayCast(&cl2, point1, point3);

	if (cl2.m_hit)
	{

		if (!(int)cl2.fixtureToReturn->GetBody()->GetUserData() && !thrown)
		{
			//std::cout << "I see u" << std::endl;
			//projectaile stone(&h, &world, 30, 30, 23, b2Vec2(en.getBody()->GetPosition().x + sign*3, en.getBody()->GetPosition().y));
			stone.push_back(projectaile(conf, &world, 25, 25, 23, b2Vec2(getBody()->GetPosition().x + sign * 3, getBody()->GetPosition().y)));
			stone[0].throwPro(b2Vec2(50 * sign, 0));
			thrown = 1;
			cl.restart();



		}
	}

	if (cl.getElapsedTime().asSeconds() > 5.0)
	{
		for (int i = 0; i < stone.size(); ++i)
			world.DestroyBody(stone[i].getBody());

		stone.clear();
		thrown = 0;
	}

}

void Enemy::setBoardesNPC(sf::Vector2i bordes)
{
	this->bordes = bordes;
}

void Enemy::cycleMovomentNPC()
{
	if ((bordes.x / SCALE) - 10 > this->getBody()->GetPosition().x || (bordes.y / SCALE) + 10 < this->getBody()->GetPosition().x)
		this->getBody()->SetTransform(b2Vec2((bordes.x / SCALE + bordes.y / SCALE) / 2, 30), 0);



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

void Enemy::anim(float time, b2World& world, phMainEntityConfig conf)
{


	CurrentFrame += 0.009 * time;
	if (CurrentFrame > 18) CurrentFrame -= 18;
	entityBaseObj::getSprite()->objSprite().setTextureRect(sf::IntRect(226 * int(CurrentFrame), 0, 227, 227));


	(getBody()->GetLinearVelocity().x <= 0) ? entityBaseObj::getSprite()->objSprite().setScale(-1, 1) : entityBaseObj::getSprite()->objSprite().setScale(1, 1);





	if (getBody()->GetLinearVelocity().x != 0)
	{
		CurrentFrame += 0.009 * time;
		if (CurrentFrame > 12) CurrentFrame -= 12;
		entityBaseObj::getSprite()->objSprite().setTextureRect(sf::IntRect(226 * int(CurrentFrame), 227, 227, 227));
	}

	attack(world, conf);

}

void Enemy::playAnimation(int i)
{

}

