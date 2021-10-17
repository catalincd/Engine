#pragma once
#include "../basic.h"
#define MAX_LIGHTS 4

namespace Core
{
	struct Light
	{
		vector3 Position;
		vector3 Falloff;
		vector4 Color;
	};

	struct LightStack
	{
		int LightCount;
		Light Lights[MAX_LIGHTS];
	};
}