#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <iostream>
#include "Map.h"

int main()
{
	sf::RenderWindow mWindow(sf::VideoMode(800, 600), "Trade Game");
	mWindow.setFramerateLimit(60);
	sf::Event event;
	Map worldMap;
	
	while (mWindow.isOpen())
	{
		mWindow.pollEvent(event);

		if (event.type == sf::Event::Closed)
		{
			mWindow.close();
		}
		for (int i = 0; i < worldMap.getMap().size(); ++i)
		{
			mWindow.draw(worldMap.getMap()[i].m_getRect());
		}
		for (int i = 0; i < worldMap.getCities().size(); ++i)
		{
			mWindow.draw(worldMap.getCities()[i].m_getRect());
		}
		mWindow.display();
	}
}


