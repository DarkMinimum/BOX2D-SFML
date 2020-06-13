
#include "Menu.h"
#include "level0r.h"
#include "SFML/Audio.hpp"




int main()
{
	

	//window
	sf::RenderWindow window(sf::VideoMode(SIZEX, SIZEY), "A story about ugly man", sf::Style::Fullscreen);
	window.setFramerateLimit(70);
	sf::Image icon;
	icon.loadFromFile("icon.png");

		

	window.setIcon(256, 256, icon.getPixelsPtr());


	menu(window);
	//lv_0(window);
		
	


	return 0;
}

