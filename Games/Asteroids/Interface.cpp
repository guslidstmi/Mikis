#include "Interface.h"


Interface::Interface() :
mWindow{ { windowWidth, windowHeight }, "Asteroid - Game" }
{
	mWindow.setFramerateLimit(60);
}
