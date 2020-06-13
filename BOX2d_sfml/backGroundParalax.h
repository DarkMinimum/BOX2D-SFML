#pragma once
#include "grObj.h"


#define SIZEX 1920
#define SIZEY 1080


class backGroundParalax
{
private:
    int n = 4;
    grObj* pt;
public:


    backGroundParalax(std::string loc, float x, float y);
    grObj& operator[](int a) const;
    int getOriginX(int a) const;
    int getPos(int a)const;
    void anim(grObj& plSp, float vel);
    ~backGroundParalax();

};

float getLen(float x);
float dis(float a, float b);