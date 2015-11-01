#include "Player.h"


Player::Player() :
	paddle{}, m_hearts{}
{
	paddle.setPosition(400, 550);
	paddle.setOrigin(60.f / 2.f, 20.f /2.f);
	m_lives = 3;
	popHearts();

}

bool Player::update(sf::Texture& texture)
{
	++m_timer;
	if (paddle.getTexture() == NULL)
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

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) 
		&& !paddle.getGlobalBounds().contains(5, 550)) velocity.x = -10.f;
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)
		&& !paddle.getGlobalBounds().contains(790, 550)) velocity.x = 10.f;
	else
		velocity.x = 0;

	return false;
}

float Player::x()		{ return paddle.getPosition().x; }
float Player::y()		{ return paddle.getPosition().y; }

int Player::getLives()
{
	return m_lives;
}

void Player::reduceLives()
{
	--m_lives;
	m_hearts.pop_back();
}

void Player::popHearts()
{
	int x = 5;
	for (int i = 0; i < 3; ++i)
	{
		Hearts heart(x, 5);
		m_hearts.push_back(heart);
		x += 35;
	}
}

std::vector<Hearts>& Player::getHearts()
{
	return m_hearts;
}