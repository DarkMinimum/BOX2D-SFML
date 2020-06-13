#pragma once
#include "SFML/Graphics.hpp"
//#include "classList.h"
#include <windows.h>
#include <shellapi.h>
#include <SFML/Audio.hpp>
#include "objClass.h"

#include "level0r.h"

void menu(sf::RenderWindow& window) {

	sf::Music main_menu;
	main_menu.setLoop(1);
	main_menu.openFromFile("assets/sounds/m_menu.wav");
	main_menu.setVolume(20);
	main_menu.play();
	
	bool isMenu = 1;
	int menuNum = 0;
	float x, y;
	x = 1400;
	y = 400;

	sf::SoundBuffer buffer;
	// load something into the sound buffer...
	buffer.loadFromFile("assets/sounds/button.wav");
	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.setVolume(20);
	

	float c = 0.0007;
	const double d = 0.035;
	const double n = 0.07;

	float CurrentFrame = 0;
	
	srand(time(NULL));
	int a = rand() % 3;

	bool AboutAdd = 0;
	bool SetAdd = 0;
	bool PlayAdd = 0;


	std::string loc;
	switch (a)
	{
	case 0: loc = "assets/levels/1_Lb/"; break;
	case 1: loc = "assets/levels/2_Df/"; break;
	case 2: loc = "assets/levels/3_Wc/"; break;
	}
	float time;
	
	backGroundParalax lv_1(loc, SIZEX / 2, SIZEY / 2);
	sf::Font m_font, m_msgFont;
	sf::Text m_text, msg, aboutTxt, playTxt;
	sf::Texture  m_CloudBiggestTex, m_CloudMediumTex, m_CloudSmallestTex, m_ButtonsTex, m_MsgTex, m_FogTex, m_TitleTexture, player_tex, windowTex, levels;
	sf::Sprite m_ButPlaySp, m_ButSetSp, m_ButAboutSp, m_ButEscSp, m_MsgSp, m_Fog, m_CloudBiggestSp, m_CloudMediumSp, m_CloudSmallestSp, m_TitleSprite, player_sp, windowSp, crossSp, inst, telegr, gmail, discord, sfml, lv1, lv2, lv3, lv_block;

	m_CloudBiggestTex.loadFromFile("assets/levels/clouds/clouds_biggest.png");
	m_CloudMediumTex.loadFromFile("assets/levels/clouds/clouds_medium.png");
	m_CloudSmallestTex.loadFromFile("assets/levels/clouds/clouds_smallest.png");
	m_TitleTexture.loadFromFile("assets/gui/logo.png");
	levels.loadFromFile("assets/gui/levels.png");
	levels.setSmooth(true);
	//window
	windowTex.loadFromFile("assets/gui/window.png");

	//Text
	//std::string about;
	aboutTxt.setFont(m_msgFont);
	aboutTxt.setString("Hey you, dear stranger! \n< A story about ugly man > was created by <DarkMinimum>.\nI'm student of < Kharkiv National University of Radio Electronics>. \nHere I've learnt C++ and tried to do this little game.\nIt's based on SFML - 2.5.1 - graphical/audio/and-so-on engine. \nI'm really happy, that this library exists.\n\n\ \nIf you want to find me, please, use links below. \nBy the way, you can find SFML link too.\nHave a nice experience. <3");

	playTxt.setFont(m_msgFont);
	playTxt.setString("Here is the list of levels. <Click> on the level icon to continue. \n* Unfortunately, only first level was created completely.\n\n\n\n\t\t\t<Lonely boy>\t\t  <Darkest forest>\t\t<Wizard Castel>");

	///but
	m_MsgTex.loadFromFile("assets/gui/msg.png");
	m_ButtonsTex.loadFromFile("assets/gui/m_buttons.png");
	// Связываем спрайт и текстуру
	m_ButPlaySp.setTexture(m_ButtonsTex);
	m_ButSetSp.setTexture(m_ButtonsTex);
	m_ButAboutSp.setTexture(m_ButtonsTex);
	m_ButEscSp.setTexture(m_ButtonsTex);
	m_MsgSp.setTexture(m_MsgTex);
	m_Fog.setTexture(m_FogTex);

	windowSp.setTexture(windowTex);
	crossSp.setTexture(m_ButtonsTex);
	crossSp.setTextureRect(sf::IntRect(268, 0, 44,42));

	inst.setTexture(m_ButtonsTex);
	telegr.setTexture(m_ButtonsTex);
	gmail.setTexture(m_ButtonsTex);
	discord.setTexture(m_ButtonsTex);
	sfml.setTexture(m_ButtonsTex);

	lv1.setTexture(levels);
	lv2.setTexture(levels);
	lv3.setTexture(levels);
	lv_block.setTexture(levels);
	


	inst.setTextureRect(sf::IntRect(341,428, 59, 59));
	telegr.setTextureRect(sf::IntRect(333, 490, 67, 66));
	gmail.setTextureRect(sf::IntRect(338, 558, 61,61));
	discord.setTextureRect(sf::IntRect(337,366, 61, 61));
	sfml.setTextureRect(sf::IntRect(348, 319, 45, 47));

	m_ButPlaySp.setTextureRect(sf::IntRect(0, 0, 240, 68));
	m_ButSetSp.setTextureRect(sf::IntRect(0, 147, 400, 85));
	m_ButAboutSp.setTextureRect(sf::IntRect(0, 316, 323, 64));
	m_ButEscSp.setTextureRect(sf::IntRect(0, 456, 312, 80));

	lv1.setTextureRect(sf::IntRect(0, 0, 240, 135));
	lv2.setTextureRect(sf::IntRect(240, 0, 240, 135));
	lv3.setTextureRect(sf::IntRect(480, 0, 240, 135));
	lv_block.setTextureRect(sf::IntRect(720, 0, 240, 135));
	


	player_tex.loadFromFile("assets/entity/player_map.png");
	player_sp.setTexture(player_tex);

	m_font.loadFromFile("assets/fonts/font_inf.ttf");//передаем нашему шрифту файл шрифта
	m_msgFont.loadFromFile("assets/fonts/font_cloud.ttf");
	//buttons
	m_ButtonsTex.loadFromFile("assets/gui/m_buttons.png");

	

	m_CloudBiggestSp.setTexture(m_CloudBiggestTex);
	m_CloudMediumSp.setTexture(m_CloudMediumTex);
	m_CloudSmallestSp.setTexture(m_CloudSmallestTex);

	m_TitleSprite.setTexture(m_TitleTexture);
	
	player_sp.setPosition(-50, 200);
	player_sp.setRotation(30.0f);
	player_tex.setSmooth(1);
	player_sp.scale(2, 2);
	

	// title
	m_TitleSprite.setPosition(1200, 50);
	m_TitleSprite.setScale(1, 1);

	m_Fog.setPosition(0, 800);
	m_Fog.setScale(2, 2);
	// Buttons
	m_ButPlaySp.setPosition(x, y - 15);
	m_ButSetSp.setPosition(x - 80, y + 60);
	m_ButAboutSp.setPosition(x - 35, y + 170);
	m_ButEscSp.setPosition(x - 40, y + 250);

	m_MsgSp.setPosition(115, 250);
	m_MsgSp.setScale(0.6, 0.6);
	//
	windowSp.setOrigin(480 / 2, 270 / 2);
	windowSp.setScale(2.2, 2.2);
	windowSp.setPosition(SIZEX / 2 - SIZEX/8, SIZEY / 2);

	crossSp.setOrigin(44/2, 42/2);
	inst.setOrigin(59/2, 59 / 2);
	gmail.setOrigin(61 / 2, 61 / 2);
	discord.setOrigin(61/2, 61/2);
	telegr.setOrigin(67/2, 66/2);
	sfml.setOrigin(45/2, 47/2);



	crossSp.setPosition(windowSp.getPosition().x + 525, windowSp.getPosition().y - 290);
	crossSp.setScale(0.8, 0.8);
	sfml.setScale(1.2, 1.2);

	aboutTxt.setPosition(windowSp.getPosition().x - 510, windowSp.getPosition().y - 285);
	playTxt.setPosition(windowSp.getPosition().x - 510, windowSp.getPosition().y - 285);

	inst.setPosition(windowSp.getPosition().x + 400, windowSp.getPosition().y + 210);
	telegr.setPosition(windowSp.getPosition().x + 300, windowSp.getPosition().y + 210);
	gmail.setPosition(windowSp.getPosition().x + 200, windowSp.getPosition().y + 210);
	discord.setPosition(windowSp.getPosition().x + 100, windowSp.getPosition().y + 210);
	sfml.setPosition(windowSp.getPosition().x, windowSp.getPosition().y + 210);

	lv1.setOrigin(240/2, 135/2);
	lv2.setOrigin(240 / 2, 135 / 2);
	lv3.setOrigin(240 / 2, 135 / 2);
	lv_block.setOrigin(240 / 2, 135 / 2);
	lv1.setPosition(windowSp.getPosition().x - 300, windowSp.getPosition().y);
	lv2.setPosition(windowSp.getPosition().x , windowSp.getPosition().y);
	lv3.setPosition(windowSp.getPosition().x + 300, windowSp.getPosition().y);


	//crossSp.setScale(0.7, 0.7);

	sf::Clock clock;
	sf::Clipboard clip;
	bool pressed = 1;


	while (isMenu)
	{

		///clock////
		time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;


		window.clear(sf::Color(129, 181, 221));

		//Events Handler
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
		}

		// Обрабатываем нажатие Escape
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();

		if ( (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (m_ButEscSp.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y))))
		{
			if (pressed)
			{
				sound.play();
				pressed = 0;
			}
			window.close();
		}
		// Обрабатываем нажатие play
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (m_ButPlaySp.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)))
		{
			//isMenu = 0;
			//window.close();
			AboutAdd = 0;
			SetAdd = 0;
			PlayAdd = 1;
			if (pressed)
			{
				sound.play();
				pressed = 0;
			}
		}
		//Cross
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && ( AboutAdd || PlayAdd || SetAdd) && (crossSp.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y - 30)))
		{
			AboutAdd = 0;
			SetAdd = 0;
			PlayAdd = 0;
			if (pressed)
			{
				sound.play();
				pressed = 0;
			}
		}
		//About
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (m_ButAboutSp.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)))
		{
			AboutAdd = 1;
		
			SetAdd = 0;
			PlayAdd = 0;
			if (pressed)
			{
				sound.play();
				pressed = 0;
			}
		}
		//Sett
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (m_ButSetSp.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)))
		{
			SetAdd = 1;
			AboutAdd = 0;
		
			PlayAdd = 0;
			if (pressed)
			{
				sound.play();
				pressed = 0;
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (inst.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y - 30)))
		{
		
			if (pressed)
			{
				ShellExecute(0, 0, "http://www.instagram.com/dark.minimum/", 0, 0, SW_SHOW); //clip.setString("instagram.com/dark.minimum/");
				sound.play();
				pressed = 0;
			}

		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (telegr.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y - 30))) 
		{
			clip.setString("@DarkMinimum");
			if (pressed)
			{
				sound.play();
				pressed = 0;
			}
		}
			
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (gmail.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y - 30)))
		{
			clip.setString("danylo.hrechyshkin@nure.ua");
			if (pressed)
			{
				sound.play();
				pressed = 0;
			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (discord.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y - 30)))
		{
			clip.setString("#3260");
			if (pressed)
			{
				sound.play();
				pressed = 0;
			}

		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (sfml.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y - 30)))
		{
			
			if (pressed)
			{
				ShellExecute(0, 0, "http://www.sfml-dev.org/index.php", 0, 0, SW_SHOW); //clip.setString("sfml-dev.org/index.php");
				sound.play();
				pressed = 0;
			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (lv1.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)))
		{
			sound.play();
			main_menu.stop();
			while(lv_0(window));
			main_menu.play();
		}
		if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) pressed = 1;


		m_CloudSmallestSp.move(0.2, 0.0);

		m_CloudBiggestSp.move(-0.1, 0.0);

		if (m_CloudSmallestSp.getPosition().x >= 1000)
		{
			m_CloudSmallestSp.setPosition(-1700, 0);
		}

		if (m_CloudBiggestSp.getPosition().x <= -1900)
		{
			m_CloudBiggestSp.setPosition(1900, 0);

		}

		if (m_MsgSp.getScale().y >= 0.7) c = -0.0007;
		if (m_MsgSp.getScale().y <= 0.6) c = 0.0007;

		m_MsgSp.setScale(m_MsgSp.getScale().x + c, m_MsgSp.getScale().y + c);
		msg.setScale(msg.getScale().x + c, msg.getScale().y + c);

		//std::cout << m_MsgSp.getScale().y << std::endl;

		CurrentFrame += 0.009 * time;
		if (CurrentFrame > 18) CurrentFrame -= 18;
		player_sp.setTextureRect(sf::IntRect(226 * int(CurrentFrame), 0, 227, 227));

		switch (e.type)
		{

			// нажатие клавиши
		case sf::Event::MouseMoved:
		{
			//std::cout << "new mouse x: " << e.mouseMove.x << std::endl;
			//std::cout << "new mouse y: " << e.mouseMove.y << std::endl;



			if (m_ButPlaySp.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y))
			{

				m_MsgSp.setTextureRect(sf::IntRect(0, 0, 594, 378));
				msg.setString("Oh, press it, \nhuman being! We'll \nhave appealing \njourney.");

				m_ButPlaySp.setTextureRect(sf::IntRect(0, 70, 240, 75));


			}
			else
			{
				m_MsgSp.setTextureRect(sf::IntRect(0, 0, 0, 0));
				m_ButPlaySp.setTextureRect(sf::IntRect(0, 0, 240, 68));

				msg.setString("");


			}

			if (m_ButSetSp.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y))
			{
				m_MsgSp.setTextureRect(sf::IntRect(0, 0, 594, 378));
				msg.setString("I can't see \nanything right here...");

				m_ButSetSp.setTextureRect(sf::IntRect(0, 229, 400, 88));

			}
			else m_ButSetSp.setTextureRect(sf::IntRect(0, 147, 400, 84));

			if (m_ButAboutSp.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y - 10))
			{
				m_MsgSp.setTextureRect(sf::IntRect(0, 0, 594, 360));
				msg.setString("My master has left \nthere a paper piece. \nHe thought that \nthis info was important.");

				m_ButAboutSp.setTextureRect(sf::IntRect(0, 383, 330, 70));

			}
			else m_ButAboutSp.setTextureRect(sf::IntRect(0, 316, 323, 64));



			if (m_ButEscSp.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y))
			{
				m_MsgSp.setTextureRect(sf::IntRect(0, 0, 594, 378));
				msg.setString("How dare you? \nCome back right now! \nYou was like a \nfather to me!");

				m_ButEscSp.setTextureRect(sf::IntRect(0, 531, 312, 80));


			}
			else m_ButEscSp.setTextureRect(sf::IntRect(0, 456, 312, 80));



			if (player_sp.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y))
			{
				m_MsgSp.setTextureRect(sf::IntRect(0, 0, 594, 378));
				msg.setString("Oh, It's you. I'm \nwaiting for you.\nSo, now press \nthe <PLAY> button.");

			}

			if (crossSp.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y - 30))
				crossSp.setScale(1, 1);
			else crossSp.setScale(0.8, 0.8);

			if (inst.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y - 30))
				inst.setScale(1.1, 1.1);
			else inst.setScale(1, 1);

			if (telegr.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y - 30))
				telegr.setScale(1.1, 1.1);
			else telegr.setScale(1, 1);

			if (discord.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y - 30))
				discord.setScale(1.1, 1.1);
			else discord.setScale(1, 1);

			if (gmail.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y - 30))
				gmail.setScale(1.1, 1.1);
			else gmail.setScale(1, 1);

			if (sfml.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y - 30))
				sfml.setScale(1.3, 1.3);
			else sfml.setScale(1.2, 1.2);

			if (lv1.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y - 30))
				lv1.setScale(1.2, 1.2);
			else lv1.setScale(1.1, 1.1);

			if (lv2.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y - 30))
			{
				lv2.setScale(1.2, 1.2);
				lv_block.setPosition(lv2.getPosition().x, lv2.getPosition().y);
				lv_block.setScale(1.2, 1.2);
			}
			else
			{
				
				lv2.setScale(1.1, 1.1);
			}

			if (lv3.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y - 30))
			{
				lv3.setScale(1.2, 1.2);
				lv_block.setPosition(lv3.getPosition().x, lv3.getPosition().y);
				lv_block.setScale(1.2, 1.2);
			}
			else
			{
				lv3.setScale(1.1, 1.1);
			}
			if (!lv3.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y - 30) && !lv2.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y - 30))
			{
				lv_block.setScale(0, 0);
			}
			break;
		}

		
		}







		window.draw(lv_1[0].objSprite());
		window.draw(lv_1[1].objSprite());
		window.draw(lv_1[2].objSprite());
		//window.draw(lv_1.getLayer(2).getSprite());

		window.draw(m_TitleSprite);
		window.draw(m_CloudBiggestSp);
		window.draw(m_CloudMediumSp);
		window.draw(m_CloudSmallestSp);

		window.draw(m_ButPlaySp);
		window.draw(m_ButAboutSp);
		window.draw(m_ButSetSp);
		window.draw(m_ButEscSp);

		if (AboutAdd)
		{
		
			window.draw(windowSp);
			window.draw(crossSp);
			window.draw(aboutTxt);

			window.draw(inst);
			window.draw(telegr);
			window.draw(gmail);
			window.draw(discord);
			window.draw(sfml);
		}
		if (PlayAdd)
		{
			window.draw(windowSp);
			window.draw(crossSp);

			window.draw(lv1);
			window.draw(lv2);
			window.draw(lv3);
			window.draw(lv_block);

			window.draw(playTxt);
		}
			
		if (SetAdd)
		{
			window.draw(windowSp);
			window.draw(crossSp);
		}

		window.draw(m_MsgSp);

		m_text.setFont(m_font);
		m_text.setCharacterSize(24);
		m_text.setString("DarkMinimum's first project. 28.09.2019. Doesn't show the final quality of the game. ver 0.1.2 new classes");
		m_text.setFillColor(sf::Color::White);
		m_text.setPosition(5, 5);

		msg.setFont(m_msgFont);
		msg.setCharacterSize(35);
		//msg.setString("Doesn't show the final quality of the game.");
		msg.setFillColor(sf::Color::Black);
		msg.setPosition(140, 255);

		window.draw(m_text);
		window.draw(msg);
		window.draw(player_sp);
		

		window.display();
		

	}


}




