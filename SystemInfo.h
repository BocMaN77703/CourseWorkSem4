#pragma once
#include "Disk.h"

class SystemInfo
{
private:
	list<Disk> disks;
public:
	SystemInfo() {};
	~SystemInfo() {};
	void searchDisks();
	void removeSystemDisks();
	bool isFAT(wstring fsName);
	Disk getDisk(int number);
	list<Disk> getDisks();
};

