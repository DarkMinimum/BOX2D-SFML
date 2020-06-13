#include "msgCloud.h"

msgCloud::msgCloud() : grObj("assets/gui/msg.png", sf::Vector2i(0, 0), sf::Vector2i(594, 365))
{

	m_font.loadFromFile("assets/fonts/font_cloud.ttf");
	msgTxt.setFont(m_font);

	msgTxt.setFillColor(sf::Color::Black);

	this->objSprite().setOrigin(594 / 2, 365 / 2);
	msgTxt.setOrigin(594 / 4, 365 / 4);

	c = 0;

}

//(boySp.getPosition(), getPosition(), getScaleX(), "...");
void msgCloud::openCloud(sf::Vector2f boy, float scale, std::string str)
{ //"Hi there, Bro!\nI'm friendly NPC!\nI'm waiting for ur AI\nI need friends..."
	msgTxt.setString(str);
	objSprite().setScale(-scale * 0.7, 0.5);
	msgTxt.setScale(1, 1);
	this->objSprite().setPosition(boy.x - scale * 70, boy.y - 150);
	msgTxt.setPosition(objSprite().getPosition().x + 20, objSprite().getPosition().y + 5);

	//(this->getScaleX() > 0) ? msgTxt.setPosition(this->objSprite().getPosition().x + 20, this->objSprite().getPosition().y + 5) : msgTxt.setPosition(this->objSprite().getPosition().x - 280, this->objSprite().getPosition().y + 5);
}

void msgCloud::animCloud()
{


	//std::cout << this->objSprite().getScale().x << '\t' << this->objSprite().getScale().y << std::endl;

	switch (con)
	{
	case 0:
	{
		if ((double)this->objSprite().getScale().y > 0.55)
			con = 1;

		c = 1.001;

		break;
	};

	case 1:
	{
		if (this->objSprite().getScale().y < 0.5)
			con = 0;

		c = 0.999;

		break;
	};
	}



	this->objSprite().scale(c, c);
	//this->msgTxt.move(-10* fabs(this->objSprite().getScale().x, 0);
	this->msgTxt.scale(c, c);
	//(this->getScaleX() > 0) ? msgTxt.setPosition(this->objSprite().getPosition().x + 20 * this->getScaleX(), this->objSprite().getPosition().y + 5) : msgTxt.setPosition(this->objSprite().getPosition().x - 280, this->objSprite().getPosition().y + 5);




	/*
	from 0.5 to 0.54


	*/
}
