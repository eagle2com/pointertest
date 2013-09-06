#pragma once
#include <cstdio>

class BaseWrapper
{
public:
	BaseWrapper(){}
	virtual void* Call(void* data)
	{
		printf_s("BaseWrapper call, shouldnt happen\n");
		return nullptr;
	};
};

template <class T>
class Wrapper : public BaseWrapper
{
public:
	Wrapper(T* object, void* (T::* pfunc)(void*) ) : m_pfunc(pfunc), m_object(object){}
	virtual void* Call(void* data)
	{
		return (m_object->*m_pfunc)(nullptr);
	}

private:
	void* (T::* m_pfunc)(void*) ;
	T* m_object;
};