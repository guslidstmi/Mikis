#include "City.h"

City::City(const float x, const float y, const int id, const sf::Texture& cityTexture) :
	m_Id{ id }
	, m_neighbourCity{0, 0, 16, 15}
	, m_playerCity{0, 15, 16, 15}
	, m_City{}
{
	m_City.setTexture(cityTexture);
	m_City.setPosition(x, y);
	if (id > 0)
	{
		m_City.setTextureRect(m_neighbourCity);
	}
	else
	{
		m_City.setTextureRect(m_playerCity);
	}
}

const int City::m_getCityId() const
{
	return m_Id;
}

sf::Sprite& City::m_getRect()
{
	return m_City;
}
