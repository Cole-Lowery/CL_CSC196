#pragma once
#include "Vector2.h"
namespace viper {
	struct Transform {
		vec2 position{ 0,0 };
		float rotation = 0 ;
		float scale = 1;

		Transform() = default;
		Transform(const vec2& pos, float rot = 0, float scl = 1)
			: position(pos), rotation(rot), scale(scl) {}
	};
}