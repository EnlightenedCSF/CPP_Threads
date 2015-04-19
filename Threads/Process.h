#pragma once

#include <vector>
#include <string>

#include "Thread.h"
#include "Library.h"

class OperatingSystem;

class Process
{
public:
	Process(int id, std::string name, OperatingSystem *system) : id_(id), name_(name), system_(system) {
		threads_.push_back(new Thread(true));
	};
	virtual ~Process();

	int getThreadCount() { return threads_.size(); }
	std::string getName() { return name_;  }
	
	void createNewThread();
	bool killThread(int index);

	void loadLibrary(Library* library);
	bool didLoadedLibrary(Library* library);

private:
	int id_;
	std::string name_;
	std::vector<Thread*> threads_;
	std::vector<Library*> libraries_;

	OperatingSystem *system_;
};

