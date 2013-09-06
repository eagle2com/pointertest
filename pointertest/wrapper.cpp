#include "wrapper.h"



BaseWrapper::BaseWrapper()
{

}

void* BaseWrapper::Call(void* data)
{
	printf_s("BaseWrapper call, shouldnt happen\n");
	return nullptr;
}



template <class T>
Wrapper<T>::Wrapper(T* object, void* (T::* pfunc)(void*) ) : 
	m_pfunc(pfunc), m_object(object)
{
}

template <class T>
void* Wrapper<T>::Call(void* data)
{
	return (m_object->*m_pfunc)(nullptr);
}