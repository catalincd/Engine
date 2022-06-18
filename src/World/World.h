#pragma once
#include "../basic.h"
#include "../Entity/Entity.h"
#include "../Renderer/Renderer.h"
#include "../Input/Input.h"

namespace Core
{
	class World
	{
		vector2 BucketSize = vector2(256, 256);
		vector2 LimitBucket = vector2(9, 6);
		Color AmbientColor = Color(0.8f, 0.8f, 0.8f, 1.0f);
		Color BackgroundColor = Color(0x333333FF);

	public:

		World();

		void ComputeBucketLimits(vector2 resolution);
		
		LightStack GetLights(const Entity& entity);
		

		vector2 GetBucketLimit() const;
		vector2 GetBucketSize() const;
		void SetBucketSize(vector2 v);

		Color GetBackgroundColor() const;
		void SetBackgroundColor(Color color);

		Color GetAmbientColor() const;
		void SetAmbientColor(Color color);
	};
}