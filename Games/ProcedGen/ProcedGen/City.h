#pragma once
#include <SFML\Graphics.hpp>
#include "Tile.h"

class City
{
public :
	City(const float x, const float y, const int id, const sf::Texture& cityTexture);
	const int m_getCityId() const;
	sf::Sprite& m_getCity();

private :
	sf::Sprite m_City;
	sf::IntRect m_playerCity;
	sf::IntRect m_neighbourCity;
	const int m_Id;
};