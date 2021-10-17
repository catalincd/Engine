#include "World.h"

Core::World G_World;
extern Core::InputManager G_Input;

namespace Core
{
	World::World()
	{

	}

	void World::ComputeBucketLimits(vector2 resolution)
	{
		LimitBucket = resolution / BucketSize;
		LimitBucket = vector2(int(LimitBucket.x) + 2, int(LimitBucket.y) + 2);
	}

	LightStack World::GetLights(const Entity& entity)
	{
		vector2 cursorPos = G_Input.GetCursorPosition();
		vector3 lightPos = { cursorPos.x, cursorPos.y, 1 };
		vector3 lightPos1 = { cursorPos.x, cursorPos.y - 150, 1 };
		vector3 lightPos2 = { cursorPos.x + 150, cursorPos.y + 130, 1 };
		vector3 lightPos3 = { cursorPos.x - 150, cursorPos.y + 130, 1 };

		vector4 lightColor = { 0.0f, 0.5f, 1.0f, 1.0f };
		vector3 lightFallOff = { 0.01f, 30.0f, 40.0f };

		Light light = { lightPos, lightFallOff, lightColor };
		LightStack stack;
		stack.LightCount = 4;
		stack.Lights[0] = { lightPos, lightFallOff, lightColor };
		stack.Lights[1] = { lightPos1, lightFallOff, lightColor };
		stack.Lights[2] = { lightPos2, lightFallOff, lightColor };
		stack.Lights[3] = { lightPos3, lightFallOff, lightColor };

		return stack;
	}

	vector2 World::GetBucketSize() const
	{
		return BucketSize;
	}

	vector2 World::GetBucketLimit() const
	{
		return LimitBucket;
	}

	void World::SetBucketSize(vector2 v)
	{
		BucketSize = v;
	}

	Color World::GetBackgroundColor() const
	{
		return BackgroundColor;
	}

	void World::SetBackgroundColor(Color color)
	{
		BackgroundColor = color;
	}

	Color World::GetAmbientColor() const
	{
		return AmbientColor;
	}

	void World::SetAmbientColor(Color color)
	{
		AmbientColor = color;
	}
}