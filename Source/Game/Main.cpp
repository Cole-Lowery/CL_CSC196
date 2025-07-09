#include "Math/Math.h"
#include "Math/Vector2.h" 
#include "Core/Random.h"
#include "Core/Time.h"
#include <SDL3/SDL.h>
#include <iostream>
#include <Renderer/Renderer.h>
#include <vector>
#include "Input/InputSystem.h"
int main(int argc, char* argv[]) {
    viper::Time time;
    viper::Renderer renderer;

    renderer.Initialize();
    renderer.CreateWindow("Viper Engine", 1280, 1024);

    viper::InputSystem input;
    input.Initialize();

    SDL_Event e;
    bool quit = false;

    std::vector<viper::vec2> stars;
    for (int i = 0; i < 100; i++) {
        stars.push_back(viper::vec2(viper::random::getRandomFloat() * 1280, viper::random::getRandomFloat() * 1024));
    }
    

    while (!quit) {
        time.Tick();
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }   
        }

        input.Update();
        if (input.GetKeyPressed(SDL_SCANCODE_A)) {
            std::cout << "pressed\n";
        }
        if (input.GetMouseButtonDown(0)){
            std::cout << "pressed\n";
        }

        viper::vec2 mouse = input.GetMousePosition();
        std::cout << mouse.x << " " << mouse.y << std::endl;


        renderer.SetColor(0, 0, 0);
        renderer.Clear();

        viper::vec2 speed{ -0.1f, 0.0f };
        float length = speed.Length();
        for (viper::vec2 star : stars) {
            star += speed * time.GetDeltaTime();

            if (star[0] > 1280) star[0] = 5;
            if (star.x > 0) star[0] = 1280;

            renderer.SetColor(viper::random::getRandomInt(0, 255), viper::random::getRandomInt(0, 255), viper::random::getRandomInt(0, 255));
            renderer.DrawPoint(star.x, star.y);
        }

        /*for (int i = 0; i < 10; i++) {
            renderer.SetColor(viper::random::getRandomInt(0, 256), viper::random::getRandomInt(0, 256), viper::random::getRandomInt(0, 256));
            renderer.DrawLine(viper::random::getRandomFloat() * 1280, viper::random::getRandomFloat() * 1280, viper::random::getRandomFloat() * 1280, viper::random::getRandomFloat() * 1280);
        }

        for (int i = 0; i < 20; i++) {
            renderer.SetColor(viper::random::getRandomInt(0, 256), viper::random::getRandomInt(0, 256), viper::random::getRandomInt(0, 256));
            renderer.DrawPoint(viper::random::getRandomFloat() * 1280, viper::random::getRandomFloat() * 1280);
        }*/

        //renderer.SetColor(viper::random::getRandomInt(0, 256), viper::random::getRandomInt(0, 256), viper::random::getRandomInt(0, 256));
        //renderer.DrawPoint(v.x, v.y);

        renderer.Present();
    }

    renderer.Shutdown();

    return 0;
}