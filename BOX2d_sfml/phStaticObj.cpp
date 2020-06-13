#include "phStaticObj.h"

phStaticObj::phStaticObj(b2World* world, phMainEntityConfig conf, int type) : phObj(world, 100, 100, conf, type, 0)
{
    sprite.setSize(sf::Vector2f(100, 100));
    sprite.setFillColor(sf::Color::Green);
    sprite.setOrigin(100 / 2, 100 / 2);

    phObj::getBody()->SetType(b2_staticBody);
    //phObj::getBody()

    sprite.setOutlineThickness(3);
    sprite.setOutlineColor(sf::Color::White);

}

sf::RectangleShape& phStaticObj::getDebugSprite()
{
    return this->sprite;
}

b2Body* phStaticObj::getBody()
{
    return phObj::getBody();
}
void phStaticObj::setPos(float X, float Y)
{
    phObj::getBody()->SetTransform(b2Vec2(X / SCALE, Y / SCALE), 0);
}
void phStaticObj::setRot(float angle)
{
    phObj::getBody()->SetTransform(phObj::getBody()->GetPosition(), (3.14 * angle) / 180);
}