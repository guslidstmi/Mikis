#ifndef INTERFACE_H_
#define INTERFACE_H_
#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace {

	constexpr unsigned int windowWidth{ 800 }, windowHeight{ 600 };
}

class Interface
{
public:
	Interface();
	sf::RenderWindow mWindow;

private:
	
};

#endif // INTERFACE_H_