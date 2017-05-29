#include "Enemy.h"

Enemy::Enemy(const float x, const float y, const int id, const int row, const int col) 
	: m_enemy{}
	, left{ 6, 8, 45, 40 }
	, front{66, 8, 45, 40 }
	, right{130, 8, 45, 40 }
	, left2{6, 65, 45, 40 }
	, front2{66, 65, 45, 40 }
	, right2{130, 65, 45, 40 }
	, left3{6, 130, 45, 40 }
	, front3{66, 130, 45, 40 }
	, right3{130, 130, 45, 40 }
	, m_id{ id }
	, m_row{ row }
	, m_col{ col }
	, m_lives{ 3 }
	, m_destroyed{ false }
	, m_bottom{ false }
	, m_state{State::FullHealth}
{
	m_enemy.setPosition(x, y);
}

const bool Enemy::update(const int num, const sf::Texture& texture)
{
	if (m_enemy.getTexture() == nullptr)
	{
		m_enemy.setTexture(texture);
		m_enemy.scale(1.0f, 1.0f);
		m_enemy.setTextureRect(front);
	}
	if (m_enemy.getPosition().y > 525.f && !isDestroyed())
	{
		return true;
	}

	switch (m_row)
	{
	case 0 :
		
		switch (num)
		{
		case 0 :
			velocity.y += 20.f;
			velocity.x = 0;
			m_enemy.move(velocity);
			switch (m_state)
			{
			case State::FullHealth : m_enemy.setTextureRect(front); break;
			case State::HitOnce :  m_enemy.setTextureRect(front2); break;
			case State::HitTwice :  m_enemy.setTextureRect(front3); break;
			} 
			
			break;
		case 1 :
			velocity.y = 0;
			velocity.x += 15.f;
			m_enemy.move(velocity);
			switch (m_state)
			{
			case State::FullHealth: m_enemy.setTextureRect(right); break;
			case State::HitOnce:  m_enemy.setTextureRect(right2); break;
			case State::HitTwice:  m_enemy.setTextureRect(right3); break;
			}
			break;
		case 2 :
			velocity.y = 0;
			velocity.x -= 15.f;
			m_enemy.move(velocity);
			switch (m_state)
			{
			case State::FullHealth: m_enemy.setTextureRect(left); break;
			case State::HitOnce:  m_enemy.setTextureRect(left2); break;
			case State::HitTwice:  m_enemy.setTextureRect(left3); break;
			}
			break;
		case 3 :
			velocity.y = 0;
			velocity.x -= 15.f;
			m_enemy.move(velocity);
			switch (m_state)
			{
			case State::FullHealth: m_enemy.setTextureRect(left); break;
			case State::HitOnce:  m_enemy.setTextureRect(left2); break;
			case State::HitTwice:  m_enemy.setTextureRect(left3); break;
			}
			break;
		case 4 :
			velocity.y = 0;
			velocity.x += 15.f;
			m_enemy.move(velocity);
			switch (m_state)
			{
			case State::FullHealth: m_enemy.setTextureRect(right); break;
			case State::HitOnce:  m_enemy.setTextureRect(right2); break;
			case State::HitTwice:  m_enemy.setTextureRect(right3); break;
			}
			break;
		}
		break;
	case 1 :

		switch (num)
		{
		case 0:
			velocity.y += 20.f;
			velocity.x = 0;
			m_enemy.move(velocity); 
			switch (m_state)
			{
			case State::FullHealth: m_enemy.setTextureRect(front); break;
			case State::HitOnce:  m_enemy.setTextureRect(front2); break;
			case State::HitTwice:  m_enemy.setTextureRect(front3); break;
			}
			break;
		case 1:
			velocity.y = 0;
			velocity.x -= 15.f;
			m_enemy.move(velocity);
			switch (m_state)
			{
			case State::FullHealth: m_enemy.setTextureRect(left); break;
			case State::HitOnce:  m_enemy.setTextureRect(left2); break;
			case State::HitTwice:  m_enemy.setTextureRect(left3); break;
			}
			break;
		case 2:
			velocity.y = 0;
			velocity.x += 15.f;
			m_enemy.move(velocity);
			switch (m_state)
			{
			case State::FullHealth: m_enemy.setTextureRect(right); break;
			case State::HitOnce:  m_enemy.setTextureRect(right2); break;
			case State::HitTwice:  m_enemy.setTextureRect(right3); break;
			}
			break;
		case 3:
			velocity.y = 0;
			velocity.x += 15.f;
			m_enemy.move(velocity);
			switch (m_state)
			{
			case State::FullHealth: m_enemy.setTextureRect(right); break;
			case State::HitOnce:  m_enemy.setTextureRect(right2); break;
			case State::HitTwice:  m_enemy.setTextureRect(right3); break;
			}
			break;
		case 4:
			velocity.y = 0;
			velocity.x -= 15.f;
			m_enemy.move(velocity);
			switch (m_state)
			{
			case State::FullHealth: m_enemy.setTextureRect(left); break;
			case State::HitOnce:  m_enemy.setTextureRect(left2); break;
			case State::HitTwice:  m_enemy.setTextureRect(left3); break;
			}
			break;
		}
		break;
	}
	return false;
}

void Enemy::incrementState()
{
	switch (m_state)
	{
	case State::FullHealth: m_state = State::HitOnce; break;
	case State::HitOnce: m_state = State::HitTwice; break;
	default: m_state = State::FullHealth; break;
	}
}

