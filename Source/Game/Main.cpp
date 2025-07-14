#include "Math/Math.h"
#include "Math/Vector2.h"
#include "Core/Random.h"
#include "Core/Time.h"
#include <SDL3/SDL.h>
#include <iostream>
#include <Renderer/Renderer.h>
#include <vector>
#include <Input/InputSystem.h>
#include <fmod.hpp>

int main(int argc, char* argv[]) {
    viper::Time time;
    viper::Renderer renderer;

    std::vector<viper::vec2> points;
    renderer.Initialize();
    renderer.CreateWindow("Viper Engine", 1280, 1024);

    FMOD::System* audio;
    FMOD::System_Create(&audio);

    void* extradriverdata = nullptr;
    audio->init(32, FMOD_INIT_NORMAL, extradriverdata);

    viper::InputSystem input;
    input.Initialize();

    SDL_Event e;
    bool quit = false;
    
    FMOD::Sound* sound = nullptr;
    audio->createSound("test.wav", FMOD_DEFAULT, 0, &sound);

    std::vector<FMOD::Sound*> sounds;
    audio->createSound("bass.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);

    audio->createSound("snare.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);

    audio->createSound("clap.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);

    audio->createSound("cowbell.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);

    audio->createSound("close-hat.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);

    audio->createSound("open-hat.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);

    audio->playSound(sound, 0, false, nullptr);

    while (!quit) {
        time.Tick();
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        if (input.GetKeyDown(SDL_SCANCODE_Q) && !input.GetPrevKeyDown(SDL_SCANCODE_Q))
    {
            if (!sounds.empty()) {
            audio->playSound(sounds[0], nullptr, false, nullptr);
			}
    }
        if (input.GetKeyDown(SDL_SCANCODE_W) && !input.GetPrevKeyDown(SDL_SCANCODE_W))
        {
            if (sounds.size() > 1) {
                audio->playSound(sounds[1], nullptr, false, nullptr);
            }
        }
        if (input.GetKeyDown(SDL_SCANCODE_E) && !input.GetPrevKeyDown(SDL_SCANCODE_E))
		{
            if (sounds.size() > 2) {
                audio->playSound(sounds[2], nullptr, false, nullptr);
            }
		}

		if (input.GetKeyDown(SDL_SCANCODE_R) && !input.GetPrevKeyDown(SDL_SCANCODE_R))
		{
                     if (sounds.size() > 3) {
                audio->playSound(sounds[3], nullptr, false, nullptr);
			}
		}
		if (input.GetKeyDown(SDL_SCANCODE_T) && !input.GetPrevKeyDown(SDL_SCANCODE_T))
            {
            if (sounds.size() > 4) {
				audio->playSound(sounds[4], nullptr, false, nullptr);
                }
		}
		if (input.GetKeyDown(SDL_SCANCODE_Y) && !input.GetPrevKeyDown(SDL_SCANCODE_Y))
            {
			if (sounds.size() > 5) {
				audio->playSound(sounds[5], nullptr, false, nullptr);
			}
		}

        if (input.GetKeyDown(SDL_SCANCODE_ESCAPE)) {
			quit = true;
    }
        audio->update();
        input.Update();

        if (input.GetMouseButtonPressed(viper::InputSystem::MouseButton::Left)) {
            points.push_back(input.GetMousePosition());
        }

        if (input.GetMouseButtonDown(viper::InputSystem::MouseButton::Left)) {
            viper::vec2 position = input.GetMousePosition();
            if (points.empty()) points.push_back(position);
            else if ((position - points.back()).Length() > 10) points.push_back(position);
        }

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
    renderer.Shutdown();

    return 0;
}