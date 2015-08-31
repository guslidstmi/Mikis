#include "Interface.h"
#include "Player.h"
#include "World.h"

int main()
{
	Interface interface{};
	Player player{};
	World world{};
	world.spawnAsteroid();

	while (interface.mWindow.isOpen())
	{
		interface.mWindow.clear(sf::Color::Black);

		sf::Event event;
		while (interface.mWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				interface.mWindow.close();
		}

		player.update(world);
		world.update();
		interface.mWindow.draw(player.mShip);

		for (std::vector<sf::CircleShape>::iterator it = world.asteroids.begin(); it != world.asteroids.end(); ++it)
		{
			interface.mWindow.draw(*it);
		}

		for (std::vector<sf::RectangleShape>::iterator it = world.shots.begin(); it != world.shots.end(); ++it)
		{
			interface.mWindow.draw(*it);
		}

		interface.mWindow.display();
	} 

	return 0;
}