#include "SpaceGame.h"
#include "Framework/Scene.h"
#include "Math/vector2.h"
#include "Engine.h"
#include "Renderer/Model.h"
#include "../Game/Player.h"
#include "Core/Random.h"
#include "Renderer/Renderer.h"
#include "../Game/Enemy.h"

#include <vector>

bool spaceGame::Initialize(){
	m_scene = std::make_unique<viper::Scene>();
    // Define the points for the initial model (a custom shape)
    std::vector<viper::vec2> points{
        { 0, 0 },
        { -4, -2 },
        { 6, 0 },
        { -4, 2 },
        { 0, 0 },
        { -4, 3 },
        { 6, 0 },
        { -4, -3 },
        { 0, 0 },
        { -4, -1 },
        {   0, 0 },
        { -4, 1 },
        { 0, 0 },
        { -4, 0 },
        {  0, 0 },
    };

    std::shared_ptr<viper::Model> model = std::make_shared<viper::Model>(points, viper::vec3{ 0, 0, 1 });

    m_scene = std::make_unique<viper::Scene>();
    // Draw all actors

    viper::Transform transform{ { viper::GetEngine().GetRenderer().GetWidth() * 0.5f , viper::GetEngine().GetRenderer().GetHeight() * 0.5f}, 0, 10};
    std::unique_ptr<Player> player = std::make_unique<Player>(transform, model);
    m_scene->AddActor(std::move(player));

	
    m_scene->Draw(viper::GetEngine().GetRenderer());
    

    /*for (int i = 0; i < 10; i++) {
        viper::Transform transform{ { viper::random::getRandomFloat() * 1280, viper::random::getRandomFloat() * 1024 }, 0, 10 };
        std::unique_ptr<Player> player = std::make_unique<Player>(transform, model);
        scene.AddActor(std::move(player));
    }*/
    return false;
}

void spaceGame::Shutdown()
{
    //
}

void spaceGame::Update()
{
    m_scene->Update(viper::GetEngine().GetTime().GetDeltaTime());
}

void spaceGame::Draw()
{
	m_scene->Draw(viper::GetEngine().GetRenderer());
}