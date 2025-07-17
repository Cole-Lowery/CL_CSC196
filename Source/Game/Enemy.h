#pragma once
#include "Game/Actor.h"
#include "Math/Transform.h"	

class Enemy : public viper::Actor {
public:
	Enemy() = default;
	Enemy(const viper::Transform& transform, std::shared_ptr<viper::Model> model)
		: viper::Actor(transform, model) {}

	void Update(float deltaTime) override;

private:
};

