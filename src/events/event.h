#pragma once
#include "../basic.h"

namespace Core
{
	class Event
	{
		std::vector<Function> m_functions;

	public:

		Event();

		void AddFunction(Function function);

		void Trigger();
	};
}