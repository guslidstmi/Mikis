#include "Hearts.h"
#include <iostream>

Hearts::Hearts(int x, int y) :
	m_heart{}
{
	m_heart.setPosition(sf::Vector2f(x, y));
	timer = 0;
	state = 0;
	scale = m_heart.getScale();
}

void Hearts::update(sf::Texture& heart_texture)
{
	if(m_heart.getTexture() == NULL)
	{
		m_heart.setTexture(heart_texture);
		m_heart.setTextureRect(sf::IntRect(0, 0, 30, 30));
	}
	++timer;
	if (timer == 60)
	{
		state = 1;	
	}
	else if (timer == 120)
	{
		state = 2;
	}
	else if (timer > 120) { timer = 0; }
	switch (state)
	{
	case 1 :
		m_heart.setTextureRect(sf::IntRect(31, 0, 30, 30));
		break;
	case 2 :
		m_heart.setTextureRect(sf::IntRect(0, 0, 30, 30));
		break;
	}
	
}