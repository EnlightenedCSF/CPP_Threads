#pragma once

#include <string>

class Library
{
public:
	Library(std::string name) : name_(name) { };
	virtual ~Library();

private:
	std::string name_;
};

