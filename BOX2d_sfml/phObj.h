#pragma once
#define SCALE 30.0
#include "SFML/Graphics.hpp"
#include "Box2D\Box2D.h"
#include "phMainEntityConfig.h"

class phObj
{
private:

	b2Body* boxBody; //bodyPointer
	b2PolygonShape shape; // shape model
	//visualisation
	sf::RectangleShape sprite;

public:
	//Rectangle
	phObj(b2World* world, float SizeX, float SizeY, phMainEntityConfig conf, int type, bool smartType);
	phObj()
	{

	};

	sf::RectangleShape& getDebugSprite();
	b2Body* getBody();
	void setPos(float X, float Y);
	


};



