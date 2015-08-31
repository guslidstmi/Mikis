#include "Player.h"
#include "World.h"
#include <iostream>


Player::Player() :
mShip{ 20, 3 }
{
	mShip.setFillColor(sf::Color::White);
	mShip.setPosition(400, 300);
	mShip.setOrigin(24 ,24);
}

void Player::update(World& world)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		mShip.rotate(-2.50);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		mShip.rotate(2.50);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		direction = mShip.getPosition();
		rotation = mShip.getRotation();
		world.spawnShot(direction, rotation);
	}
}
