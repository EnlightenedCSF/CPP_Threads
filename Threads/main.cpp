// Threads.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <Windows.h>

#include "OperatingSystem.h"

int main()
{
	OperatingSystem os;
	os.showLibraries();
	
	std::cout << "\n\n";

	os.showProcesses();

	system("pause");
	return 0;
}

