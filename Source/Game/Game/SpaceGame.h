#pragma once
#include "Framework/Game.h"

class spaceGame : public viper::Game {
	public:
		spaceGame() = default;

		bool Initialize();
		void Shutdown();

		void Update();
		void Draw();
	
	private:
};