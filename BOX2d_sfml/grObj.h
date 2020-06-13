#pragma once
#include "SFML/Graphics.hpp"

//grafical primitive obj
class grObj
{
private:
	sf::Sprite sp;
	sf::Texture tex;
	short int layer = 1;


public:
	//empty
	grObj()
	{

	}

	grObj(std::string ResLoc);
	grObj(std::string ResLoc, sf::Vector2i startPoint, sf::Vector2i size);
	grObj(sf::Texture& tile, sf::Vector2i startPoint, sf::Vector2i size);
	grObj(const grObj& gr);

	operator sf::Sprite();

	sf::Color getColor() const;
	sf::Vector2f getPosition() const;
	short int getLayer() const;


	void setRes(std::string ResLoc);

	void setIntRec(sf::Vector2i startPoint, sf::Vector2i size);
	void setScale(float x, float y);
	void setColor(sf::Color col);
	void setPosition(float x, float y);
	void setLayer(short int a);

	sf::Sprite& objSprite();
	float getScaleX();


};
