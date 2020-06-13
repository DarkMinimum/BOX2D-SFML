#include "phObj.h"

//Rectangle
phObj::phObj(b2World* world, float SizeX, float SizeY, phMainEntityConfig conf, int type, bool smartType)
{
	sprite.setSize(sf::Vector2f(SizeX, SizeY));
	sprite.setFillColor(sf::Color::Blue);
	sprite.setOrigin(SizeX / 2, SizeY / 2);

	conf.getFix().friction = 0.95;

	conf.getDef().type = b2_dynamicBody;
	//conf.getDef().position.Set(x, y);

	boxBody = (*world).CreateBody(&conf.getDef());

	if (!smartType)
	{
		shape.SetAsBox((SizeX / SCALE) / 2, (SizeY / SCALE) / 2);

		conf.getFix().shape = &shape;

	}
	if (smartType)
	{
		b2Vec2 vertices[6];

		vertices[0].Set(-SizeX / SCALE / 2, -SizeY / SCALE / 2);
		vertices[1].Set(SizeX / SCALE / 2, -SizeY / SCALE / 2);
		vertices[2].Set(SizeX / SCALE / 2, SizeY / SCALE / 2 - SizeX / SCALE / 4);
		vertices[3].Set(-SizeX / SCALE / 2, SizeY / SCALE / 2 - SizeX / SCALE / 4);
		vertices[4].Set(SizeX / SCALE / 2 - 1, SizeY / SCALE / 2);
		vertices[5].Set(-SizeX / SCALE / 2 + 1, SizeY / SCALE / 2);

		shape.Set(vertices, 6);
		conf.getFix().shape = &shape;
	}

	boxBody->CreateFixture(&conf.getFix());


	boxBody->SetUserData((void*)type);



}
sf::RectangleShape& phObj::getDebugSprite()
{
	return this->sprite;
}
b2Body* phObj::getBody()
{
	return this->boxBody;
}
void phObj::setPos(float X, float Y)
{
	this->boxBody->SetTransform(b2Vec2(X / SCALE, Y / SCALE), 0);
}
