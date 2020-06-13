#pragma once
#include "phStaticObj.h"

class bridgeObj
{
private:

    int len = 30;
public:
    bridgeObj(b2World* world, phStaticObj& A, phStaticObj& B)
    {

        b2PolygonShape shape;
        shape.SetAsBox((100 / SCALE) / 2, (20 / SCALE) / 2);

        b2FixtureDef fd;
        fd.shape = &shape;
        fd.density = 20.0f;
        fd.friction = 0.2f;

        b2RevoluteJointDef jd;



        b2Body* prevBody = A.getBody();
        b2Body* m_middle = NULL;

        int e_count = abs(A.getBody()->GetPosition().x - B.getBody()->GetPosition().x) / (100 / SCALE);
        for (int32 i = 0; i < e_count; ++i)
        {
            b2BodyDef bd;
            bd.type = b2_dynamicBody;
            bd.position.Set(A.getBody()->GetPosition().x + (100 / SCALE) + (100 / SCALE) * i, B.getBody()->GetPosition().y);
            b2Body* body = world->CreateBody(&bd);
            body->CreateFixture(&fd);
            int type = rand() % 3 + 2;

            body->SetUserData((void*)type);

            b2Vec2 anchor(A.getBody()->GetPosition().x + (100 / SCALE) * i, B.getBody()->GetPosition().y);
            jd.Initialize(prevBody, body, anchor);
            world->CreateJoint(&jd);

            if (i == (e_count >> 1))
            {
                m_middle = body;
            }
            prevBody = body;
        }

        b2Vec2 anchor(A.getBody()->GetPosition().x + (100 / SCALE) * e_count, A.getBody()->GetPosition().y);
        jd.Initialize(prevBody, B.getBody(), anchor);
        world->CreateJoint(&jd);




    }
};
