#include "Vector.h"


Vec3::Vec3(float xin, float yin, float zin)
{
	x = xin;
	y = yin;
	z = zin;
}

 float Vec3::operator[](int i) const
{
	switch (i)
	{
	case 0:
		return x;
		break;
	case 1:
		return y;
		break;
	case 2:
		return z;
		break;
	}
}

 float& Vec3::operator[](int i)
{
	switch (i)
	{
	case 0:
		return x;
		break;
	case 1:
		return y;
		break;
	case 2:
		return z;
		break;
	}
}

 Vec3& Vec3::operator+=(const Vec3& v2)
{
	x = x + v2.x;
	y = y + v2.y;
	z = z + v2.z;
	
	return *this;
}

 Vec3& Vec3::operator-=(const Vec3& v2)
{
	x = x - v2.x;
	y = y - v2.y;
	z = z - v2.z;

	return *this;
}

 Vec3& Vec3::operator*=(const Vec3& v2)
{
	x = x * v2.x;
	y = y * v2.y;
	z = z * v2.z;

	return *this;
}


 Vec3& Vec3::operator/=(const Vec3& v2)
{
	x = x / v2.x;
	y = y / v2.y;
	z = z / v2.z;

	return *this;
}

 Vec3& Vec3::operator*=(const float t)
{
	x = x * t;
	y = y * t;
	z = z * t;

	return *this;
}

 Vec3& Vec3::operator/=(const float t)
{
	x = x / t;
	y = y / t;
	z = z / t;

	return *this;
}

 Vec3 Vec3::operator+(const Vec3& v2) const
{
	Vec3 output;
	output.x = x + v2.x;
	output.y = y + v2.y;
	output.z = z + v2.z;

	return output;
}

 Vec3 Vec3::operator-(const Vec3& v2) const
{
	Vec3 output;
	output.x = x - v2.x;
	output.y = y - v2.y;
	output.z = z - v2.z;

	return output;
}

 Vec3 Vec3::operator*(const Vec3& v2) const
{
	Vec3 output;
	output.x = x * v2.x;
	output.y = y * v2.y;
	output.z = z * v2.z;

	return output;
}

 Vec3 Vec3::operator/(const Vec3& v2) const
{
	Vec3 output;
	output.x = x / v2.x;
	output.y = y / v2.y;
	output.z = z / v2.z;

	return output;
}

 Vec3 Vec3::operator*(const float t) const
{
	Vec3 output;
	output.x = x * t;
	output.y = y * t;
	output.z = z * t;

	return output;
}

 Vec3 Vec3::operator/(const float t) const
{
	Vec3 output;
	output.x = x / t;
	output.y = y / t;
	output.z = z / t;

	return output;
}

 float Vec3::length() const
{
	return sqrt(x * x + y * y + z * z);
}

 float Vec3::squared_length() const
{
	return (x * x + y * y + z * z);
}

 void Vec3::normalize()
{
	*this = *this / length();
}

