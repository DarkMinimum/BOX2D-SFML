#include "playerFinalObj.h"
#include <iostream>

playerFinalObj::playerFinalObj(b2World* world, phMainEntityConfig conf, grObj* sp) : entityBaseObj(world, conf, 50, 125, 0, sp), msgCloud()
{
	this->view.reset(sf::FloatRect(0, 0, SIZEX * 1, SIZEY * 1));
	phObj::setPos(0, 900);
	


	stepBuffer.loadFromFile("assets/sounds/grass1.wav");
	hurtBuf.loadFromFile("assets/sounds/hurt.wav");
	woodBuf.loadFromFile("assets/sounds/crate_impact.wav");
	buffer.loadFromFile("assets/sounds/button.wav");
	step.setVolume(20);

	sound.setBuffer(buffer);
	sound.setVolume(20);



	step.setBuffer(stepBuffer);

	hurtSound.setBuffer(hurtBuf);

	woodImp.setBuffer(woodBuf);
	woodImp.setVolume(20);

}

void playerFinalObj::CamUpDate()
{
	view.setCenter(entityBaseObj::getBody()->GetPosition().x * SCALE, entityBaseObj::getBody()->GetPosition().y * SCALE - 400);
}
sf::View& playerFinalObj::getCamera()
{
	return this->view;
}
void playerFinalObj::ZoomChange(float a)
{
	view.zoom(a);
}

void playerFinalObj::interact(b2World& world, grObj& boySp, std::vector<NPC*>& vec)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && vec.size())
	{
		if (!pressed2)
		{
			b2Vec2 point1 = getBody()->GetPosition();
			b2Vec2 point2 = point1;

			//get where is looking
			int sign = 1;
			this->getSprite()->objSprite().getScale().x > 0 ? sign = 1 : sign = -1;


			point2.x += 10 * sign;

			RayCastClosestCallback callback;
			world.RayCast(&callback, point1, point2);

			NPC* firstOne = NULL;
			float distance = dis(getBody()->GetPosition().x, vec[0]->getBody()->GetPosition().x);


			//get closest NPC
			for (int i = 0; i < vec.size(); ++i)
			{
				if (dis(phObj::getBody()->GetPosition().x, vec[i]->getBody()->GetPosition().x) <= distance)
				{
					//std::cout << dis(getBody()->GetPosition().x, vec[i]->getBody()->GetPosition().x) << std::endl;
					firstOne = vec[i];
				}
			}


			if (firstOne != NULL)
			{

				if (callback.m_hit && (int)callback.fixtureToReturn->GetBody()->GetUserData() == 21)
				{
					isSpeaking = 1;
					firstOne->getInteractFlag() == 0 ? firstOne->setInteractFlag(1) : firstOne->setWaiting();
					grObj::objSprite().getScale().x > 0 ? boySp.setScale(-0.75, 0.75) : boySp.setScale(0.75, 0.75);
					openCloud(boySp.getPosition(), boySp.getScaleX(), "Hi there, Bro!\nI'm friendly NPC!\nI'm waiting for ur AI\nI need friends...");
					sound.play();
				}

			}

			pressed2 = 1;
		}
	}
	else pressed2 = 0;
}

void playerFinalObj::playAnimation(int i)
{
	CurrentFrame = 0;
	isAnimationInProcess = i;
	clock.restart();

}

