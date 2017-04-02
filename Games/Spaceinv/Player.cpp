#include "Player.h"


Player::Player() 
	: paddle{}
	, m_hearts{}
	, m_lives{3}
	, m_timer{0}
{
	paddle.setPosition(400, 550);
	paddle.setOrigin(60.f / 2.f, 20.f /2.f);
	popHearts();
}

const bool Player::update(const sf::Texture& texture)
{
	++m_timer;
	if (paddle.getTexture() == nullptr)
	{
		paddle.setTexture(texture);
		paddle.setTextureRect(sf::IntRect(0, 0, 45, 20));
	}

	if(m_lives == 0)
	{
		return true;
	}
	if (m_timer < 40)
	{
		paddle.setTextureRect(sf::IntRect(0, 0, 45, 20));
	}
	else if (m_timer < 80)
	{
		paddle.setTextureRect(sf::IntRect(45, 0, 45, 20));
	}
	else 
		{ m_timer = 0; }

	paddle.move(velocity);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)
		&& !paddle.getGlobalBounds().contains(5, 550))
	{
		velocity.x = -10.f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)
		&& !paddle.getGlobalBounds().contains(790, 550))
	{
		velocity.x = 10.f;
	}
	else
		velocity.x = 0;

	return false;
}

void Player::reduceLives()
{
	--m_lives;
	m_hearts.pop_back();
}

void Player::popHearts()
{
	float x = 5.f;
	for (int i = 0; i < 3; ++i)
	{
		Hearts heart(x, 5.f);
		m_hearts.push_back(heart);
		x += 35.f;
	}
}