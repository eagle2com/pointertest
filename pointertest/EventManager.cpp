#include "EventManager.h"



EventManager::EventManager()
{
}


EventManager::~EventManager()
{
}

void EventManager::Register(int id, BaseWrapper* w)
{
	m_map[id] = w;
}

void EventManager::Send(int id)
{
	CallMap::iterator it = m_map.find(id);
	if (it != m_map.end())
		(*it).second->Call(nullptr);
}