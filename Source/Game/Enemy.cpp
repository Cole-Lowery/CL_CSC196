#include "Enemy.h"

void Enemy::Update(float dt)
{
	viper::vec2 direction{ 1, 0 };
	viper::vec2 force = direction.Rotate(viper::math::degToRad(m_transform.rotation)) * thrust * speed;
	velocity += force * dt;

	m_transform.position.x = viper::math::wrap(m_transform.position.x, 0.0f, (float)viper::GetEngine().GetRenderer().GetWidth());
	m_transform.position.y = viper::math::wrap(m_transform.position.y, 0.0f, (float)viper::GetEngine().GetRenderer().GetHeight());

	Actor::Update(dt);
}
