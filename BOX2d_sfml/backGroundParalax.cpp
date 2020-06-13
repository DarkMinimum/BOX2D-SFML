#include "backGroundParalax.h"

#include <math.h>

float getLen(float x)
{
    return round(x + 0.5);
}

float dis(float a, float b)
{
    return abs(a - b);

}


backGroundParalax::backGroundParalax(std::string loc, float x, float y)
{
    this->pt = new grObj[n];


    for (int i = 0; i < n - 1; ++i)
    {
        pt[i].setRes(loc + std::to_string(i) + ".png");

        pt[i].objSprite().setOrigin(SIZEX / 2, SIZEY / 2);
        pt[i].objSprite().setPosition(x, y);
    }


    pt[n - 1] = pt[2];

    pt[n - 1].objSprite().setOrigin(SIZEX / 2, SIZEY / 2);
    pt[n - 1].objSprite().setPosition(x - 1920 + 2, y);

}

grObj& backGroundParalax::operator[](int a) const
{
    return this->pt[a];
}

int backGroundParalax::getOriginX(int a) const
{
    return pt[a].objSprite().getOrigin().x;
}

int backGroundParalax::getPos(int a)const
{
    return pt[a].objSprite().getPosition().x;
}

void backGroundParalax::anim(grObj& plSp, float vel)
{
    grObj* current, * ghost;
    current = NULL; ghost = NULL;

    int pos;

    float firstPoint = dis(plSp.objSprite().getPosition().x, pt[2].objSprite().getPosition().x);
    float secondPoint = dis(plSp.objSprite().getPosition().x, pt[3].objSprite().getPosition().x);

    //vel = player.getBody()->GetLinearVelocity().x;

    if (firstPoint < secondPoint)
    {
        current = &pt[2];
        ghost = &pt[3];
    }
    if (firstPoint > secondPoint)
    {
        current = &pt[3];
        ghost = &pt[2];
    }

    //move slides
    if (vel > 0)
    {
        ///here
        //lv_1.setPosX(2, vel / 25);
        pt[2].objSprite().setPosition(pt[2].objSprite().getPosition().x + vel / 25, pt[2].objSprite().getPosition().y);
        pt[3].objSprite().setPosition(pt[3].objSprite().getPosition().x + vel / 25, pt[3].objSprite().getPosition().y);

        if (dis(plSp.objSprite().getPosition().x, current->objSprite().getPosition().x) <= 15.0)
            ghost->objSprite().setPosition(current->objSprite().getPosition().x + 1920 - 2, 500);

    }
    if (vel < 0)
    {
        ///here
        pt[2].objSprite().setPosition(pt[2].objSprite().getPosition().x + vel / 25, pt[2].objSprite().getPosition().y);
        pt[3].objSprite().setPosition(pt[3].objSprite().getPosition().x + vel / 25, pt[3].objSprite().getPosition().y);

        if (dis(plSp.objSprite().getPosition().x, current->objSprite().getPosition().x) <= 15.0)
            ghost->objSprite().setPosition(current->objSprite().getPosition().x - 1920 + 2, 500);

    }


}

backGroundParalax::~backGroundParalax()
{
    delete[] pt;
    pt = NULL;
}

