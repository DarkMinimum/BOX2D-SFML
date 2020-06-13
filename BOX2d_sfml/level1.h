//#pragma once
//#include "Box2D\Box2D.h"
//#include "classList.h"
//#include "SFML/Graphics.hpp"
//#include "objClass.h"
//
//#define TILES 25
//
//void lv_1(sf::RenderWindow& window)
//{
//	
//	//clock
//	sf::Clock clock;
//	float CurrentFrame = 0;
//
//	//create world//box2d
//	b2Vec2 gravity(0.0, GRAVITY);
//	b2World world(gravity);
//
//	Player player(100, "assets/entity/player_map.png", &world);
//	Entity entity(100, 100, 100, 800, 100, "assets/environment/objects.png", &world, 0, 0, 128, 128, 1, 0.5f, 10.0f, 0);
//	
//	
//	
//	//player.getBody()->GetPosition();
//
//
//	backGround lv_1("assets/levels/1_Lb/", player.getBody()->GetPosition().x * SCALE);
//
//	////preinizialization
//	int pos;
//	int vec;
//	float time;
//	bool onGround;
//	//paralax
//	TS* current, * ghost;
//
//	////////
//	const int ver = 8;
//
//	sf::Vertex line[ver] =
//	{
//	 sf::Vertex(sf::Vector2f(-20.0f * SCALE, 0.0f)),
//	 sf::Vertex(sf::Vector2f(20.0f * SCALE, 0.0f)),
//	 sf::Vertex(sf::Vector2f(-33.3f * SCALE, 30 * SCALE)),
//	 sf::Vertex(sf::Vector2f(-33.3f * SCALE, 0.0f)),
//	 //slide
//		  sf::Vertex(sf::Vector2f(120.0f * SCALE, 17.0f * SCALE)),
//		  sf::Vertex(sf::Vector2f(168.0f * SCALE, 30.0f * SCALE)),
//
//		  sf::Vertex(sf::Vector2f(168.0f * SCALE, 30.0f * SCALE)),
//		  sf::Vertex(sf::Vector2f(168.0f * SCALE, 50.0f * SCALE)),
//
//	};
//
//	for (int i = 0; i < ver; ++i)
//		line[i].color = sf::Color::Red;
//
//
//
//	b2BodyDef bd;
//	b2Body* ground = world.CreateBody(&bd);
//
//	b2EdgeShape shape;
//
//	b2FixtureDef fd;
//	fd.shape = &shape;
//	fd.density = 0.0f;
//	fd.friction = 0.6f;
//	//
//	//shape.Set(b2Vec2(-20.0f, 0.0f), b2Vec2(20.0f, 0.0f));
//	//ground->CreateFixture(&fd);
//
//	//shape.Set(b2Vec2(-33, 30.0f), b2Vec2(-33, 0.0f));
//	//ground->CreateFixture(&fd);
//
//	//slide
//	//shape.Set(b2Vec2(120.0f, 17.0f), b2Vec2(168.0f, 30.0f));
//	//ground->CreateFixture(&fd);
//
//	//shape.Set(b2Vec2(168.0f, 30.0f), b2Vec2(168.0f, 50.0f));
//	//ground->CreateFixture(&fd);
//
//
//	//collision
//	b2PolygonShape Shape;
//
//	Wall pl_1[TILES] = {
//					 Wall(0, &world, b2Vec2(-METR * 2, METR * 2.5), bd, Shape),
//					 Wall(0,&world, b2Vec2(-METR, METR * 2.5), bd, Shape),
//					 Wall(0,&world, b2Vec2(0, METR * 2.5), bd, Shape),
//					 Wall(0,&world, b2Vec2(METR, METR * 2.5), bd, Shape),
//					 Wall(0,&world, b2Vec2(METR * 2, METR * 2.5), bd, Shape),
//					 Wall(0,&world, b2Vec2(METR * 3, METR * 2.5), bd, Shape),
//					 Wall(0,&world, b2Vec2(METR * 4, METR * 2.5), bd, Shape),
//					 Wall(0,&world, b2Vec2(METR * 5, METR * 2.5), bd, Shape),
//					 Wall(1,&world, b2Vec2(METR * 3, METR * 2.5), bd, Shape),
//					 Wall(1,&world, b2Vec2(METR * 4, METR * 2.5), bd, Shape),
//					 Wall(1,&world, b2Vec2(METR * 5, METR * 2.5), bd, Shape),
//
//					 Wall(0,&world, b2Vec2(METR * 6, METR * 2.5), bd, Shape),
//					 Wall(0,&world, b2Vec2(METR * 7, METR * 2.5), bd, Shape),
//					 Wall(1,&world, b2Vec2(METR * 6, METR * 2.5), bd, Shape),
//					 Wall(1,&world, b2Vec2(METR * 7, METR * 2.5), bd, Shape),
//
//
//					 Wall(0,&world, b2Vec2(METR * 8, METR * 2.5), bd, Shape),
//					 Wall(0,&world, b2Vec2(METR * 9, METR * 2.5), bd, Shape),
//					 Wall(0,&world, b2Vec2(METR * 10, METR * 2.5), bd, Shape),
//					 Wall(0,&world, b2Vec2(METR * 11, METR * 2.5), bd, Shape),
//					 Wall(0,&world, b2Vec2(METR * 12, METR * 2.5), bd, Shape),
//
//
//					 Wall(0,&world, b2Vec2(METR * 13, METR * 2.5), bd, Shape),
//					 Wall(0,&world, b2Vec2(METR * 14, METR * 2.5), bd, Shape),
//					 Wall(0,&world, b2Vec2(METR * 15, METR * 2.5), bd, Shape),
//					 Wall(0,&world, b2Vec2(METR * 16, METR * 2.5), bd, Shape),
//					 Wall(0,&world, b2Vec2(METR * 17, METR * 2.5), bd, Shape),
//
//
//	};
//
//	//0 - 22
//	TS dec_list[DECOR] =
//	{
//		TS(1, 22, 200, 870, 1.5),
//		TS(1, 0, 100, 600, 2),
//		TS(0, 22, -900, 870, 1.5),
//		TS(1, 22, METR * 3, METR * 2 - 325, 1.5),
//		TS(0, 18, METR * 3, METR * 2 - 325, 1.5),
//		TS(1, 1, METR * 3 + 300, METR * 2 - 700, 2.5),
//		TS(0, 19, METR * 3 + 500, METR * 2 - 325, 1.5),
//		TS(1, 14, METR * 3 + 1000, METR * 2 - 325, 1.5),
//		TS(1, 16, METR * 3 + 1300, METR - 60, 1.5),
//		TS(0, 16, METR * 3 + 1700, METR - 60, 1.5),
//		TS(0, 3, METR * 3 + 1700, METR - 350, 2.5),
//
//	};
//
//	//TS slide("assets/environment/t_d3.png", 0, 0, 780, 440);
//	//slide.setScale(1.85, 1.85);
//	//slide.setPos(METR * 7.5, METR * 1.05);
//
//
//	while (window.isOpen())
//	{
//		///clock////
//		time = clock.getElapsedTime().asMicroseconds();
//		clock.restart();
//		time = time / 800;
//		///phicis step////
//		world.Step(1 / 60.f, 8, 3);
//
//		///camera & player////
//		window.setView(player.getCamera());
//		player.CamUpDate();
//
//		lv_1.getLayer(0).setPos(player.getSprite().getPosition().x, player.getSprite().getPosition().y - 400); ///phon
//		lv_1.getLayer(1).setPos(player.getSprite().getPosition().x, 500); //gori
//
//		window.clear();
//
//
//		//Events Handler
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//
//
//		/////check if onGround//////
//		onGround = false;
//		///pos medium
//		b2Vec2 pos1 = player.getBody()->GetPosition();
//		pos1.y += ((100.f / 2) / SCALE + 0.1);
//		b2Vec2 pos2 = pos1;
//		pos1.x += 1.65;
//		pos2.x -= 1.65;
//
//		for (b2Body* it = world.GetBodyList(); it != 0; it = it->GetNext())
//			for (b2Fixture* f = it->GetFixtureList(); f != 0; f = f->GetNext())
//				if (f->TestPoint(pos1) || f->TestPoint(pos2))  onGround = true;
//		///////end////////
//
//		//camera
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
//		{
//			player.ZoomChange(1.01f);
//
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
//		{
//			player.ZoomChange(0.99f);
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Divide))
//		{
//			std::cout << "lox\n";
//			player.getCamera() = (window.getDefaultView());
//			player.getCamera().setCenter(player.getSprite().getPosition().x, player.getSprite().getPosition().y);
//		}
//
//
//		//movement
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
//		{
//			CurrentFrame += 0.01 * time;
//			if (CurrentFrame > 11) CurrentFrame -= 11;
//			player.getSprite().setTextureRect(sf::IntRect(226 * int(CurrentFrame), 227 * 2, 227, 227));
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
//		{
//			player.getBody()->SetTransform(b2Vec2(2000 / SCALE, 0), 0);
//			std::cout << "R pressed...\n";
//
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && onGround)
//		{
//
//			CurrentFrame += 0.019 * time;
//			if (CurrentFrame > 12) CurrentFrame -= 12;
//			player.getSprite().setTextureRect(sf::IntRect(226 * int(CurrentFrame), 227, 227, 227));
//			player.getSprite().setScale(1.0f, 1.0f);
//
//
//			if (player.getBody()->GetLinearVelocityFromLocalPoint(player.getBody()->GetPosition()).x < 25.0f)
//				player.getBody()->ApplyLinearImpulse(b2Vec2(20, 0), player.getBody()->GetWorldCenter(), 1);
//
//
//
//			//std::cout << player.getBody()->GetLinearVelocityFromLocalPoint(player.getBody()->GetPosition()).x << "\n";
//
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && onGround)
//		{
//			player.getSprite().setScale(-1.0f, 1.0f);
//
//			CurrentFrame += 0.019 * time;
//			if (CurrentFrame > 12) CurrentFrame -= 12;
//			player.getSprite().setTextureRect(sf::IntRect(226 * int(CurrentFrame), 227, 227, 227));
//
//			if (player.getBody()->GetLinearVelocityFromLocalPoint(player.getBody()->GetPosition()).x > -25.0f)
//				player.getBody()->ApplyLinearImpulse(b2Vec2(-20, 0), player.getBody()->GetWorldCenter(), 1);
//
//			//std::cout << player.getBody()->GetLinearVelocityFromLocalPoint(player.getBody()->GetPosition()).x << "\n";
//
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
//		{
//			/*CurrentFrame += 0.013 * time;
//			if (CurrentFrame > 6) CurrentFrame -= 6;
//			player.getSprite().setTextureRect(sf::IntRect(226 * int(CurrentFrame), 227 * 7, 227, 227));*/
//
//			if (onGround) player.getBody()->ApplyLinearImpulse(b2Vec2(0, -280), player.getBody()->GetWorldCenter(), 1);
//		}
//		if (!onGround && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//		{
//			player.getSprite().setScale(1.0f, 1.0f);
//			CurrentFrame += 0.0075 * time;
//			if (CurrentFrame > 6) CurrentFrame -= 6;
//			player.getSprite().setTextureRect(sf::IntRect((226 * 8) + (226 * int(CurrentFrame)), 227 * 3, 227, 227));
//
//			if (player.getBody()->GetLinearVelocityFromLocalPoint(player.getBody()->GetPosition()).x < 7.0f)
//				player.getBody()->ApplyLinearImpulse(b2Vec2(5, 0), player.getBody()->GetWorldCenter(), 1);
//		}
//		if (!onGround && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//		{
//			player.getSprite().setScale(-1.0f, 1.0f);
//			CurrentFrame += 0.0075 * time;
//			if (CurrentFrame > 6) CurrentFrame -= 6;
//			player.getSprite().setTextureRect(sf::IntRect((226 * 8) + (226 * int(CurrentFrame)), 227 * 3, 227, 227));
//
//			if (player.getBody()->GetLinearVelocityFromLocalPoint(player.getBody()->GetPosition()).x > -7.0f)
//				player.getBody()->ApplyLinearImpulse(b2Vec2(-5, 0), player.getBody()->GetWorldCenter(), 1);
//		}
//		if (!onGround)
//		{
//			CurrentFrame += 0.0075 * time;
//			if (CurrentFrame > 6) CurrentFrame -= 6;
//			player.getSprite().setTextureRect(sf::IntRect((226 * 8) + (226 * int(CurrentFrame)), 227 * 3, 227, 227));
//		}
//		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::E) && onGround)
//		{
//			CurrentFrame += 0.009 * time;
//			if (CurrentFrame > 18) CurrentFrame -= 18;
//			player.getSprite().setTextureRect(sf::IntRect(226 * int(CurrentFrame), 0, 227, 227));
//
//		}
//		////system
//		
//
//		///example of borning///
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
//		{
//			CurrentFrame += 0.0013 * time;
//			if (CurrentFrame > 18) CurrentFrame -= 18;
//			player.getSprite().setTextureRect(sf::IntRect(226 * int(CurrentFrame), 2037, 227, 227));
//
//		}
//
//		/*//example of sliding//
//		if (player.getSprite().getPosition().x > 120.0f * SCALE && player.getSprite().getPosition().x < 168.0f * SCALE)
//		{
//			CurrentFrame += 0.0075 * time;
//			if (CurrentFrame > 6) CurrentFrame -= 6;
//			player.getSprite().setTextureRect(sf::IntRect(226 * int(CurrentFrame), 227 * 3, 227, 227));
//
//			player.getBody()->ApplyLinearImpulse(b2Vec2(2, 0), player.getBody()->GetWorldCenter(), 1);
//		}*/
//
//
//
//		////background/////
//
//		
//	
//		//dis(player.getBody()->GetPosition().x* SCALE, lv_1.getLayer(2).getSprite().getPosition().x) < dis(player.getBody()->GetPosition().x* SCALE, lv_1.getLayer(3).getSprite().getPosition().x) ? current = &lv_1.getLayer(2) : current = &lv_1.getLayer(3);
//
//		float firstPoint = dis(player.getBody()->GetPosition().x * SCALE, lv_1.getLayer(2).getSprite().getPosition().x);
//		float secondPoint = dis(player.getBody()->GetPosition().x * SCALE, lv_1.getLayer(3).getSprite().getPosition().x);
//		vec = player.getBody()->GetLinearVelocity().x;
//
//
//		if (vec > 0)
//		{
//			///here
//			lv_1.setPosX(2, vec / 10);
//			lv_1.setPosX(3, vec / 10);
//
//		}
//		if (vec < 0)
//		{
//			///here
//			lv_1.setPosX(2, vec / 10);
//			lv_1.setPosX(3, vec / 10);
//
//		}
//
//		if (firstPoint < secondPoint)
//		{
//			current = &lv_1.getLayer(2);
//			ghost = &lv_1.getLayer(3);
//		}
//		else
//		{
//			current = &lv_1.getLayer(3);
//			ghost = &lv_1.getLayer(2);
//		}
//
//		if (dis(player.getSprite().getPosition().x, current->getSprite().getPosition().x) <= 10.0)
//		{
//			if (vec > 0)
//			{
//
//				ghost->setPos(current->getSprite().getPosition().x + 1920, 500);
//				
//			}
//			if (vec < 0)
//			{
//				ghost->setPos(current->getSprite().getPosition().x - 1920, 500);
//				
//			}
//
//		}
//
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
//		{
//			std::cout << "/////////////////\n";
//			//std::cout << "player X:" << (int)player.getSprite().getPosition().x << std::endl;
//			//std::cout << "player Y:" << player.getSprite().getPosition().y << std::endl;
//			std::cout << "dadadadya\n" << player.getSprite().getPosition().x << '\n' << player.getBody()->GetPosition().x * SCALE << '\n' << current->getSprite().getPosition().x << '\n' << '\n';
//
//
//			std::cout << "Player Screen is:" << (int)(player.getSprite().getPosition().x / 1440) << "\n";
//			std::cout << "/////////////////\n";
//
//
//		}
//		
//		
//
//		//pos = player.getBody()->GetPosition().x * SCALE;
//		//vec = player.getBody()->GetLinearVelocity().x;
//
//
//		//float firstP = distance(pos, lv_1.getLayer(2).getSprite().getPosition().x);
//		//float secondP = distance(pos, lv_1.getLayer(3).getSprite().getPosition().x);
//
//
//		///take closest pointer
//		/*if (firstP < secondP)
//		{
//			current = &lv_1.getLayer(2);
//			ghost = &lv_1.getLayer(3);
//		}
//		else
//		{
//			current = &lv_1.getLayer(3);
//			ghost = &lv_1.getLayer(2);
//		}
//
//		if (distance(pos, current->getSprite().getPosition().x) < 10)
//		{
//			if (vec > 0)
//			{
//
//				ghost->setPos(current->getSprite().getPosition().x + 1920 * 1.5, 250);
//				std::cout << "----->\t" << std::endl;
//			}
//			if (vec < 0)
//			{
//				ghost->setPos(current->getSprite().getPosition().x - 1920 *1.5, 250);
//				std::cout << "<-----\t" << std::endl;
//			}
//
//		}
//
//
//		////paralax_scrolling
//
//		if (vec > 0)
//		{
//			///here
//			lv_1.setPosX(2, vec / 10);
//			lv_1.setPosX(3, vec / 10);
//
//		}
//		if (vec < 0)
//		{
//			///here
//			lv_1.setPosX(2, vec / 10);
//			lv_1.setPosX(3, vec / 10);
//
//		}*/
//
//
//		/////sound////
//
//		/*for (int i = 0; i < DECOR; ++i)
//			if (dec_list[i].getLayer() == 0)
//				window.draw(dec_list[i].getSprite());*/
//
//
//
//		window.draw(lv_1.getLayer(0).getSprite()); //phon
//		window.draw(lv_1.getLayer(1).getSprite()); // gori
//		window.draw(lv_1.getLayer(3).getSprite());
//		window.draw(lv_1.getLayer(2).getSprite());
//
//
//		//phisic draw//////
//		for (b2Body* BodyIterator = world.GetBodyList(); BodyIterator != 0; BodyIterator = BodyIterator->GetNext())
//		{
//			if (BodyIterator->GetType() == b2_dynamicBody && (int)BodyIterator->GetUserData() == 0)
//			{
//
//
//
//				player.getSprite().setOrigin(113.5, 113.5 + 23);
//				player.getShape().setOrigin(50, 50);
//
//
//
//				player.getSprite().setPosition(BodyIterator->GetPosition().x * 30, BodyIterator->GetPosition().y * 30);
//				player.getShape().setPosition(BodyIterator->GetPosition().x * 30, BodyIterator->GetPosition().y * 30);
//
//
//
//
//
//				player.getSprite().setRotation(BodyIterator->GetAngle() * 180 / b2_pi);
//				player.getShape().setRotation(BodyIterator->GetAngle() * 180 / b2_pi);
//
//
//
//
//				//window.draw(player.getShape());
//				window.draw(player.getSprite());
//
//
//
//
//			}
//			else if (BodyIterator->GetType() == b2_dynamicBody && (int)BodyIterator->GetUserData() == 1)
//			{
//
//				entity.getShape().setOrigin(50, 50);
//				entity.getSprite().setOrigin(64, 64);
//				entity.setScale(0.8f, 0.8f);
//
//
//
//
//				entity.getShape().setPosition(BodyIterator->GetPosition().x * 30, BodyIterator->GetPosition().y * 30);
//				entity.getSprite().setPosition(BodyIterator->GetPosition().x * 30, BodyIterator->GetPosition().y * 30);
//
//
//
//
//
//
//				entity.getShape().setRotation(BodyIterator->GetAngle() * 180 / b2_pi);
//				entity.getSprite().setRotation(BodyIterator->GetAngle() * 180 / b2_pi);
//
//
//
//				window.draw(entity.getShape());
//				window.draw(entity.getSprite());
//
//			}
//			
//
//		}
//
//		//window.draw(wall0.getShape());
//		//window.draw(wall1.getShape());
//		//window.draw(wall2.getShape());
//		//window.draw(wall3.getShape());
//		//window.draw(wall4.getShape());
//		//window.draw(wall5.getShape());
//
//		//window.draw(line, ver, sf::Lines);
//		//window.draw(slide.getSprite());
//
//		//window.draw(wall_1.getTile());
//		//window.draw(wall_2.getTile());
//		//window.draw(wall_3.getTile());
//
//		
//
//		/*for (int i = 0; i < DECOR; ++i)
//			if (dec_list[i].getLayer() == 1)
//				window.draw(dec_list[i].getSprite());*/
//
//
//		for (int i = 0; i < TILES; ++i)
//			window.draw(pl_1[i].getTile());
//
//
//
//
//		window.display();
//
//	}
//}