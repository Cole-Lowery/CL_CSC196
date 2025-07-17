#pragma once 
#include "Scene.h"
#include "Actor.h"

namespace viper{
	/// <summary>
	/// Updates all actors in the scene by advancing their state based on the elapsed time.
	/// </summary>
	/// <param name="deltaTime">The time in seconds since the last update.</param>
	void Scene::Update(float deltaTime) {
		for (auto& actor : m_actors) {
			if (actor) {
				actor->Update(deltaTime);
			}
		}
	}
	/// <summary>
	/// Draws all actors in the scene using the specified renderer.
	/// </summary>
	/// <param name="renderer">The renderer used to draw the actors.</param>
	void viper::Scene::Draw(Renderer& renderer)
	{
		for (auto& actor : m_actors) {
			if (actor) {
				actor->Draw(renderer);
			}
		}
	}

	void Scene::AddActor(std::unique_ptr<class Actor> actor)
	{
		m_actors.push_back(std::move(actor));
	}

}