#pragma once
#include <cmath> 

namespace math {

	struct vector2 {
		constexpr vector2(float x = 0.f, float y = 0.f) noexcept : x(x), y(y) {}
		float x, y;
	};
	struct vector3 {
		constexpr vector3(float x = 0.f, float y = 0.f, float z = 0.f) noexcept : x(x), y(y), z(z) {}
		const bool WorldToScreen(vector2& out, float(*ViewMatrix)[4][4]);
		float x, y, z;
	};
	struct vector4 {
		float x{ 0.f }, y{ 0.f }, z{ 0.f }, w{ 0.f };
	};
}