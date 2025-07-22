#include "SpaceGame.h"
#include "Framework/Scene.h"
#include "Math/vector2.h"
#include "Engine.h"
#include "Renderer/Model.h"
#include "../Game/Player.h"
#include "Core/Random.h"

#include <vector>

bool spaceGame::Initialize()
{
	m_scene = std::make_unique<viper::Scene>();
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
        scene.AddActor(std::move(player));
    }
    return false;
}

void spaceGame::Shutdown()
{
}

void spaceGame::Update()
{
}
