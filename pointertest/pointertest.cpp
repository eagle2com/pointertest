#include "stdafx.h"
#include "wrapper.h"
#include "EventManager.h"
#include "defs.h"

#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{
	Test* t1 = new Test();
	Test* t2 = new TestChild();
	Another* t3 = new Another();

	
	Wrapper<Test>* w1 = new Wrapper<Test>(t1, &Test::vfunc);
	Wrapper<Test>* w2 = new Wrapper<Test>(t2, &Test::vfunc);
	Wrapper<Another>* w3 = new Wrapper<Another>(t3, &Another::lol);

	EventManager manager;
	manager.Register(E1, w1);
	manager.Register(E2, w2);
	manager.Register(E3, w3);

	manager.Send(E1);
	manager.Send(E2);
	manager.Send(E3);
	while (true)
	{
		int e;
		std::cin >> e;
		manager.Send(e);
		if (e == -1)
			break;
	}

	delete w1,w2,w3,t1, t2, t3;

	return 0;
}

