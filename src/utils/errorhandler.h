#pragma once
#include "../basic.h"

namespace Core
{
	class ErrorHandler
	{
	public:
		static void Log(std::string errorText);
		static void Log(std::vector<GLchar> errorText);
	};
}