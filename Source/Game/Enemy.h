#pragma once

#include "Framework/Actor.h"

class Enemy : public viper::Actor {
public:
	float speed = 75.0f;
	float fireTime = 0;
	float fireTimer = 0;

public:
	Enemy() = default;
	Enemy(const viper::Transform transform, std::shared_ptr<viper::Model> model) :
		Actor{ transform, model }
	{
	}

	void Update(float dt) override;

	void OnCollision(Actor* other) override;
};