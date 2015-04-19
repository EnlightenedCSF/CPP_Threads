#include "Thread.h"

#include <iostream>

Thread::~Thread()
{
	if (!isMain_)
		std::cout << "Deleting thread...\n";
	else
		std::cout << "Deleting main thread...\n";
}
