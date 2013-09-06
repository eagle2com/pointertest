#pragma once
#include "wrapper.h"
#include <map>

typedef std::map<int,BaseWrapper*> CallMap;

enum{E1=1,E2,E3};

class EventManager
{
public:
	EventManager();
	~EventManager();
	void Register(int,BaseWrapper*);
	void Send(int);

private:
	CallMap m_map;
};

