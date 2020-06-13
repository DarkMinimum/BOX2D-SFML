#pragma once
#include "Box2D\Box2D.h"

class RayCastClosestCallback : public b2RayCastCallback
{
public:

    bool m_hit;
    b2Vec2 m_point;
    b2Vec2 m_normal;
    b2Fixture* fixtureToReturn;


    RayCastClosestCallback()
    {
        m_hit = false;
        fixtureToReturn = NULL;
    }

    float ReportFixture(b2Fixture* fixture, const b2Vec2& point, const b2Vec2& normal, float fraction) override
    {
        b2Body* body = fixture->GetBody();
        void* userData = body->GetUserData();

        //if (userData)
        //{
        //  int index = (int)userData;
        //  if (index == 0)
        //  {
        //    // By returning -1, we instruct the calling code to ignore this fixture and
        //    // continue the ray-cast to the next fixture.
        //    return 1.0f;
        //  }
        //}

        if ((int)userData > 0 || (int)userData == 0)
        {
            m_hit = true;
            m_point = point;
            m_normal = normal;

            fixtureToReturn = fixture;
        }

        // By returning the current fraction, we instruct the calling code to clip the ray and
        // continue the ray-cast to the next fixture. WARNING: do not assume that fixtures
        // are reported in order. However, by clipping, we can always get the closest fixture.
        return fraction;
    }


};
