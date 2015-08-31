#ifndef PLAYER_H_
#define PLAYER_H_
#pragma once

#include <SFML/Graphics.hpp>
#include "World.h"

class Player
{
public:
	Player();
	void update(World& world);

	sf::CircleShape mShip;

private:
	sf::Vector2f direction;
	float rotation;

};
#endif //PLAYER_H_