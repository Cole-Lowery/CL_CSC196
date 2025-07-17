#include "Math/Math.h"
#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include "Math/Transform.h"
#include "Core/Random.h"
#include "Core/Time.h"
#include "Game/Actor.h"
#include "Audio/AudioSystem.h"
#include "Renderer/Renderer.h"
#include "Renderer/Model.h"
#include "Input/InputSystem.h"
#include "../Game/Player.h"
#include "Game/Scene.h"

#include <iostream>
#include <vector>
#include <memory>

int main(int argc, char* argv[]) {

    // Intialize engine systems
    viper::Time time;
    
    // Create and initialize the renderer
    std::unique_ptr<viper::Renderer> renderer = std::make_unique<viper::Renderer>();
    renderer->Initialize();
    renderer->CreateWindow("Viper Engine", 1280, 1024);

    // Create and initialize the input system
    std::unique_ptr <viper::InputSystem> input = std::make_unique<viper::InputSystem>();
    input->Initialize();

    // Create and initialize the audio system
    std::unique_ptr<viper::AudioSystem> audio = std::make_unique<viper::AudioSystem>();
    audio->Initialize();

    // Define the points for the initial model (a custom shape)
    std::vector<viper::vec2> points{
            { 0, -10 },    // Tip
            { 8, 8 },      // Right corner
            { 2, 2 },      // Indent start
            { 0, -0 },     // Indent tip
            { -2, 2 },     // Indent end 
            { -8, 8 },     // Left corner
            { 0, -10 },    // Back to tip
    };

    // Create a shared model using the defined points and a blue color
    std::shared_ptr<viper::Model> model = std::make_shared<viper::Model>(points, viper::vec3{ 0, 0, 1 });

	viper::Scene scene;

   
    for (int i = 0; i < 10; i++) {
        viper::Transform transform{ { viper::random::getRandomFloat() * 1280, viper::random::getRandomFloat() * 1024 }, 0, 10 };
		std::unique_ptr<Player> player = std::make_unique<Player>(transform, model);
        scene.AddActors(std::move(player));
    }

    // Load sounds into the audio system
    audio->AddSound("bass.wav", "base");
    audio->AddSound("snare.wav", "snare");
    audio->AddSound("clap.wav", "clap");
    audio->AddSound("cowbell.wav", "cowbell");
    audio->AddSound("close-hat.wav", "close-hat");
    audio->AddSound("open-hat.wav", "open-hat");

    SDL_Event e;
    bool quit = false;

    // Main game loop
    while (!quit) {
        time.Tick(); // Update time

        // Handle SDL events (window close, etc.)
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        // Exit if ESCAPE is pressed
        if (input->GetKeyPressed(SDL_SCANCODE_ESCAPE)) { quit = true; }

        // Add a point to the model if left mouse button is pressed
        if (input->GetMouseButtonPressed(viper::InputSystem::MouseButton::Left)) {
            points.push_back(input->GetMousePosition());
        }

        // Add a point if left mouse button is held and mouse moved enough
        if (input->GetMouseButtonDown(viper::InputSystem::MouseButton::Left)) {
            viper::vec2 position = input->GetMousePosition();
            if (points.empty()) points.push_back(position);
            else if ((position - points.back()).Length() > 10) points.push_back(position);
        }

        // Update audio and input systems
        audio->Update();
        input->Update();
        float speed = 200;

        // Determine movement direction from WASD keys
        viper::vec2 direction{ 0, 0 };
        if (input->GetKeyDown(SDL_SCANCODE_W)) direction.y = -1;
        if (input->GetKeyDown(SDL_SCANCODE_S)) direction.y = 1;
        if (input->GetKeyDown(SDL_SCANCODE_A)) direction.x = -1;
        if (input->GetKeyDown(SDL_SCANCODE_D)) direction.x = 1;

        // Move all actors in the specified direction
        if (direction.Length() > 0) {
            direction = direction.Normalized();
            for (auto& actor : actors) {
                actor->GetTransform().position += (direction * speed) * time.GetDeltaTime();
            }
        }

        // Set renderer color to black and clear the screen
        viper::vec3 color{ 0, 0, 0 };
        renderer->SetColor(color.r, color.g, color.b);
        renderer->Clear();

        // Draw all actors
		scene.Draw(*renderer);

        // Present the rendered frame
        renderer->Present();
    }

    // Shutdown all systems
    renderer->Shutdown();
    audio->Shutdown();
    input->Shutdown();

    return 0;
}