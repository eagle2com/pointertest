#pragma once
#include <cstdio>
#include "defs.h"

#define EVENT_CLASS(T) template class Wrapper<T>

class BaseWrapper
{
public:
	BaseWrapper();
	virtual void* Call(void*);
};


template <class T>
class Wrapper : public BaseWrapper
{
public:
	Wrapper(T* object, void* (T::* pfunc)(void*) );
	virtual void* Call(void*);

private:
	void* (T::* m_pfunc)(void*) ;
	T* m_object;
};

EVENT_CLASS(Test);
EVENT_CLASS(Another);