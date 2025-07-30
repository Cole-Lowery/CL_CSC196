#include "Math/Math.h"
#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include "Math/Transform.h"
#include "Core/Random.h"
#include "Core/Time.h"
#include "Core/File.h"
#include "Framework/Actor.h"
#include "Audio/AudioSystem.h"
#include "Renderer/Renderer.h"
#include "Renderer/Model.h"
#include "Input/InputSystem.h"
#include "Framework/Scene.h"
#include "Engine.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"

#include "../Game/Player.h"
#include "Game/SpaceGame.h"

#include <iostream>
#include <vector>
#include <memory>

int main(int argc, char* argv[]) {

    // Get current directory path
    std::cout << "Directory Operations:\n";
    std::cout << "Current directory: " << viper::file::GetCurrentDirectory() << "\n";

    // Set current directory path (current path + "Assets")
    std::cout << "Setting directory to 'Assets'...\n";
    viper::file::SetCurrentDirectory("Assets");
    std::cout << "New directory: " << viper::file::GetCurrentDirectory() << "\n\n";

    // Get filenames in the current directory
    std::cout << "Files in Directory:\n";
    auto filenames = viper::file::GetFilesInDirectory(viper::file::GetCurrentDirectory());
    for (const auto& filename : filenames) {
        std::cout << filename << "\n";
    }
    std::cout << "\n";

    // Get filename (filename.extension) only
    if (!filenames.empty()) {
        std::cout << "Path Analysis:\n";
        std::string filename = viper::file::GetFilename(filenames[0]);
        std::cout << "Filename only: " << filename << "\n";

        // Get extension only
        std::string ext = viper::file::GetExtension(filenames[0]);
        std::cout << "Extension: " << ext << "\n\n";
    }

    // Read and display text file
    std::cout << "Text File Reading:\n";
    std::string str;
    bool success = viper::file::ReadTextFile("test.txt", str);
    if (success) {
        std::cout << "Contents of test.txt:\n";
        std::cout << str << "\n";
    }
    else {
        std::cout << "Failed to read test.txt\n";
    }


	// Initialize the engine
	viper::GetEngine().Initialize();

	std::unique_ptr<SpaceGame> game = std::make_unique<SpaceGame>();
    game->Initialize();
  

    // Load sounds into the audio system

    viper::GetEngine().GetAudio().AddSound("bass.wav", "base");
    viper::GetEngine().GetAudio().AddSound("snare.wav", "snare");
    viper::GetEngine().GetAudio().AddSound("clap.wav", "clap");
    viper::GetEngine().GetAudio().AddSound("cowbell.wav", "cowbell");
    viper::GetEngine().GetAudio().AddSound("close-hat.wav", "close-hat");
    viper::GetEngine().GetAudio().AddSound("open-hat.wav", "open-hat");

    /*
    viper::Font* font = new viper::Font();
    font->Load("Madina.ttf", 60);
    viper::Text *text = new viper::Text(font);
    text->Create(viper::GetEngine().GetRenderer(), "Hello World", viper::vec3{1, 1, 1});
    */

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
        game->Update(viper::Time.GetTime());
        game->Draw();

        //text->Draw(viper::GetEngine().GetRenderer(), 40.0f, 40.0f);

        // Present the rendered frame
        viper::GetEngine().GetRenderer().Present();
    }

	viper::GetEngine().Shutdown();  
    game->Shutdown();
    return 0;
}