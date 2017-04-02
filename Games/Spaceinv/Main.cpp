#include "Interface.h"
#include "World.h"
#include <iostream>

int main()
{
	Interface interface{};
	World world{};
	sf::RectangleShape start;
	sf::RectangleShape quit;
	sf::Event event;
	sf::Font font; 	

	if (!font.loadFromFile("Font_Eroded.ttf"))
	{
		std::cout << "could not load font" << std::endl;
	}
	sf::Text startText("Start", font, 30);
	sf::Text quitText("Quit", font, 30);
	sf::Text spaceInvText("Mikis Cute-Invaders", font, 30);
	sf::Text gameOverText("Game Over!", font, 30);
	sf::Text congratzText("Congratulations!", font, 30);
	sf::Text winningText("You beat the Cuties and saved the world!", font, 20);

	startText.setFillColor(sf::Color(0, 102, 51, 255));
	quitText.setFillColor(sf::Color(0, 102, 51, 255));
	spaceInvText.setFillColor(sf::Color(0, 102, 51, 255));
	gameOverText.setFillColor(sf::Color(0, 102, 51, 255));
	congratzText.setFillColor(sf::Color(0, 102, 51, 255));
	winningText.setFillColor(sf::Color(0, 102, 51, 255));

	startText.setPosition(325, 200);
	quitText.setPosition(325, 300);
	spaceInvText.setPosition(200, 50);
	gameOverText.setPosition(280, 100);
	congratzText.setPosition(225, 200);
	winningText.setPosition(50, 300);

	start.setSize(sf::Vector2f(120, 40));
	start.setFillColor(sf::Color::Transparent);
	start.setPosition(325,200);
	quit.setSize(sf::Vector2f(100, 40));
	quit.setFillColor(sf::Color::Transparent);
	quit.setPosition(325, 300);

	while (interface.mWindow.isOpen())
	{
		switch (world.state)
		{
		case World::State::starting :

			interface.mWindow.clear(sf::Color::Black);
			interface.mWindow.draw(interface.backgroundSprite);
			interface.mWindow.draw(spaceInvText);
			interface.mWindow.draw(start);
			interface.mWindow.draw(startText);
			interface.mWindow.draw(quit);
			interface.mWindow.draw(quitText);


			interface.mWindow.pollEvent(event);
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					if (start.getGlobalBounds().contains((float)sf::Mouse::getPosition(interface.mWindow).x, (float)sf::Mouse::getPosition(interface.mWindow).y))
					{
						world.state = World::State::play;
					}
					else if (quit.getGlobalBounds().contains((float)sf::Mouse::getPosition(interface.mWindow).x, (float)sf::Mouse::getPosition(interface.mWindow).y))
					{
						interface.mWindow.close();
					}
				}
			}
			else if (event.type == sf::Event::Closed)
			interface.mWindow.close();

			interface.mWindow.display();
			break;

		case World::State::play :
			
			interface.mWindow.clear(sf::Color::Black);
			interface.mWindow.draw(interface.backgroundSprite);
			
			interface.mWindow.pollEvent(event);
			if (event.type == sf::Event::Closed)
			interface.mWindow.close();

			world.state = world.update(interface);

			interface.mWindow.display();
			break;

		case World::State::endLose :
			interface.mWindow.clear(sf::Color::Black);
			interface.mWindow.draw(interface.backgroundSprite);
			interface.mWindow.draw(gameOverText);
			interface.mWindow.draw(quit);
			interface.mWindow.draw(quitText);

			interface.mWindow.pollEvent(event);
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					if (quit.getGlobalBounds().contains((float)sf::Mouse::getPosition(interface.mWindow).x, (float)sf::Mouse::getPosition(interface.mWindow).y))
					{
						interface.mWindow.close();
					}
				}
			}
			if (event.type == sf::Event::Closed)
			interface.mWindow.close();

			interface.mWindow.display();
			break;

		case World::State::endWin:
			interface.mWindow.clear(sf::Color::Black);
			interface.mWindow.draw(interface.backgroundSprite);
			interface.mWindow.draw(congratzText);
			interface.mWindow.draw(winningText);

			interface.mWindow.pollEvent(event);

			if (event.type == sf::Event::Closed)
			interface.mWindow.close();
			interface.mWindow.display();
			break;
		}
	}
	return 0;
}