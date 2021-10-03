#pragma once

namespace Core
{
	class Math
	{
	public:

		const float PI = 3.141592;
		float d2r = PI / 180.0f;
		float r2d = 180.0f / PI;

		float DegreeToRadian(float alpha)
		{
			return alpha * d2r;
		}

		float RadianToDegree(float alpha)
		{
			return alpha * r2d;
		}
	};
}