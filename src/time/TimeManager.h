#pragma once
#include "../basic.h"

namespace Core
{
	float GetTimeF();

	uint GetTime();

	float GetLastFrameElapsedTimeF();

	uint GetLastFrameElapsedTime();

	float GetFPSRateF();

	uint GetFPSRate();

	uint GetAverageFPS();

	class TimeManager
	{
		float Factor = 1.0f;
		float TargetFPS = 60.0f;
		float CurrentFrameStartTime = 0.0f;
		uint CurrentSleepTime = 0;
	public:
		void Update();
		void Sleep();

		float GetFactor()
		{
			return Factor;
		}

		void SetFactor(float factor);
		void SetCurrentFrameStartTime(float time);
	};
}