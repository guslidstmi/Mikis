#ifndef INTERFACE_H_
#define INTERFACE_H_
#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace {

	unsigned int windowWidth{ 800 }, windowHeight{ 600 };
}

class Interface
{
public:
	Interface();
	sf::RenderWindow mWindow;
	sf::Texture background;

private:
	
};

#endif // INTERFACE_H_