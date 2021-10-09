#include "EventManager.h"

Core::EventManager G_EventManager;

namespace Core
{
	void EventManager::AddEvent(Event* event)
	{
		m_events.push_back(event);
	}
}