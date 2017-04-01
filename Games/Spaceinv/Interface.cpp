#include "Interface.h"

Interface::Interface() :
mWindow{ { windowWidth, windowHeight }, "Space Invaders - Game" }
{
	mWindow.setFramerateLimit(60);
	if(!background.loadFromFile("sky.jpg"))
	{
		std::cout << "Could not load background" << std::endl;
	}
	backgroundSprite.setTexture(background);
	backgroundSprite.setPosition(sf::Vector2f(0.f, 0.f));
}
