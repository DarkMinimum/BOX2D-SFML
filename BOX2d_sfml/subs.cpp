#include "subs.h"

subs::subs(grObj* gr, bool i) : grObj(*gr)
{
	//obj = gr;
	isVisible = i;
	font.loadFromFile("assets/fonts/font_cloud.ttf");
	txt.setFont(font);
	txt.setString("void");
	txt.setCharacterSize(32);
};
void subs::setSub(std::string str)
{
	txt.setString(str);
};
void subs::update(grObj* target)
{


	switch (condition)
	{


	case 0:
	{
		setSub("Press <F> key . . .");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		{

			++condition;
		}

		break;
	};

	case 1:
	{
		setSub("Press <A-D> to move ...");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			A = 1;
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			D = 1;
	

		if (A && D)
		{
			++condition;
			A = 0; D = 0;
		}
		break;
	};

	case 2:
	{
		setSub("<Q> and <E> to interact with box ...");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			A = 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
			D = 1;
		if (A && D) ++condition;
		break;
	};

	case 3:
	{
		isVisible = 0;
	}

	};


	if (isVisible)
	{
		grObj::objSprite().setOrigin(480 / 2, 101 / 2);
		grObj::setScale(1.2, 1.2);
		grObj::setPosition(target->getPosition().x, target->getPosition().y - 400);

		txt.setOrigin(txt.getLocalBounds().width / 2, txt.getLocalBounds().height / 2);
		txt.setPosition(grObj::getPosition().x, grObj::getPosition().y);
	}
	else
	{
		grObj::setScale(0, 0);
		txt.setCharacterSize(0);
	}

	//if (!sf::Keyboard::isKeyPressed(sf::Keyboard::C) || !sf::Keyboard::isKeyPressed(sf::Keyboard::F)) isPressed = 0;


};
const sf::Text& subs::getTxt() const
{
	return txt;
}
subs::operator sf::Sprite()
{
	return grObj::operator sf::Sprite();
}
