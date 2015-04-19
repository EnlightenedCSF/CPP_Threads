#pragma once

#include <hash_map>
#include <vector>
#include <string>

#include "Library.h"
#include "Process.h"

class OperatingSystem
{
public:
	OperatingSystem();
	virtual ~OperatingSystem();

	void addLibrary(std::string name);
	void showLibraries();
	void deleteLibrary(std::string name);

	void addProcess(std::string process_description);
	void showProcesses();
	void killProcess(int index);
	void killProcess(std::string name);

private:
	std::hash_map<std::string, Library*> libraries_;
	std::hash_map<int, Process*> processes_;

	int lastProcessId_;
	int getNewId();

	Library* getLibraryByName(std::string name);
	Process* getProcessByName(std::string name);
	int getProcessIdByName(std::string name);
};

