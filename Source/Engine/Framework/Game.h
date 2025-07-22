#pragma once 
#include <memory>

namespace viper{
	class Game {
		public:
		Game() = default;
		bool Initialize();
		void Shutdown();
		void Update();
		void Draw();

	protected:
		std::unique_ptr<class Scene> m_scene; // Scene containing all actors
	};

}