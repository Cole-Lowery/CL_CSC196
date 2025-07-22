#include "Player.h"
#include "Engine.h"
#include "Input/InputSystem.h"
#include <SDL3/SDL_scancode.h>

void Player::Update(float dt)
{
	float speed = 200; // Speed in pixels per second
    // Determine movement direction from WASD keys
    viper::vec2 direction{ 0, 0 };
    if (viper::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_W)) direction.y = -1;
    if (viper::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_S)) direction.y = 1;
    if (viper::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_A)) direction.x = -1;
    if (viper::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_D)) direction.x = 1;

    if (direction.Length() > 0) {
        direction = direction.Normalized();
		m_transform.position += (direction * speed) * dt;
    }
}
