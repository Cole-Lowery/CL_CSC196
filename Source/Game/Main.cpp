#include "Math/Math.h"
#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include "Math/Transform.h"
#include "Core/Random.h"
#include "Core/Time.h"
#include "Framework/Actor.h"
#include "Audio/AudioSystem.h"
#include "Renderer/Renderer.h"
#include "Renderer/Model.h"
#include "Input/InputSystem.h"
#include "Framework/Scene.h"
#include "Engine.h" 
#include "Renderer/Font.h"
#include "Renderer/Text.h"

#include "Game/spaceGame.h"
#include "../Game/Player.h"


#include <iostream>
#include <vector>
#include <memory>

int main(int argc, char* argv[]) {
	// Initialize the engine
	viper::GetEngine().Initialize();

	std::unique_ptr<spaceGame> game = std::make_unique<spaceGame>();
    game->Initialize();
  

    // Load sounds into the audio system

    viper::GetEngine().GetAudio().AddSound("bass.wav", "base");
    viper::GetEngine().GetAudio().AddSound("snare.wav", "snare");
    viper::GetEngine().GetAudio().AddSound("clap.wav", "clap");
    viper::GetEngine().GetAudio().AddSound("cowbell.wav", "cowbell");
    viper::GetEngine().GetAudio().AddSound("close-hat.wav", "close-hat");
    viper::GetEngine().GetAudio().AddSound("open-hat.wav", "open-hat");

    Font* font = new Font();
    font->Load("Madina.ttf", 20);
    Text *text = new Text(font);
    text->Create(GetEngine().GetRenderer(), "Hello World", vec3{1, 1, 1, 1});

    SDL_Event e;
    bool quit = false;

    // Main game loop
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }
        // Exit if ESCAPE is pressed
        if (viper::GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_ESCAPE)) { quit = true; }
        // Update audio and input systems
        viper::GetEngine().Update();

        // Set renderer color to black and clear the screen
        viper::vec3 color{ 0, 0, 0 };
        viper::GetEngine().GetRenderer().SetColor(color.r, color.g, color.b);
        viper::GetEngine().GetRenderer().Clear();

        // Draw all actors
		game->Update();
        game->Draw();

        text->Draw(GetEngine().GetRenderer(), 40.0f, 40.0f);

        // Present the rendered frame
        viper::GetEngine().GetRenderer().Present();
    }

	viper::GetEngine().Shutdown();  
    game->Shutdown();
    return 0;
}