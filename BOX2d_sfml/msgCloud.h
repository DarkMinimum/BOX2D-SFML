#pragma once
#include "grObj.h"

class msgCloud : public grObj
{
protected:
	////forNPC
	sf::Font m_font;
	sf::Text msgTxt;
	bool con = 0;
	float c;


public:
	msgCloud();

	//(boySp.getPosition(), getPosition(), getScaleX(), "...");
	void openCloud(sf::Vector2f boy, float scale, std::string str);

	void animCloud();



};
