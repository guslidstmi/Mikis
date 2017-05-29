#pragma once
#include <SFML\Graphics.hpp>
#include "Tile.h"

class City
{
public :
	City(const float x, const float y, const int id, const sf::Texture& cityTexture);
	const int getCityId() const;
	const sf::Sprite& getCity() const;

private :
	sf::Sprite m_City;
	const sf::IntRect m_playerCity;
	const sf::IntRect m_neighbourCity;
	const int m_Id;
};