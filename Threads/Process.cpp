#include "Process.h"

#include <algorithm>
#include <iostream>

#include "Library.h"

Process::~Process()
{
	std::cout << "Deleting " + name_ + "...\t";

	system_ = 0;
	for (unsigned int i = 0; i < threads_.size(); i++)
		delete threads_[i];

	threads_.clear();
	libraries_.clear();

	std::cout << '\n';
}

void Process::createNewThread() {
	threads_.push_back(new Thread(false));
}

bool Process::killThread(int index) {
	if (index < 0 || index > threads_.size())
		throw std::invalid_argument("Index must be correct!");

	if (index != 0) {
		delete threads_[index];
		threads_.erase(threads_.begin() + index);
		return true;
	}
	
	return false;
}

void Process::loadLibrary(Library* library) {
	auto pos = std::find(libraries_.begin(), libraries_.end(), library);
	if (pos == libraries_.end()) {			// not found
		libraries_.push_back(library);
	}
}

bool Process::didLoadedLibrary(Library* library) {
	auto pos = std::find(libraries_.begin(), libraries_.end(), library);
	return pos != libraries_.end();
}