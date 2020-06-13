#include "edgeObj.h"

edgeObj::edgeObj(b2World& world, phMainEntityConfig h, sf::Vector2i StPoint, int type)
{
	
	b2EdgeShape shape;
	h.getDef().type = b2_staticBody;
	h.getFix().friction = -4;

	switch (type)
	{
	case 15:
	{
		StPoint.x += 25;
		StPoint.y += 25;

		h.getDef().position.x = StPoint.x / SCALE;
		h.getDef().position.y = StPoint.y / SCALE;

		b2Body* ground = world.CreateBody(&h.getDef());
		h.getFix().shape = &shape;

		h.getFix().density = 0.0f;
		h.getFix().friction = 0.6f;

		shape.Set(b2Vec2(StPoint.x / SCALE, StPoint.y / SCALE), b2Vec2((StPoint.x + 100) / SCALE, (StPoint.y + 100) / SCALE));
		ground->CreateFixture(&h.getFix());



		ground->SetUserData((void*)type);
		break;
	}
	case 16:
	{
		StPoint.x += 25;
		StPoint.y += 25;

		h.getDef().position.x = StPoint.x / SCALE;
		h.getDef().position.y = StPoint.y / SCALE;

		b2Body* ground = world.CreateBody(&h.getDef());
		h.getFix().shape = &shape;

		h.getFix().density = 0.0f;
		h.getFix().friction = 0.6f;

		shape.Set(b2Vec2(StPoint.x / SCALE, StPoint.y / SCALE), b2Vec2((StPoint.x + 200) / SCALE, (StPoint.y + 100) / SCALE));
		ground->CreateFixture(&h.getFix());



		ground->SetUserData((void*)type);
		break;
	}
	case 17:
	{
		StPoint.x += 25;
		StPoint.y += 25;

		h.getDef().position.x = StPoint.x / SCALE;
		h.getDef().position.y = StPoint.y / SCALE;

		b2Body* ground = world.CreateBody(&h.getDef());
		h.getFix().shape = &shape;

		h.getFix().density = 0.0f;
		h.getFix().friction = 0.6f;

		shape.Set(b2Vec2(StPoint.x / SCALE, StPoint.y / SCALE), b2Vec2((StPoint.x + 300) / SCALE, (StPoint.y + 100) / SCALE));
		ground->CreateFixture(&h.getFix());



		ground->SetUserData((void*)type);
		break;
	}
	case 18:
	{
		StPoint.x += 25;
		StPoint.y += 25;

		h.getDef().position.x = StPoint.x / SCALE;
		h.getDef().position.y = StPoint.y / SCALE;

		b2Body* ground = world.CreateBody(&h.getDef());
		h.getFix().shape = &shape;

		h.getFix().density = 0.0f;
		h.getFix().friction = 0.6f;

		shape.Set(b2Vec2(StPoint.x / SCALE, StPoint.y / SCALE), b2Vec2((StPoint.x - 100) / SCALE, (StPoint.y + 100) / SCALE));
		ground->CreateFixture(&h.getFix());



		ground->SetUserData((void*)type);
		break;
	}
	case 19:
	{
		StPoint.x += 25;
		StPoint.y += 25;

		h.getDef().position.x = StPoint.x / SCALE;
		h.getDef().position.y = StPoint.y / SCALE;

		b2Body* ground = world.CreateBody(&h.getDef());
		h.getFix().shape = &shape;

		h.getFix().density = 0.0f;
		h.getFix().friction = 0.6f;

		shape.Set(b2Vec2(StPoint.x / SCALE, StPoint.y / SCALE), b2Vec2((StPoint.x - 200) / SCALE, (StPoint.y + 100) / SCALE));
		ground->CreateFixture(&h.getFix());



		ground->SetUserData((void*)type);
		break;
	}
	case 20:
	{
		StPoint.x += 25;
		StPoint.y += 25;

		h.getDef().position.x = StPoint.x / SCALE;
		h.getDef().position.y = StPoint.y / SCALE;

		b2Body* ground = world.CreateBody(&h.getDef());
		h.getFix().shape = &shape;

		h.getFix().density = 0.0f;
		h.getFix().friction = 0.6f;

		shape.Set(b2Vec2(StPoint.x / SCALE, StPoint.y / SCALE), b2Vec2((StPoint.x - 300) / SCALE, (StPoint.y + 100) / SCALE));
		ground->CreateFixture(&h.getFix());



		ground->SetUserData((void*)type);
		break;
	}
	}

}