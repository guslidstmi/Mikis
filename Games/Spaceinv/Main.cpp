#include "Interface.h"
#include "World.h"

int main()
{
	Interface interface{};
	World world{};

	while (interface.mWindow.isOpen())
	{
		interface.mWindow.clear(sf::Color::Black);
		interface.mWindow.draw(interface.backgroundSprite);

		sf::Event event;
		while (interface.mWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				interface.mWindow.close();
		}

		
		world.update(interface);

		interface.mWindow.display();
	} 

	return 0;

}