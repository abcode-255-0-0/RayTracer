#pragma once

#include <math.h>
#include <stdlib.h>
#include <iostream>

class Vec3
{
public:

	Vec3() {}
	Vec3(float xin, float yin, float zin);

	inline const Vec3 operator+() const { return *this; }
	inline Vec3		  operator-() { return Vec3(-x, -y, -z); }
	float operator[](int i) const;
	float& operator[](int i);

	Vec3& operator+=(const Vec3& v2);
	Vec3& operator-=(const Vec3& v2);
	Vec3& operator*=(const Vec3& v2);
	Vec3& operator/=(const Vec3& v2);
	Vec3& operator*=(const float t);
	Vec3& operator/=(const float t);

	Vec3 operator+(const Vec3& v2) const;
	Vec3 operator-(const Vec3& v2) const;
	Vec3 operator*(const Vec3& v2) const;
	Vec3 operator/(const Vec3& v2) const;

	Vec3 operator*(const float t) const;
	Vec3 operator/(const float t) const;

	float length() const;
	float squared_length() const;

	void normalize();

	float x, y, z;
};

inline float dot(const Vec3& v1, const Vec3& v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

inline Vec3 cross(const Vec3& v1, const Vec3& v2)
{
	return Vec3(v1.y * v2.z - v1.z * v2.y,
				v1.z * v2.x - v1.x * v2.z,
				v1.x * v2.y - v1.y * v2.x);
}

inline Vec3 normalize(Vec3 v1)
{
	return v1 / v1.length();
}

inline Vec3 operator*(const float t, const Vec3& v)
{
	return Vec3(v * t);
}

inline Vec3 operator/(const float t, const Vec3& v)
{
	return Vec3(v / t);
}