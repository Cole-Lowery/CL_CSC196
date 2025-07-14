#include "Math/Math.h"
#include "Math/Vector2.h"
#include "Core/Random.h"
#include "Core/Time.h"
#include "Renderer/Renderer.h"
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"

#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    viper::Time time;
    viper::Renderer renderer;

    std::vector<viper::vec2> points;
    renderer.Initialize();
    renderer.CreateWindow("Viper Engine", 1280, 1024);

    viper::AudioSystem audio;
    audio.Initialize();

    viper::InputSystem input;
    input.Initialize();


	audio.Initialize();
	audio.AddSound("test.wav", "test");
	audio.AddSound("bass.wav", "bass");
	audio.AddSound("snare.wav", "snare");
	audio.AddSound("clap.wav", "clap");
	audio.AddSound("cowbell.wav", "cowbell");
	audio.AddSound("close-hat.wav", "close-hat");
	audio.AddSound("open-hat.wav", "open-hat");

    SDL_Event e;
    bool quit = false;
    

    while (!quit) {
        time.Tick();
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        if (input.GetKeyDown(SDL_SCANCODE_ESCAPE)) {
			quit = true;
    }
        audio.Update();
        input.Update();

        if (input.GetMouseButtonPressed(viper::InputSystem::MouseButton::Left)) {
            points.push_back(input.GetMousePosition());
        }

        if (input.GetMouseButtonDown(viper::InputSystem::MouseButton::Left)) {
            viper::vec2 position = input.GetMousePosition();
            if (points.empty()) points.push_back(position);
            else if ((position - points.back()).Length() > 10) points.push_back(position);
        }
        
		if (input.GetKeyDown(SDL_SCANCODE_Q)) audio.PlaySound("bass");
		if (input.GetKeyDown(SDL_SCANCODE_W)) audio.PlaySound("snare");
		if (input.GetKeyDown(SDL_SCANCODE_E)) audio.PlaySound("clap");
		if (input.GetKeyDown(SDL_SCANCODE_R)) audio.PlaySound("cowbell");
		if (input.GetKeyDown(SDL_SCANCODE_T)) audio.PlaySound("close-hat");
        if (input.GetKeyDown(SDL_SCANCODE_Y)) audio.PlaySound("open-hat");

        renderer.SetColor(0, 0, 0);
        renderer.Clear();

        viper::vec2 speed{ 140.0f, 0.0f };
        float length = speed.Length();

        for (int i = 0; i < (int)points.size() - 1; i++) {
            renderer.SetColor(viper::random::getRandomInt(0, 256), viper::random::getRandomInt(0, 256), viper::random::getRandomInt(0, 256));
            renderer.DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
        }

        for (int i = 0; i < (int)points.size() - 1; i++) {
            renderer.SetColor(viper::random::getRandomInt(0, 256), viper::random::getRandomInt(0, 256), viper::random::getRandomInt(0, 256));
            renderer.DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
        }

        renderer.Present();
    }
	audio.Shutdown();  
    renderer.Shutdown();

    return 0;
}