void playerFinalObj::cam(sf::RenderWindow& window)
{
	//camera
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
	{
		ZoomChange(1.01f);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
	{
		ZoomChange(0.99f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Divide))
	{

		getCamera() = (window.getDefaultView());
		getCamera().setCenter(getDebugSprite().getPosition().x, getDebugSprite().getPosition().y);
	}
}

bool playerFinalObj::onGround(b2World& world)
{
	/////check if onGround//////
	bool onGround = false;
	///pos medium
	b2Vec2 pos1 = getBody()->GetPosition();
	pos1.y += ((125.f / 2) / SCALE + 0.1);
	b2Vec2 pos2 = pos1;
	pos1.x += 0.5;
	pos2.x -= 0.5;

	for (b2Body* it = world.GetBodyList(); it != 0; it = it->GetNext())
		for (b2Fixture* f = it->GetFixtureList(); f != 0; f = f->GetNext())
			if (f->TestPoint(pos1) || f->TestPoint(pos2))  onGround = true;
	///////end////////

	return onGround;
}

int playerFinalObj::isNextToCrate(b2World& world)
{
	/////check if onGround//////
	int nextToCrate = 0;
	///pos medium
	b2Vec2 pos1 = this->getBody()->GetPosition();
	pos1.x += 1;
	b2Vec2 pos2 = pos1;
	pos2.x -= 2;


	for (b2Body* it = world.GetBodyList(); it != 0; it = it->GetNext())
		for (b2Fixture* f = it->GetFixtureList(); f != 0; f = f->GetNext())
		{
			if ((int)it->GetUserData() == 1)
			{
				if (f->TestPoint(pos1))  nextToCrate = -1;
				if (f->TestPoint(pos2))  nextToCrate = 1;
			}
		}
	///////end////////

	return nextToCrate;
}

b2Body* playerFinalObj::getNextCrateToPlayer(b2World& world)
{
	/////check if onGround//////

	b2Body* resBody = NULL;

	///pos medium
	b2Vec2 pos1 = this->getBody()->GetPosition();
	b2Vec2 pos2 = pos1;
	pos1.x += 1;
	pos2.x -= 1;
	if (isNextToCrate(world))
	{
		for (b2Body* it = world.GetBodyList(); it != 0; it = it->GetNext())
			for (b2Fixture* f = it->GetFixtureList(); f != 0; f = f->GetNext())
			{
				if ((int)it->GetUserData() == 1)
				{
					if (f->TestPoint(pos1))
						resBody = it;
					if (f->TestPoint(pos2))  resBody = it;
				}
			}
	}
	///////end////////

	return resBody;
}

void playerFinalObj::hurt(int dam)
{
	int dir;
	playAnimation(4);
	entityBaseObj::getSprite()->getScaleX() == 1 ? dir = -1 : dir = 1;
	entityBaseObj::getSprite()->objSprite().setColor(sf::Color::Red);
	entityBaseObj::getBody()->ApplyLinearImpulse(b2Vec2(IMP * 7 * dir, 0), getBody()->GetWorldCenter(), 1);

	armor -= dam;

	if (armor < 0)
	{
		hp += armor;
		armor = 0;
	}

	hp <= 0 ? setAlive(0) : setAlive(1);

}

int playerFinalObj::getAnX() const { return x; }
int playerFinalObj::getAnY() const { return y; }

void playerFinalObj::collision(b2World& world)
{
	
	for (b2ContactEdge* edge = getBody()->GetContactList(); edge; edge = edge->next)
	{
		
			
		if ((int)edge->contact->GetFixtureB()->GetBody()->GetUserData() == 23 && !blood)
			if (fabs(edge->contact->GetFixtureB()->GetBody()->GetLinearVelocity().x) > 30)
			{
				hurt(0);

				hurtSound.play();
				blood = 1;
				blClock.restart();

			}

		

		if ((int)edge->contact->GetFixtureA()->GetBody()->GetUserData() == 22 && !blood)
		{
			
			hurt(0);
			hurtSound.play();
			blood = 1;
			blClock.restart();

		}

		
	}


	//grab_the_box
	//And_kick...
	if (isNextToCrate(world) != 0)
	{
		b2Body* crate = getNextCrateToPlayer(world);
		int cof = isNextToCrate(world);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && crate != NULL && !isAmipPlays())
		{
			playAnimation(1);
			woodImp.play();

			crate->ApplyLinearImpulse(b2Vec2(IMP * 10 * cof, 0), crate->GetWorldCenter(), 1);
			getBody()->ApplyLinearImpulse(b2Vec2(IMP * 9 * cof, 0), crate->GetWorldCenter(), 1);
		}

		//done
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && crate != NULL && !isAmipPlays())
		{
			playAnimation(2);
			woodImp.play();
			crate->ApplyLinearImpulse(b2Vec2(IMP * 10 * -cof, 0), crate->GetWorldCenter(), 1);

		}
	}
}

