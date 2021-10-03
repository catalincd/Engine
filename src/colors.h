#if 0
#define DEFINED_COLORS
#include "linmath.h"
#include "utils/color.h"

namespace Core
{
	struct Colors
	{
		vec4 V4_WHITE = { 1.0f, 1.0f, 1.0f, 1.0f };
		vec4 V4_RED = { 1.0f, 0.0f, 0.0f, 1.0f };
		vec4 V4_GREEN = { 0.0f, 1.0f, 0.0f, 1.0f };
		vec4 V4_BLUE = { 0.0f, 0.0f, 1.0f, 1.0f };
		vec4 V4_BLACK = { 0.0f, 0.0f, 0.0f, 1.0f };

		Color WHITE = Color(0xFFFFFFFF);
		Color RED = Color(0xFF0000FF);
		Color GREEN = Color(0x00FF00FF);
		Color BLUE = Color(0x0000FFFF);
		Color BLACK = Color(0x00000000);
	};
}

#endif // !

