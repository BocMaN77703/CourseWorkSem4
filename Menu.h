#pragma once
#include "Disk.h"
#include "SystemInfo.h"

class Menu
{
public:
	Menu() {};
	~Menu() {};
	int chooseDisk(SystemInfo& info);
	void printDisks(SystemInfo& info) const;
};

