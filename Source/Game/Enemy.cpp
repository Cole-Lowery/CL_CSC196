#include "Enemy.h"
#include "Engine.h"
#include "Framework/Scene.h"
#include "Framework/Game.h"
#include "Renderer/Renderer.h"

void Enemy::Update(float dt)
{
	bool playerSeen = false;
	Actor* player = m_scene->GetactorByName("player");
	if (player)
	{
		viper::vec2 direction{ 0, 0 };
		direction = player->m_transform.position - m_transform.position;
		direction = direction.Normalized();
		viper::vec2 forward = viper::vec2{ 1, 0 }.Rotate(viper::math::degToRad(m_transform.rotation * speed ));
		

		float angle = viper::math::radToDeg(viper::vec2::AngleBetween(forward, direction));
		playerSeen = angle <= 30;

		if (playerSeen) {
			float angle = viper::vec2::SignedAngleBetween(direction, forward);
			angle = viper::math::sign(angle);
			m_transform.rotation = viper::math::radToDeg(angle);
		}
		

	}

	viper::vec2 force = viper::vec2{ 1,0 }.Rotate(viper::math::degToRad(m_transform.rotation)) * speed;
	velocity += force;

	m_transform.position.x = viper::math::wrap(m_transform.position.x, 0.0f, (float)viper::GetEngine().GetRenderer().GetWidth());
	m_transform.position.y = viper::math::wrap(m_transform.position.y, 0.0f, (float)viper::GetEngine().GetRenderer().GetHeight());

	Actor::Update(dt);
}
void Enemy::OnCollision(Actor* other)
{
	if (tag != other->tag) {
		destroyed = true;
		m_scene->GetGame()->AddPoints(100);
	}
}