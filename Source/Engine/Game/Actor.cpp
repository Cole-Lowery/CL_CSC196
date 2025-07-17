#include "Actor.h"
#include "../Renderer/Renderer.h"

void viper::Actor::Update(float deltaTime)
{
}

void viper::Actor::Draw(Renderer& renderer) const
{
	m_model->Draw(renderer, m_transform);
}
