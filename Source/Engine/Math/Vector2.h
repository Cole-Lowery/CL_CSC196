#pragma once
#include <cassert>
#include "Math.h"

namespace viper {
	template<typename T>
	struct Vector2
	{
		union {
			struct { T x, y; };
			struct { T u, v; };
		};

		Vector2() = default;
		Vector2(T x, T y) : x{ x }, y{ y } {}

		T operator [] (unsigned int index) const{ assert(index < 2); return (&x)[index]; }
		T& operator [] (unsigned int index) { assert(index < 2); return (&x)[index]; }

		Vector2 operator + (const Vector2& v) const { return Vector2{ x + v.x, y + v.y }; }
		Vector2 operator - (const Vector2& v) const { return Vector2{ x - v.x, y - v.y }; }
		Vector2 operator * (const Vector2& v) const { return Vector2{ x * v.x, y * v.y }; }
		Vector2 operator / (const Vector2& v) const { return Vector2{ x / v.x, y / v.y }; }

		Vector2 operator + (float s) const { return Vector2{ x + s,y + s }; }
		Vector2 operator - (float s) const { return Vector2{ x - s,y - s }; }
		Vector2 operator * (float s) const { return Vector2{ x * s,y * s }; }
		Vector2 operator / (float s) const { return Vector2{ x / s,y / s }; }

		Vector2& operator += (const Vector2 v) { x += v.x; y += v.y; return *this; }
		Vector2& operator -= (const Vector2 v) { x -= v.x; y -= v.y; return *this; }
		Vector2& operator *= (const Vector2 v) { x *= v.x; y *= v.y; return *this; }
		Vector2& operator /= (const Vector2 v) { x /= v.x; y /= v.y; return *this; }

		Vector2& operator += (float s) { x += s; y += s; return *this; }
		Vector2& operator -= (float s) { x -= s; y -= s; return *this; }
		Vector2& operator *= (float s) { x *= s; y *= s; return *this; }
		Vector2& operator /= (float s) { x /= s; y /= s; return *this; }
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

		/// <summary>
		/// Returns a normalized (unit length) version of the vector.
		/// </summary>
		/// <returns>A new Vector2 instance representing the normalized (unit) vector.</returns>
		Vector2 Normalized() const { return *this / Length(); }

		/// <summary>
		/// Calculates the angle, in radians, of the vector from the origin to the point (x, y).
		/// </summary>
		/// <returns>The angle in radians between the positive x-axis and the vector (x, y), computed using atan2f(y, x).</returns>
		float Angle() const {
			return viper::math::atan2f(y, x);
		}	
		Vector2 Rotate(float radians) const {
			Vector2 v;

			v.x = x * viper::math::cosf(radians) - y * viper::math::sinf(radians);
			v.y = x * viper::math::sinf(radians) + y * viper::math::cosf(radians);

			return v; // Return the rotated vector
		}
		static float Dot(const Vector2& a, const Vector2& b) {

			return a.x * b.x + a.y * b.y;

		}
		static float AngleBetween(const Vector2& a, const Vector2& b) {

			return math::acosf(Dot(a, b));

		}
		static float Cross(const Vector2& a, const Vector2& b) {

			return a.x * b.y - a.y * b.x;

		}

		static float SignedAngleBetween(const Vector2& a, const Vector2& b) {

			Vector2 v{ Dot(a,b), Cross(a,b) };

			return v.Angle();

		}

	};

	using ivec2 = Vector2<int>;
	using vec2 = Vector2<float>;
}