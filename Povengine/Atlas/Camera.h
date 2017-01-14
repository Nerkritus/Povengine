#pragma once
#include "Transformable.h"

namespace Atlas
{
	class Camera
	{
	public:
		Camera();
		void SetPosition(float x, float y, float z);
		void SetLookAt(float x, float y, float z);

		glm::mat4 GetViewMatrix();

	private:

		void Update();

		glm::vec3 _camPos;
		glm::vec3 _camTarget;
		glm::vec3 _camDirection;
		glm::vec3 _camUp;
		glm::vec3 _upVec;
		glm::vec3 _rightVec;

		glm::mat4 _viewMat;

		bool _needsUpdate;
	};
}