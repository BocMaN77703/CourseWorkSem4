#include "pch.h"
#include "SystemInfo.h"
#include "Disk.h"


void SystemInfo::searchDisks()
{
	const int bufferSize = 100;
	list<Disk> disks;
	HANDLE h;
	LPWSTR diskName = new WCHAR[bufferSize];
	h = FindFirstVolumeW(diskName, bufferSize);
	do {

		Disk disk = Disk(diskName);
		disks.push_back(disk);

	} while (FindNextVolumeW(h, diskName, bufferSize));
	delete[] diskName;
	this->disks = disks;
}

void SystemInfo::removeSystemDisks()
{
	Disk v;
	list<Disk>::iterator it;
	for (it = disks.begin(); it != disks.end(); ) {
		if (it->getLetter()[0] == '*')
			it = disks.erase(it);
		else it++;
	}
}

bool SystemInfo::isFAT(wstring fsName)
{
	list<Disk>::iterator it;
	bool flag=false;
	for (it = disks.begin(); it != disks.end(); it++) {
		if (it->getFileSystemName() == fsName) {
			flag = true;
			break;
		}
	}
	return flag;
}

Disk SystemInfo::getDisk(int number)
{
	list<Disk>::iterator it=disks.begin();
	advance(it, number);
	return *it;
}


list<Disk> SystemInfo::getDisks()
{
	return disks;
}
