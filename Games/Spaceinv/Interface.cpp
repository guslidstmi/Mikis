#include "Interface.h"


Interface::Interface() :
mWindow{ { windowWidth, windowHeight }, "Space Invaders - Game" }
{
	mWindow.setFramerateLimit(60);
	//background.loadFromFile("/sky.jpg");
	
}