void playerFinalObj::anim(float time, b2World& world, grObj& boySp, std::vector<NPC*>& vec)
{

	x = 226 * int(CurrentFrame); y = 0;

	//movement
	if (onGround(world))
	{

		CurrentFrame += 0.009 * time;
		if (CurrentFrame > 18) CurrentFrame -= 18;
		if (!isAnimationInProcess)
		{
			entityBaseObj::getSprite()->objSprite().setTextureRect(sf::IntRect(226 * int(CurrentFrame), 0, 227, 227));
		}


		//jump
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			getBody()->ApplyLinearImpulse(b2Vec2(0, -IMP * 8.5), getBody()->GetWorldCenter(), 1);
		//left
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			entityBaseObj::getSprite()->objSprite().setScale(-1.0f, 1.0f);

			CurrentFrame += 0.019 * time;
			if (CurrentFrame > 12) CurrentFrame -= 12;

			if (!isAnimationInProcess)
			{
				entityBaseObj::getSprite()->objSprite().setTextureRect(sf::IntRect(226 * int(CurrentFrame), 227, 227, 227));
			}

			//x = 226 * int(CurrentFrame); y = 227;

			if (getBody()->GetLinearVelocityFromLocalPoint(getBody()->GetPosition()).x > -25.0f)
				getBody()->ApplyLinearImpulse(b2Vec2(-IMP, 0), getBody()->GetWorldCenter(), 1);

			//std::cout << player.getBody()->GetLinearVelocityFromLocalPoint(player.getBody()->GetPosition()).x << "\n";

		}
		//right
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{

			CurrentFrame += 0.019 * time;
			if (CurrentFrame > 12) CurrentFrame -= 12;
			if (!isAnimationInProcess)
			{
				entityBaseObj::getSprite()->objSprite().setTextureRect(sf::IntRect(226 * int(CurrentFrame), 227, 227, 227));
			}
			entityBaseObj::getSprite()->objSprite().setScale(1.0f, 1.0f);

			//x = 226 * int(CurrentFrame); y = 227;

			if (getBody()->GetLinearVelocityFromLocalPoint(getBody()->GetPosition()).x < 25.0f)
				getBody()->ApplyLinearImpulse(b2Vec2(IMP, 0), getBody()->GetWorldCenter(), 1);

		}
		
	}

	//air
	if (!onGround(world))
	{

		CurrentFrame += 0.0075 * time;
		if (CurrentFrame > 6) CurrentFrame -= 6;
		if (!isAnimationInProcess)
		{
			entityBaseObj::getSprite()->objSprite().setTextureRect(sf::IntRect((226 * 8) + (226 * int(CurrentFrame)), 227 * 3, 227, 227));
		}

		//x = (226 * 8) + (226 * int(CurrentFrame)); y = 227 * 3;

		///right air
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			entityBaseObj::getSprite()->objSprite().setScale(1.0f, 1.0f);
			CurrentFrame += 0.0075 * time;
			if (CurrentFrame > 6) CurrentFrame -= 6;
			if (!isAnimationInProcess)
			{
				entityBaseObj::getSprite()->objSprite().setTextureRect(sf::IntRect((226 * 8) + (226 * int(CurrentFrame)), 227 * 3, 227, 227));
			}

			//x = (226 * 8) + (226 * int(CurrentFrame)); y = 227 * 3;

			if (getBody()->GetLinearVelocityFromLocalPoint(getBody()->GetPosition()).x < 7.0f)
				getBody()->ApplyLinearImpulse(b2Vec2(IMP / 4, 0), getBody()->GetWorldCenter(), 1);
		}
		//left air
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			entityBaseObj::getSprite()->objSprite().setScale(-1.0f, 1.0f);
			CurrentFrame += 0.0075 * time;
			if (CurrentFrame > 6) CurrentFrame -= 6;
			if (!isAnimationInProcess)
			{
				entityBaseObj::getSprite()->objSprite().setTextureRect(sf::IntRect((226 * 8) + (226 * int(CurrentFrame)), 227 * 3, 227, 227));
			}
			//x = (226 * 8) + (226 * int(CurrentFrame)); y = 227 * 3;

			if (getBody()->GetLinearVelocityFromLocalPoint(getBody()->GetPosition()).x > -7.0f)
				getBody()->ApplyLinearImpulse(b2Vec2(-IMP / 4, 0), getBody()->GetWorldCenter(), 1);
		}
	}

	//nevermind
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		getBody()->SetTransform(b2Vec2(0, 0), 0);
		//std::cout << "R pressed...\n";

	}

	switch (isAnimationInProcess)
	{

	case 1:
	{

		float t = clock.getElapsedTime().asSeconds();
		CurrentFrame += 0.02 * t;
		if (CurrentFrame > 11) CurrentFrame -= 11;
		entityBaseObj::getSprite()->objSprite().setTextureRect(sf::IntRect(226 * int(CurrentFrame), 227 * 2, 227, 227));
		if (t > 0.5) isAnimationInProcess = 0;
		break;
	};

	case 2:
	{

		float t = clock.getElapsedTime().asSeconds();
		CurrentFrame += 0.02 * t;
		if (CurrentFrame > 11) CurrentFrame -= 11;
		entityBaseObj::getSprite()->objSprite().setTextureRect(sf::IntRect(226 * int(CurrentFrame), 227 * 6, 227, 227));
		if (t > 0.4) isAnimationInProcess = 0;

		break;
	};
	case 3:
	{

		float t = clock.getElapsedTime().asSeconds();
		CurrentFrame += 0.03 * t;
		entityBaseObj::getSprite()->objSprite().setTextureRect(sf::IntRect(226 * int(CurrentFrame), 227 * 5, 227, 227));
		if (t > 0.9) isAnimationInProcess = 10;
		break;
	};

	case 4:
	{
		float t = clock.getElapsedTime().asSeconds();
		CurrentFrame += 0.04 * t;
		if (CurrentFrame > 11) CurrentFrame -= 11;
		entityBaseObj::getSprite()->objSprite().setTextureRect(sf::IntRect(226 * int(CurrentFrame), 227 * 4, 227, 227));
		if (t > 0.4) isAnimationInProcess = 0;
	};
	}

	if (blClock.getElapsedTime().asSeconds() > 0.3 && blood)
	{
		entityBaseObj::getSprite()->objSprite().setColor(sf::Color::White);
		blood = 0;
	}

	collision(world);
	interact(world, boySp, vec);

	if (fabs(getBody()->GetLinearVelocity().x) > 5) isSpeaking = 0;

	if (getBody()->GetLinearVelocity().x != 0 && onGround(world))
	{
		//std::cout << moveTime << std::endl;
		float moveTime = moveClock.getElapsedTime().asSeconds();

		if (moveClock.getElapsedTime().asSeconds() > 2.5)
		{

			moveClock.restart();
			step.play();
			yes = 1;
		}

	}
	else
	{
		step.stop();
		yes = 0;
	}

	animCloud();

}

sf::Text playerFinalObj::getText()
{
	return msgCloud::msgTxt;
}

sf::Sprite& playerFinalObj::getCloudSprite()
{
	return msgCloud::grObj::objSprite();
}