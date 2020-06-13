#pragma once
#include "Box2D\Box2D.h"
#include <ctime>
#include "objClass.h"
#include <functional>

#include <functional>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>


typedef std::vector<phStaticObj> tlList;
typedef std::vector<edgeObj> edgList;
typedef std::vector<std::vector <int>> vint;
typedef std::vector<NPC*> vecNPCpointers;
typedef std::vector<NPC> vecNPCs;
typedef std::vector<entityBaseObj> vecBox;
typedef std::vector<Enemy> vecEnemy;
typedef std::vector<bridgeObj> vecBridge;

phStaticObj createTile(tlList& ls, int TILE_SET_TYPE, int x, int y, b2World& world, phMainEntityConfig h)
{
	//phStaticObj(&world, h, 5),
	phStaticObj temp(&world, h, TILE_SET_TYPE);
	temp.setPos(y * 100 - 500, x * 100 + 600);

	ls.push_back(temp);

	return temp;
}
void createSlide(edgList& ls, int TILE_SET_TYPE, int x, int y, b2World& world, phMainEntityConfig h)
{
	int ti_down = 0;
	if(TILE_SET_TYPE < 18) ti_down = 50;
	edgeObj temp(world, h, sf::Vector2i(y * 100 / 2 - ti_down - 500 / 2, x * 100 / 2 + 250), TILE_SET_TYPE);
	ls.push_back(temp);
}
void createCrate(vecBox& lb, int x, int y, b2World& world, phMainEntityConfig h)
{
	entityBaseObj boxTemp(&world, h, 100, 100, 1, NULL, 0);
	boxTemp.setPos(y * 100 - 500, x * 100);
	lb.push_back(boxTemp);
}
void createEnemy(vecEnemy& lb, int x, int y, b2World* world, phMainEntityConfig h, grObj& EnSp)
{
	Enemy enemy(world, h, 75, 125, 22, &EnSp);

	enemy.setPos(y * 100 - 300, x * 100);
	enemy.setBoardesNPC(sf::Vector2i(y * 100 - 500, y * 100 - 100));
	lb.push_back(enemy);
}
NPC createNPC(vecNPCs& lb, int x, int y, b2World* world, phMainEntityConfig h, grObj& BouSp)
{
	NPC npc(world, h, 50, 100, 21, &BouSp);

	npc.setPos(y * 100 - 300, x * 100);
	npc.setBoardesNPC(sf::Vector2i(y * 100 - 500, y * 100 - 100));
	lb.push_back(npc);

	return npc;
}

void createBridge(vecBridge& vec, phStaticObj & A, phStaticObj& B, b2World* world, phMainEntityConfig h)
{
	vec.push_back(bridgeObj(world, A, B));
}

void levelSetUp(vint matrix, tlList& ls, edgList& le, vecBox& bl, vecEnemy& enL, vecBridge& brVec, vecNPCs& npcl, b2World& world, phMainEntityConfig h, grObj& EnSp, grObj& BoySp, vecNPCpointers& p)
{
	for (int i = 0; i < matrix.size(); ++i)
	{
		phStaticObj A, B;

		for (int j = 0; j < matrix[0].size(); ++j)
		{
			if (matrix[i][j] != 0)
			{
				if (matrix[i][j] == 1)
					createCrate(bl, i, j, world, h);
				else if (matrix[i][j] == 21)
					p.push_back(&createNPC(npcl, i, j, &world, h, BoySp));
				else if (matrix[i][j] == 22)
					createEnemy(enL, i, j, &world, h, EnSp);
				else if (matrix[i][j] != 1 && matrix[i][j] < 15)
					createTile(ls, matrix[i][j], i, j, world, h);
				else if (matrix[i][j] == 66)
					A = createTile(ls, 9, i, j, world, h);
				else if (matrix[i][j] == 99)
				{
					B = createTile(ls, 5, i, j, world, h);
					createBridge(brVec, A, B, &world, h);
				}
				
				else
				createSlide(le, matrix[i][j], i, j, world, h);
			}
		}
	}
};


