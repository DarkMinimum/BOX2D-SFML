#pragma once
#include "grObj.h"

class subs : public grObj
	{
	private:
		//grObj* obj;
		bool isVisible;
		sf::Text txt;
		sf::Font font;
	
		//triggers
		sf::Clock ck;
		bool isTime;
		int condition = 0;
	
		bool A = 0;
		bool D = 0;
	
		subs() {};
	
	public:
		subs(grObj* gr, bool i);
		void setSub(std::string str);
		void update(grObj * target);
		const sf::Text& getTxt() const;
		operator sf::Sprite();
	};
	
	