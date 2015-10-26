#ifndef SPRITES_H_
#define SPRITES_H_
#pragma once

#include "SFML/Graphics.hpp"
#include <string>

class Sprites
{
public:

	Sprites(std::String fileName, sf::IntRect );

private:

	sf::Texture textImg; 


};


#endif // SPRITES_H_