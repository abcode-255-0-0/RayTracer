#pragma once

#include "Vector.h"

class Ray
{
public:

	Ray() { }
	Ray(Vec3 origin, Vec3 direction) { mOrigin = origin; mDirection = direction; }

	Vec3 getOrigin() const { return mOrigin; }
	Vec3 getDirection() const { return mDirection; }

	Vec3 getPointAtTime(float t) const { return mOrigin + mDirection * t; }
	Vec3 rayAdvance(float t) { mOrigin = mOrigin + mDirection * t; }

	Vec3 mOrigin;
	Vec3 mDirection;
};

float isSphereHit(const Vec3& center, float radius, const Ray& ray)
{
	Vec3 oc = ray.getOrigin() - center;
	float a = dot(ray.getDirection(), ray.getDirection());
	float b = 2.0f * dot(ray.getDirection(), oc);
	float c = dot(oc, oc) - (radius * radius);

	float discriminant = (b*b) - (4 * a*c);
	
	if (discriminant < 0)
		return -1.0f;
	else
	{
		return (-b - sqrt(discriminant)) / (2.0f *a);
	}
}

Vec3 getColor(const Ray& ray)
{
	Vec3 sphereCenter = Vec3(0.0f, 0.0f, -1.0f);
	float t = isSphereHit(sphereCenter, 0.5f, ray);
	if (t > 0.0f)
	{
		Vec3 norm = normalize(ray.getPointAtTime(t) - sphereCenter);
		return (norm + Vec3(1.0f, 1.0f, 1.0f)) * 0.5f;
	}
	Vec3 normDirection = normalize(ray.getDirection());
	t = (normDirection.y + 1.0f) * 0.5f;
	return (1.0f - t) * Vec3(1.0f, 1.0f, 1.0f) + t * Vec3(0.5f, 0.7f, 1.0f);
}