#pragma once
#include <cstdio>

class Test
{
public:
	Test(){}
	virtual void* vfunc(void* data)
	{
		printf_s("Hello from Test\n");
		return nullptr;
	}
protected:

};

class Another
{
public:
	Another(){}
	void* lol(void* data)
	{
		printf_s("Hello from Another\n");
		return nullptr;
	}
};

class TestChild : public Test
{
public:
	TestChild(){}
	virtual void* vfunc(void* data)
	{
		printf_s("Hello from TestChild\n");
		return nullptr;
	}
};