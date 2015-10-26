#include "Player.h"

Player::Player() :
	paddle{}, m_hearts{}
{
	paddle.setSize({60.f, 20.f});
	paddle.setFillColor(sf::Color::White);
	paddle.setPosition(400, 550);
	paddle.setOrigin(60.f / 2.f, 20.f /2.f);
	m_lives = 3;

}

bool Player::update()
{
	if(m_lives == 0)
	{
		return true;
	}
	paddle.move(velocity);

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) 
		&& left() > 0) velocity.x = -10.f;
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)
		&& right() < 800) velocity.x = 10.f;
	else
		velocity.x = 0;

	return false;
}

float Player::x()		{ return paddle.getPosition().x; }
float Player::y()		{ return paddle.getPosition().y; }
float Player::left()	{ return x() - paddle.getSize().x / 2.f; }
float Player::right()	{ return x() + paddle.getSize().x / 2.f; }

int Player::getLives()
{
	return m_lives;
}

void Player::reduceLives()
{
	--m_lives;
}

void Player::popHearts()
{
	int x = 5;
	for (int i = 0; i < 3; ++i)
	{
		Hearts heart(x, 5);
		m_hearts.push_back(heart);
		x += 30;
	}
}

std::vector<Hearts>& Player::getHearts()
{
	return m_hearts;
}