#pragma once
#include <algorithm>
#include <cmath>
namespace viper::math {
	/// <summary>
	/// Represents the mathematical constant pi (π) as a floating-point value.
	/// </summary>
	constexpr float pi = 3.14159265358979323846f; // Use 'f' suffix to ensure the literal is treated as a float
	constexpr float twoPi = 2 * pi;
	constexpr float halfPi = pi * 0.5f;

	/// <summary>
	/// Converts an angle from radians to degrees.
	/// </summary>
	/// <param name="rad">The angle in radians to convert.</param>
	/// <returns>The equivalent angle in degrees.</returns>
	constexpr float radToDeg(float rad) { return rad * (180 / pi); }
	constexpr float degToRad(float deg) { return deg * (pi / 180); }


	using std::min;
	using std::max;
	using std::clamp;
	using std::sqrt;
	using std::sqrtf;
	using std::sin;
	using std::sinf;
	using std::cos;
	using std::cosf;
	using std::atan2;
	using std::atan2f;
}
