#pragma once
#include "EntityBaseObj.h"
#include "msgCloud.h"
#include <SFML/Audio.hpp>
#include "RayCastClosestCallback.h"
#include "backGroundParalax.h"
#include "NPC.h"

#define SIZEX 1920
#define SIZEY 1080
#define IMP 14.5





class playerFinalObj : public entityBaseObj, public msgCloud
{
private:
	sf::View view;
	sf::Clock blClock, moveClock;
	bool blood = 0;
	bool isWin = 0;
	bool yes, pressed2 = 0;

	sf::Sound step, hurtSound, woodImp, sound;
	sf::SoundBuffer stepBuffer, hurtBuf, woodBuf, buffer;



public:
	bool isSpeaking = 0;

	playerFinalObj(b2World* world, phMainEntityConfig conf, grObj* sp);

	void CamUpDate();
	sf::View& getCamera();
	void ZoomChange(float a);

	void interact(b2World& world, grObj& boySp, std::vector<NPC*>& vec);

	void playAnimation(int i);
	void cam(sf::RenderWindow& window);

	bool onGround(b2World& world);
	int isNextToCrate(b2World& world);

	b2Body* getNextCrateToPlayer(b2World& world);

	void hurt(int dam);

	int getAnX() const;
	int getAnY() const;

	void collision(b2World& world);

	void anim(float time, b2World& world, grObj& boySp, std::vector<NPC*>& vec);

	sf::Text getText();

	sf::Sprite& getCloudSprite();

};
