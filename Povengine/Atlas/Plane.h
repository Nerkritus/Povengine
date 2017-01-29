#pragma once
#include "PhysicsEntity.h"

namespace Atlas
{
	class Plane : public PhysicsEntity
	{
	public:
		Plane(float size, float x, float y, float z, unsigned int shaderProgramID);

		virtual void InitData();
	};
}