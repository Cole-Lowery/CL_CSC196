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

    std::vector<viper::vec2> points;

    while (!quit) {
        time.Tick();
        input.Update();

        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }
        renderer.SetColor(0, 0, 0);
        renderer.Clear();

   
        static viper::vec2 prevMousePosition = input.GetMousePosition();
        viper::vec2 currentMousePosition = input.GetMousePosition();

       
        viper::vec2 dir = currentMousePosition - prevMousePosition;

       
        float length = std::sqrt(dir.x * dir.x + dir.y * dir.y);
        if (length != 0) {
            dir.x /= length;
            dir.y /= length;
        }

        float desiredLength = 100.0f;

        viper::vec2 extendedEnd = prevMousePosition + dir * desiredLength;

        if (input.GetMouseButtonDown(viper::InputSystem::MouseButton::Left)) {
            renderer.SetColor(255, 0, 0);
            renderer.DrawLine(prevMousePosition.x, prevMousePosition.y, extendedEnd.x, extendedEnd.y);
        }

        prevMousePosition = currentMousePosition;

        input.Update();
        if (input.GetKeyPressed(SDL_SCANCODE_A)) {
            std::cout << "pressed\n";
        }

        viper::vec2 mouse = input.GetMousePosition();
        std::cout << mouse.x << " " << mouse.y << std::endl;

        for (int i = 0; i < (int)points.size() - 1; i++) {
            renderer.SetColor(255, 255, 255);
            renderer.DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
        }

        renderer.Present();

       
    }

    renderer.Shutdown();

    return 0;
}