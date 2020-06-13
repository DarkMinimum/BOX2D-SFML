#pragma once
#include "phObj.h"

class phStaticObj : public phObj
{
private:
    //b2Body* boxBody; //bodyPointer
    b2PolygonShape shape; // shape model
    //visualisation
    sf::RectangleShape sprite;
public:


    phStaticObj(b2World* world, phMainEntityConfig conf, int type);
    phStaticObj()
    {

    }
    sf::RectangleShape& getDebugSprite();
    b2Body* getBody();
    void setPos(float X, float Y);
    void setRot(float angle);

};