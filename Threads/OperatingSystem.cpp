#include "OperatingSystem.h"

#include <iostream>
#include <algorithm>

OperatingSystem::OperatingSystem()
{
	lastProcessId_ = 0;

	addLibrary("kernel32.dll");
	addLibrary("openAL32.dll");
	addLibrary("foundation.dll");

	addProcess("explorer.exe");
	addProcess("winlogon.exe");
	addProcess("taskeng.exe");
	addProcess("test.exe");

	/*auto proc = processes_[1];
	proc->createNewThread();
	proc->createNewThread();
	proc->loadLibrary(getLibraryByName("kernel32.dll"));
	
	proc->killThread(2);
	if (!proc->killThread(0)) {
		delete proc;
		processes_.erase(1);
	}

	killProcess("test.exe");*/ // <--- ето работаит

	auto proc = processes_[0];
	proc->loadLibrary(getLibraryByName("kernel32.dll"));
	deleteLibrary("kernel32.dll");
}

OperatingSystem::~OperatingSystem()
{
}

Library* OperatingSystem::getLibraryByName(std::string name) {
	return libraries_[name];
}

int OperatingSystem::getProcessIdByName(std::string name) {
	for (auto i = processes_.begin(); i != processes_.end(); i++) {
		if (i->second->getName().compare(name) == 0) {
			return i->first;
		}
	}
	return -1;
}

Process* OperatingSystem::getProcessByName(std::string name) {
	for (auto i = processes_.begin(); i != processes_.end(); i++) {
		if (i->second->getName().compare(name) == 0) {
			return i->second;
		}
	}
	return nullptr;
}

void OperatingSystem::addLibrary(std::string name) {
	libraries_.insert(std::pair<std::string, Library*>(name, new Library(name)));
}

void OperatingSystem::showLibraries() {
	for (auto pos = libraries_.begin(); pos != libraries_.end(); pos++) {
		std::cout << pos->first << '\n';
	}
}

void OperatingSystem::deleteLibrary(std::string name) {
	if (libraries_.count(name)) {

		auto lib = libraries_[name];
		auto i = processes_.begin();
		while (i != processes_.end()){
			bool shouldDelete = i->second->didLoadedLibrary(lib);
			if (shouldDelete) {
				delete i->second;
				processes_.erase(i++);
			}
			else {
				i++;
			}
		}

		delete libraries_[name];
		libraries_.erase(name);
	}
}

int OperatingSystem::getNewId() {
	return lastProcessId_++;
}

void OperatingSystem::addProcess(std::string process_description) {
	int id = getNewId();
	processes_.insert(std::pair<int, Process*>(id, new Process(id, process_description, this)));
}

void OperatingSystem::showProcesses() {
	for (auto pos = processes_.begin(); pos != processes_.end(); pos++) {
		std::cout << pos->first << '\t' << pos->second->getName() << '\t' << pos->second->getThreadCount() << '\n';
	}
}

void OperatingSystem::killProcess(int index) {
	delete processes_[index];
	processes_.erase(index);
}

void OperatingSystem::killProcess(std::string name){
	int index = getProcessIdByName(name);
	if (index != -1)
		killProcess(index);
}