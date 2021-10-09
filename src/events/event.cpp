#include "EventManager.h"
#include "event.h"

extern Core::EventManager G_EventManager;

namespace Core
{
	Event::Event()
	{
		G_EventManager.AddEvent(this);
	}

	void Event::AddFunction(Function function)
	{
		m_functions.push_back(function);
	}

	void Event::Trigger()
	{
		for (int i = 0; i < m_functions.size(); i++)
			m_functions[i]();
	}
}