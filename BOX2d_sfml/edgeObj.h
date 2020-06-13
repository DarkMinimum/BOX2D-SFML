#pragma once
#define SCALE 30.0
#include "phMainEntityConfig.h"
#include "SFML/Graphics.hpp"
#include "Box2D\Box2D.h"

class edgeObj
{
public:
	edgeObj(b2World& world, phMainEntityConfig h, sf::Vector2i StPoint, int type);
};



