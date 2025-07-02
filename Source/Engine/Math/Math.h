#pragma once
#include <algorithm>
namespace viper {
	/// <summary>
	/// Represents the mathematical constant pi (π) as a floating-point value.
	/// </summary>
	constexpr float pi = 3.1415926535897932384626433832795;
	constexpr float twoPi = 2 * pi;
	constexpr float halfPi = pi * 0.5f;

	/// <summary>
	/// Converts an angle from radians to degrees.
	/// </summary>
	/// <param name="rad">The angle in radians to convert.</param>
	/// <returns>The equivalent angle in degrees.</returns>
	constexpr float radToDeg(float rad) { return rad * (180/pi); }
	constexpr float degToRad(float deg) { return deg * (pi/180); }
	

	using std::min; 
	using std::max;
	//using std::clamp;
}