int lv_0(sf::RenderWindow& window)
{
	
	//ephilexia - the end is near

	sf::Music ambient;
	ambient.setLoop(1);
	ambient.openFromFile("assets/sounds/ephilexia - the end is near.wav");
	ambient.setVolume(5);
	ambient.play();

	srand(std::time(NULL));

	sf::Texture tileSetsTexture;
	tileSetsTexture.loadFromFile("assets/environment/tiles.png");
	sf::Texture hpTex;
	hpTex.loadFromFile("assets/gui/health_gui_n.png");
	sf::Texture buttonsTex;
	buttonsTex.loadFromFile("assets/gui/m_buttons.png");
	
	///graphics_sprites
	grObj plSp("assets/entity/player_map.png", sf::Vector2i(0, 0), sf::Vector2i(227, 227));
	grObj boySp("assets/entity/boyMap.png", sf::Vector2i(0, 0), sf::Vector2i(227, 227));
	grObj enSp("assets/entity/enemy.png", sf::Vector2i(0, 0), sf::Vector2i(227, 227));

	sf::Texture bornTex;
	bornTex.loadFromFile("assets/entity/pl_born.png");
	bornTex.setSmooth(1);
	grObj born(bornTex, sf::Vector2i(1, 1), sf::Vector2i(320, 270));
	born.setScale(1.5, 1.5);
	born.setPosition(-300, 550);
	
	grObj bridge0(tileSetsTexture, sf::Vector2i(160, 0), sf::Vector2i(32, 11));
	bridge0.setScale(3.125, 3.125);
	grObj bridge1(tileSetsTexture, sf::Vector2i(160, 11), sf::Vector2i(32, 14));
	bridge1.setScale(3.125, 3.125);
	grObj bridge2(tileSetsTexture, sf::Vector2i(160, 25), sf::Vector2i(32, 10));
	bridge2.setScale(3.125, 3.125);
	grObj box(tileSetsTexture, sf::Vector2i(192, 0), sf::Vector2i(32, 32));
	box.setScale(3.125, 3.125);
	grObj stoneSp(tileSetsTexture, sf::Vector2i(224, 0), sf::Vector2i(18, 19));
	stoneSp.setScale(2, 2);

	///gui
	grObj guiHP(hpTex, sf::Vector2i(0, 0), sf::Vector2i(590, 192));
	grObj HP(hpTex, sf::Vector2i(5, 197), sf::Vector2i(422, 42));
	grObj AR(hpTex, sf::Vector2i(6, 252), sf::Vector2i(422, 42));
	grObj subsGr("assets/gui/subs.png", sf::Vector2i(0, 0), sf::Vector2i(480, 101));

	guiHP.setScale(0.75, 0.75);
	HP.setScale(0.75, 0.75);
	AR.setScale(0.75, 0.75);

	//buttons

	
	grObj retryA(buttonsTex, sf::Vector2i(0, 725), sf::Vector2i(251, 56));
	retryA.objSprite().setOrigin(251/2, 56/2);
	grObj backA(buttonsTex, sf::Vector2i(0, 610), sf::Vector2i(331, 53));
	backA.objSprite().setOrigin(331/2, 53/2);
	



	grObj tilesDirt[10] = 
	{
		//upper line
		grObj(tileSetsTexture, sf::Vector2i(0, 0), sf::Vector2i(32, 32)),
		grObj(tileSetsTexture, sf::Vector2i(32, 0), sf::Vector2i(32, 32)),
		grObj(tileSetsTexture, sf::Vector2i(64, 0), sf::Vector2i(32, 32)),
		grObj(tileSetsTexture, sf::Vector2i(96, 0), sf::Vector2i(32, 32)),
		grObj(tileSetsTexture, sf::Vector2i(128, 0), sf::Vector2i(32, 32)),
		//below line
		grObj(tileSetsTexture, sf::Vector2i(128, 32), sf::Vector2i(32, 32)),
		grObj(tileSetsTexture, sf::Vector2i(96, 32), sf::Vector2i(32, 32)),
		grObj(tileSetsTexture, sf::Vector2i(64, 32), sf::Vector2i(32, 32)),
		grObj(tileSetsTexture, sf::Vector2i(32, 32), sf::Vector2i(32, 32)),
		grObj(tileSetsTexture, sf::Vector2i(0, 32), sf::Vector2i(32, 32))


	};
	grObj tilesSlide[3] =
	{
		grObj(tileSetsTexture, sf::Vector2i(64, 64), sf::Vector2i(32, 32)),
		grObj(tileSetsTexture, sf::Vector2i(96, 64), sf::Vector2i(64, 32)),
		grObj(tileSetsTexture, sf::Vector2i(64, 96), sf::Vector2i(96, 32))
	};

	for(int i = 0; i < 10; ++i)
		tilesDirt[i].setScale(3.125, 3.125);
	for (int i = 0; i < 3; ++i)
		tilesSlide[i].setScale(3.125, 3.125);

	//clock
	sf::Clock clock, cl;
	

	//create world//box2d
	b2Vec2 gravity(0.0, GRAVITY);
	b2World world(gravity);
	
	float time;
	phMainEntityConfig h;
	//h.getFix().friction = 4;

	 
	

	/*
	Slides:
	{
		15 - one
		16 - two
		17 - three

		18 - one invert
		19 - two invert
		20 - three invert
	}
	Tiles:
	{
		5 corner	 6-8 top	9 corner
		14 corner	13-11 down	10 corner
	}
	bridge
	{
		66, 99
	}
	Entities:
	{
		22 - Enemy
		23 - projectaile
		21 - NPC



	}
	
	
	
	*/
	vecBox BoxesList;
	vecNPCpointers entityList;
	vecEnemy enemiesList;
	vecNPCs npcsList;

	tlList tlBlocks;
	edgList tlSlides;
	vecBridge tlBridge;

	vint lvl_matr;
	lvl_matr =
	{
		{	0, 0,	0,	0,	0,	0,	0, 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0, 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	 0, 0,},
		{	0,	0,	0,	0,	0,	0,	0, 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0, 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	 0, 0,},
		{	0,	0,	0,	0,	0,	0,	0, 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	5,	6,	7,	8,	6,	7,  8,	17,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	5,	6,	7,	8,	6,	7,  8,	9,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	21,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	5,	7,	8,	66, 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	99,	7,	8,	9,},
		{	0,	0,	0,	0,	0,	0,	0, 0,	0,	0,	0,	0,	0,	0,	5,	6,	7,	8,	6,	7,  8,	9,	14,	13,	12,	11,	13,	11,	12,	11, 12, 13, 17,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	14,	12,	11,	11,	12,	13,	11,	10,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	22,	0,	0,	0,	0,	0,	0,	0,	5,	7,	8,	6,	7,  8,	6,	7,	8,	6,	7,  8,	6,	7,	8,	6,	7,  8,	6,	7,	8,	6,	7,  8,	66,	0,	0,	0,	0,	0,	0,	0,	99,	7,	8,	9,	0,	0,	14,	13,	12,	10, 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	14,	13,	12,	10},
		{	5,	6,	7,	8,	6,	7,	8, 6,	7,	8,	6,	7,	8,	9,	14,	13,	12,	11,	13,	11,	12,	10,	0,	0,	11,	13,	13,	12,	11,	13,	11,	12,	11, 12, 13,	6,	7,	8,	6,	7,	8,	6,	7,	8,	6,	9,	14,	13,	12,	11,	13,	11,	12,	10,	5,	6,	7,	8,	6,	7,  8,	6,	7,	8,	6,	7,  8,	6,	7,	8,	6,	7,  8,	6,	7,	8,	6,	7,  8,	9,	14,	13,	12,	11,	13,	11,	12,	13,	12,	11,	13,	11,	12,	13,	12,	11,	13,	11,	12,	13,	12,	11,	13,	11,	10,	0,	0,	0,	0,	0,	0,	0,	14,	13,	13,	10,	0,	0,	14,	13,	12,	10, 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	14,	13,	12,	10}

	};


	
	
	levelSetUp(lvl_matr, tlBlocks, tlSlides, BoxesList, enemiesList, tlBridge, npcsList, world, h, enSp, boySp, entityList);

	
	
	playerFinalObj player(&world, h, &plSp);
	player.setPos(0, 900);


	sf::SoundBuffer bornBuf, buffer;
	buffer.loadFromFile("assets/sounds/button.wav");
	bornBuf.loadFromFile("assets/sounds/magic.wav");
	sf::Sound bornS, sound;

	sound.setBuffer(buffer);
	sound.setVolume(20);

	bornS.setBuffer(bornBuf);
	bornS.setVolume(10);

	backGroundParalax lv_1("assets/levels/1_Lb/", plSp.getPosition().x, 500);
	//paralax
	
	bool isPause = 0;
	grObj gui("assets/gui/gui.png", sf::Vector2i(0, 0), sf::Vector2i(120, 170));
	gui.objSprite().setOrigin(120/2, 170/2);
	grObj title("assets/gui/titles2.png");
	

	float CurrentFrame = 0;
	float curFr = 0;
	float y = 0;
	bool pressed2 = 0;

	sf::Sprite face;
	subs subTitles(&subsGr, 1);
	
	

	//float sizeH, sizeA;
	bool Boolborn = 0;
	bool timerGo = 0;
	

	while (window.isOpen())
	{

		window.clear();
		//EVENTS
		//Events Handler
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		//All the buttons
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			if (!pressed2)
			{
				isPause == 0 ? isPause = 1 : isPause = 0;
				sound.play();
				pressed2 = 1;
			}


		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && !Boolborn)
		{
			if (!pressed2)
			{
				bornS.play();
				y = 1;
				pressed2 = 1;
				cl.restart();
				timerGo = 1;
			}
		}
		else pressed2 = 0;

		

		if (player.getHP() < 0) isPause = 1;

	if(!isPause)
	{
		///clock////
		time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		///phicis step////
		world.Step(1 / 60.f, 8, 3);


		///camera & player////
		window.setView(player.getCamera());
		player.CamUpDate();

		//capture the camera to player
		player.cam(window);
		player.anim(time, world, boySp, entityList);
		subTitles.update(&plSp);
		lv_1[0].objSprite().setPosition(plSp.objSprite().getPosition().x, plSp.objSprite().getPosition().y - 400); ///phon
		lv_1[1].objSprite().setPosition(plSp.objSprite().getPosition().x, 500); //gori

		guiHP.objSprite().setPosition(plSp.objSprite().getPosition().x - 900, plSp.objSprite().getPosition().y - 800);
		HP.objSprite().setPosition(plSp.objSprite().getPosition().x - 785, plSp.objSprite().getPosition().y - 760);
		AR.objSprite().setPosition(plSp.objSprite().getPosition().x - 785, plSp.objSprite().getPosition().y - 700);

		face = plSp.objSprite();
		face.setTextureRect(sf::IntRect(player.getAnX(), player.getAnY(), 154, 145));
		face.setScale(1, 1);
		face.setPosition(plSp.objSprite().getPosition().x - 830, plSp.objSprite().getPosition().y - 700);

		

		//smartMoving
		std::for_each(enemiesList.begin(), enemiesList.end(), std::mem_fun_ref(&Enemy::cycleMovomentNPC));
		std::for_each(enemiesList.begin(), enemiesList.end(), [&](Enemy& en) {en.anim(time, world, h); });

		std::for_each(npcsList.begin(), npcsList.end(), [&](NPC& en) {en.cycleMovomentNPC(world); });
		std::for_each(npcsList.begin(), npcsList.end(), [&](NPC& en) {en.anim(time, world); });
		//std::for_each(enemiesList.begin(), enemiesList.end(), [&](Enemy& en) {std::cout << (int)en.getBody()->GetUserData() << std::endl; });
		
		//firstOne.cycleMovomentNPC(world);
		//firstOne.anim(time, world);


		//paralax
		lv_1.anim(plSp, player.getBody()->GetLinearVelocity().x);
		if (cl.getElapsedTime().asSeconds() > 2.7 && !Boolborn && timerGo)
		{
			Boolborn = 1;
			player.setPos(0, 800);
			player.getBody()->ApplyLinearImpulse(b2Vec2(0, -IMP * 8.5), player.getBody()->GetWorldCenter(), 1);

		}
		

	}

		///DRAW
		window.draw(lv_1[0]);
		window.draw(lv_1[1]);
		window.draw(lv_1[3]);
		window.draw(lv_1[2]);

		for (b2Body* BodyIterator = world.GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
		{


			if (BodyIterator->GetType() == b2_staticBody)
				switch ((int)BodyIterator->GetUserData())
				{
				case 5:
				{
					tilesDirt[0].objSprite().setOrigin(32 / 2, 32 / 2);
					tilesDirt[0].objSprite().setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);

					//tilesDirt[0].objSprite().setRotation(BodyIterator->GetAngle() * 180 / b2_pi);


					window.draw(tilesDirt[0].objSprite());
					break;
				};
				case 6:
				{
					tilesDirt[1].objSprite().setOrigin(32 / 2, 32 / 2);
					tilesDirt[1].objSprite().setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);

					//tilesDirt[1].objSprite().setRotation(BodyIterator->GetAngle() * 180 / b2_pi);


					window.draw(tilesDirt[1].objSprite());
					break;
				};
				case 7:
				{
					tilesDirt[2].objSprite().setOrigin(32 / 2, 32 / 2);
					tilesDirt[2].objSprite().setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);

					//tilesDirt[2].objSprite().setRotation(BodyIterator->GetAngle() * 180 / b2_pi);


					window.draw(tilesDirt[2].objSprite());

					break;
				};
				case 8:
				{
					tilesDirt[3].objSprite().setOrigin(32 / 2, 32 / 2);
					tilesDirt[3].objSprite().setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);

					//tilesDirt[3].objSprite().setRotation(BodyIterator->GetAngle() * 180 / b2_pi);


					window.draw(tilesDirt[3].objSprite());

					break;
				};
				case 9:
				{
					tilesDirt[4].objSprite().setOrigin(32 / 2, 32 / 2);
					tilesDirt[4].objSprite().setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);

					//tilesDirt[4].objSprite().setRotation(BodyIterator->GetAngle() * 180 / b2_pi);


					window.draw(tilesDirt[4].objSprite());

					break;
				};
				case 10:
				{
					tilesDirt[5].objSprite().setOrigin(32 / 2, 32 / 2);
					tilesDirt[5].objSprite().setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);

					//tilesDirt[0].objSprite().setRotation(BodyIterator->GetAngle() * 180 / b2_pi);


					window.draw(tilesDirt[5].objSprite());
					break;
				};
				case 11:
				{
					tilesDirt[6].objSprite().setOrigin(32 / 2, 32 / 2);
					tilesDirt[6].objSprite().setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);

					//tilesDirt[1].objSprite().setRotation(BodyIterator->GetAngle() * 180 / b2_pi);


					window.draw(tilesDirt[6].objSprite());
					break;
				};
				case 12:
				{
					tilesDirt[7].objSprite().setOrigin(32 / 2, 32 / 2);
					tilesDirt[7].objSprite().setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);

					//tilesDirt[2].objSprite().setRotation(BodyIterator->GetAngle() * 180 / b2_pi);


					window.draw(tilesDirt[7].objSprite());

					break;
				};
				case 13:
				{
					tilesDirt[8].objSprite().setOrigin(32 / 2, 32 / 2);
					tilesDirt[8].objSprite().setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);

					//tilesDirt[3].objSprite().setRotation(BodyIterator->GetAngle() * 180 / b2_pi);


					window.draw(tilesDirt[8].objSprite());

					break;
				};
				case 14:
				{
					tilesDirt[9].objSprite().setOrigin(32 / 2, 32 / 2);
					tilesDirt[9].objSprite().setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);

					//tilesDirt[4].objSprite().setRotation(BodyIterator->GetAngle() * 180 / b2_pi);


					window.draw(tilesDirt[9].objSprite());

					break;
				};

				case 15:
				{
					


					tilesSlide[0].setScale(3.125, 3.125);
					tilesSlide[0].objSprite().setPosition(BodyIterator->GetPosition().x * SCALE * 2, BodyIterator->GetPosition().y * SCALE * 2);


					window.draw(tilesSlide[0].objSprite());


					break;
				}
				case 16:
				{
					


					tilesSlide[1].setScale(3.125, 3.125);
					tilesSlide[1].objSprite().setPosition(BodyIterator->GetPosition().x * SCALE * 2, BodyIterator->GetPosition().y * SCALE * 2);


					window.draw(tilesSlide[1].objSprite());
					break;
				}
				case 17:
				{
					

					tilesSlide[2].setScale(3.125, 3.125);
					tilesSlide[2].objSprite().setPosition(BodyIterator->GetPosition().x * SCALE * 2, BodyIterator->GetPosition().y * SCALE * 2);


					window.draw(tilesSlide[2].objSprite());
					break;
				}
				case 18:
				{
					

					tilesSlide[0].setScale(-3.125, 3.125);
					tilesSlide[0].objSprite().setPosition(BodyIterator->GetPosition().x * SCALE * 2, BodyIterator->GetPosition().y * SCALE * 2);


					window.draw(tilesSlide[0].objSprite());



					break;
				}
				case 19:
				{
					
					tilesSlide[1].setScale(-3.125, 3.125);
					tilesSlide[1].objSprite().setPosition(BodyIterator->GetPosition().x * SCALE * 2, BodyIterator->GetPosition().y * SCALE * 2);


					window.draw(tilesSlide[1].objSprite());
					break;
				}
				case 20:
				{
				

					tilesSlide[2].setScale(-3.125, 3.125);
					tilesSlide[2].objSprite().setPosition(BodyIterator->GetPosition().x * SCALE * 2, BodyIterator->GetPosition().y * SCALE * 2);


					window.draw(tilesSlide[2].objSprite());
					break;
				}



				}

			if ((BodyIterator->GetType() == b2_dynamicBody))
				switch ((int)BodyIterator->GetUserData())
				{
				case 1:
				{
					box.objSprite().setOrigin(32 / 2, 32 / 2);
					box.objSprite().setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);

					box.objSprite().setRotation(BodyIterator->GetAngle() * 180 / b2_pi);


					window.draw(box.objSprite());
					break;
				};
				case 0:
				{
					
					plSp.objSprite().setOrigin(227 / 2, 227 / 2 + 10);
					plSp.objSprite().setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);

					plSp.objSprite().setRotation(BodyIterator->GetAngle() * 180 / b2_pi);


					if(Boolborn)window.draw(plSp.objSprite());

					player.getDebugSprite().setOrigin(50 / 2, 125 / 2);
					player.getDebugSprite().setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);

					player.getDebugSprite().setRotation(BodyIterator->GetAngle() * 180 / b2_pi);


					
					break;
				};
				case 2:
				{
					bridge0.objSprite().setOrigin(32 / 2, 7 / 2);
					bridge0.setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);

					bridge0.objSprite().setRotation(BodyIterator->GetAngle() * 180 / b2_pi);


					window.draw(bridge0.objSprite());


					break;
				};
				case 3:
				{
					bridge1.objSprite().setOrigin(32 / 2, 7 / 2);
					bridge1.setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);

					bridge1.objSprite().setRotation(BodyIterator->GetAngle() * 180 / b2_pi);


					window.draw(bridge1.objSprite());

					break;
				};
				case 4:
				{
					bridge2.objSprite().setOrigin(32 / 2, 7 / 2);
					bridge2.setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);

					bridge2.objSprite().setRotation(BodyIterator->GetAngle() * 180 / b2_pi);


					window.draw(bridge2.objSprite());

					break;
				};
				case 21:
				{

					//boySp.setScale(0.75, 0.75);

					boySp.objSprite().setOrigin(227 / 2, 227 / 2);
					boySp.objSprite().setPosition(BodyIterator->GetPosition().x* SCALE, BodyIterator->GetPosition().y* SCALE);

					boySp.objSprite().setRotation(BodyIterator->GetAngle() * 180 / b2_pi);


					window.draw(boySp.objSprite());

					
					break;
				}
				case 22:
				{

					enSp.objSprite().setOrigin(227 / 2, 227 / 2 + 10);
					enSp.objSprite().setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);

					enSp.objSprite().setRotation(BodyIterator->GetAngle() * 180 / b2_pi);



					window.draw(enSp.objSprite());

					
					
					break;
				}
				case 23:
				{
					

					stoneSp.objSprite().setOrigin(18.0 / 2, 19.0 / 2);

					stoneSp.objSprite().setPosition(BodyIterator->GetPosition().x * SCALE, BodyIterator->GetPosition().y * SCALE);

					stoneSp.objSprite().setRotation(BodyIterator->GetAngle() * 180 / b2_pi);



					window.draw(stoneSp.objSprite());


					break;
				}
				}

		}


		if (isPause)
		{

			if (!player.isAlive() && CurrentFrame <= 14)
			{
				CurrentFrame += 0.01 * time;
				plSp.objSprite().setTextureRect(sf::IntRect(226 * int(CurrentFrame), 227 * 5, 227, 227));
			}


			

			////////////////
			player.isAlive() ? title.setIntRec(sf::Vector2i(0, 82), sf::Vector2i(249, 56)) : title.setIntRec(sf::Vector2i(0, 0), sf::Vector2i(365, 74));
			player.isAlive() ? title.objSprite().setOrigin(249 / 2, 56 / 2) : title.objSprite().setOrigin(365 / 2, 74 / 2);
			title.setScale(1.3, 1.3);


			gui.objSprite().setPosition(plSp.getPosition().x, plSp.getPosition().y - 300);
			gui.setScale(3.7, 3.7);
			title.setPosition(gui.objSprite().getPosition().x, gui.objSprite().getPosition().y - 350);

			retryA.setPosition(gui.objSprite().getPosition().x, gui.objSprite().getPosition().y - 200);
			backA.setPosition(gui.objSprite().getPosition().x, gui.objSprite().getPosition().y + 180);
			
		
			if (retryA.objSprite().getGlobalBounds().contains( window.mapPixelToCoords(sf::Vector2i(sf::Mouse::getPosition().x , sf::Mouse::getPosition().y - 50) )))
			{
				
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					
					sound.play();
					return 1;
				}
				

				retryA.setIntRec(sf::Vector2i(0, 782), sf::Vector2i(254, 62));
			}
			else retryA.setIntRec(sf::Vector2i(0, 725), sf::Vector2i(251, 55));

			if (backA.objSprite().getGlobalBounds().contains(window.mapPixelToCoords(sf::Vector2i(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y - 20))))
			{

				

				backA.setIntRec(sf::Vector2i(0, 666), sf::Vector2i(333, 56));

				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					
						sound.play();
						window.setView(window.getDefaultView());
						return 0;
					
				}
				
			}
			else backA.setIntRec(sf::Vector2i(0, 610), sf::Vector2i(331, 53));



			
		}

		///overlay

		
		HP.setIntRec(sf::Vector2i(5, 197), sf::Vector2i(4.22 * player.getHP(), 42));
		AR.setIntRec(sf::Vector2i(6, 252), sf::Vector2i(4.22 * player.getArmor(), 42));

		///born
		


		if (y < 7)
		{
			/////
			curFr += 0.009 * time;
			if (curFr > 5)
			{
				curFr -= 5;
				if (y >= 1) ++y;
			}
		}
		
		born.objSprite().setTextureRect(sf::IntRect(321 * int(curFr), y * 271, 319, 269));
		


		window.draw(guiHP);
		window.draw(HP);
		window.draw(AR);
		window.draw(face);
		if(!Boolborn) window.draw(born);
		window.draw(subTitles);
		window.draw(subTitles.getTxt());

		if (player.isSpeaking)
		{
			window.draw(player.getCloudSprite());
			window.draw(player.getText());
		}

		if (isPause)
		{
			window.draw(gui);
			window.draw(title);

			window.draw(retryA);
			window.draw(backA);
		}

		window.display();

	}

	return 0;
}
