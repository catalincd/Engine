#pragma once
#include "../basic.h"
#include "event.h"

namespace Core
{
	class EventManager
	{
		std::vector<Event*> m_events;
	public:

		void AddEvent(Event* event); 
	};
}