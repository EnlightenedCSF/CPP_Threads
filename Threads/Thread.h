#pragma once

#include <vector>

class Thread
{
public:
	Thread(bool isMain) : isMain_(isMain) { };
 	virtual ~Thread();

private:
	bool isMain_;
};

