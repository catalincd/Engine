#include "TimeManager.h"
#include "../utils/math.h"
#include <chrono>
#include <thread>



Core::TimeManager G_TimeManager;

namespace Core
{
	
	float TimeAtLastFrame = 0.0f;
	float AverageFrameRate = 0.0f;
	uint TotalFrames = 0;

	float GetTimeF()
	{
		return glfwGetTime() * 1000.0f;
	}

	uint GetTime()
	{
		return uint(glfwGetTime() * 1000.0f);
	}

	float GetLastFrameElapsedTimeF()
	{
		return (GetTimeF() - TimeAtLastFrame);
	}

	uint GetLastFrameElapsedTime()
	{
		return uint(GetLastFrameElapsedTimeF());
	}

	float GetFPSRateF()
	{
		return (1000.0f / GetLastFrameElapsedTimeF());
	}

	uint GetFPSRate()
	{
		return uint(1000.0f / GetLastFrameElapsedTimeF());
	}

	uint GetAverageFPS()
	{
		return static_cast<uint>(AverageFrameRate);
	}

	float UnitsPerSecond(float speed)
	{
		return float(double(speed) * double(min(GetLastFrameElapsedTime(), 200)) / 1000.0) * G_TimeManager.GetFactor();
	}

	void TimeManager::Update()
	{
		
		AverageFrameRate = (float(AverageFrameRate * TotalFrames) + GetLastFrameElapsedTimeF()) / (TotalFrames++);



		

		TimeAtLastFrame = GetTimeF();
	}

	void TimeManager::Sleep()
	{
		const float FrameTime = 1000.0f * (glfwGetTime() - CurrentFrameStartTime);
		const float delta = min(30, (1000.0f / TargetFPS) - FrameTime);
		CurrentSleepTime = static_cast<uint>(500.0f * delta);

		if (CurrentSleepTime > 0 && CurrentSleepTime < 30000)
		{
			//std::cout << "Sleep Time: " << CurrentSleepTime << std::endl;
			std::this_thread::sleep_for(std::chrono::microseconds(CurrentSleepTime));
		}
	}

	void TimeManager::SetFactor(float factor)
	{
		Factor = factor;
	}

	void TimeManager::SetCurrentFrameStartTime(float time)
	{
		CurrentFrameStartTime = time;
	}
}