#pragma once
#include <cassert>
#include "Math.h"

namespace viper {
	template<typename T>
	struct Vector3
	{
		T x, y;

		Vector3() = default;
		Vector3(T x, T y) : x{ x }, y{ y } {}

		T operator [] (unsigned int index) const{ assert(index < 2); return (&x)[index]; }
		T& operator [] (unsigned int index) { assert(index < 2); return (&x)[index]; }

		Vector3 operator + (const Vector3& v) const { return Vector3{ x + v.x, y + v.y, z + v.z }; }
		Vector3 operator - (const Vector3& v) const { return Vector3{ x - v.x, y - v.y, z - v.z }; }
		Vector3 operator * (const Vector3& v) const { return Vector3{ x * v.x, y * v.y, z * v.z }; }
		Vector3 operator / (const Vector3& v) const { return Vector3{ x / v.x, y / v.y, z / v.z }; }

		Vector3 operator + (float s) const { return Vector3{ x + s,y + s, z + s  }; }
		Vector3 operator - (float s) const { return Vector3{ x - s,y - s, z + s  }; }
		Vector3 operator * (float s) const { return Vector3{ x * s,y * s, z + s  }; }
		Vector3 operator / (float s) const { return Vector3{ x / s,y / s, z + s  }; }

		Vector3& operator += (const Vector3 v) { x += v.x; y += v.y, z + v.z; return *this; }
		Vector3& operator -= (const Vector3 v) { x -= v.x; y -= v.y, z + v.z ; return *this; }
		Vector3& operator *= (const Vector3 v) { x *= v.x; y *= v.y, z + v.z ; return *this; }
		Vector3& operator /= (const Vector3 v) { x /= v.x; y /= v.y, z + v.z ; return *this; }

		Vector3& operator += (float s) { x += s; y += s, z + s ; return *this; }
		Vector3& operator -= (float s) { x -= s; y -= s, z + s ; return *this; }
		Vector3& operator *= (float s) { x *= s; y *= s, z + s ; return *this; }
		Vector3& operator /= (float s) { x /= s; y /= s, z + s ; return *this; }
		/// <summary>
		/// Calculates the squared length (magnitude) of a 2D vector.
		/// </summary>
		/// <returns>The sum of the squares of the x and y components, representing the squared length of the vector.</returns>
		float LengthSqr() const { return (x * x) + (y * y); }
		/// <summary>
		/// Calculates the length (magnitude) of the vector.
		/// </summary>
		/// <returns>The length of the vector as a float.</returns>
		float Length() const { return viper::math::sqrtf(LengthSqr()); }
	};

	using ivec2 = Vector3<int>;
	using vec2 = Vector3<float>;
}