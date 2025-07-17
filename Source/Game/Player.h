#pragma once
#include "Game/Actor.h"
#include "Math/Transform.h"	

class Player : public viper::Actor {
public:
	Player() = default;
	Player(const viper::Transform& transform, std::shared_ptr<viper::Model> model)
		: viper::Actor(transform, model) {}

	void Update(float deltaTime) override;

private:
};

