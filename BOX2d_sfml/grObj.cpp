#include "grObj.h"

grObj::grObj(std::string ResLoc)
{
	//tex;


	tex.loadFromFile(ResLoc);
	this->sp.setTexture(tex);

	tex.setSmooth(1);
	this->layer = 1;
}
grObj::grObj(std::string ResLoc, sf::Vector2i startPoint, sf::Vector2i size)
{



	tex.loadFromFile(ResLoc);
	this->sp.setTexture(tex);
	this->sp.setTextureRect(sf::IntRect(startPoint, size));
	tex.setSmooth(0);
	this->layer = 1;
}
grObj::grObj(sf::Texture& tile, sf::Vector2i startPoint, sf::Vector2i size)
{
	tex = tile;
	//std::cout << tex << std::endl;
	this->sp.setTexture(tex);
	this->sp.setTextureRect(sf::IntRect(startPoint, size));
	tex.setSmooth(0);
	this->layer = 1;
}
grObj::grObj(const grObj& gr)
{
	this->sp = gr.sp;
	this->tex = gr.tex;
}
grObj::operator sf::Sprite()
{
	return sp;
}
sf::Color grObj::getColor() const
{
	return this->sp.getColor();
}
sf::Vector2f grObj::getPosition() const
{
	return this->sp.getPosition();
}
short int grObj::getLayer() const
{
	return this->layer;
}
void grObj::setRes(std::string ResLoc)
{
	//tex = new sf::Texture;

	tex.loadFromFile(ResLoc);
	this->sp.setTexture(tex);
	tex.setSmooth(1);
}
void grObj::setIntRec(sf::Vector2i startPoint, sf::Vector2i size)
{
	//tex = new sf::Texture;
	//this->sp.setTexture(tex);
	this->sp.setTextureRect(sf::IntRect(startPoint, size));
	tex.setSmooth(1);
}
void grObj::setScale(float x, float y)
{
	this->sp.setScale(x, y);
};
void grObj::setColor(sf::Color col)
{
	this->sp.setColor(col);
}
void grObj::setPosition(float x, float y)
{
	sp.setPosition(x, y);
}
void grObj::setLayer(short int a)
{
	this->layer = a;
}
sf::Sprite& grObj::objSprite()
{
	return sp;
}
float grObj::getScaleX()
{
	return sp.getScale().x;
}