#include "pch.h"
#include "Menu.h"
#include <iostream>
#include <iomanip>
#include "Validation.h"

int Menu::chooseDisk(SystemInfo& info)
{
	list<Disk> volumes = info.getDisks();
	int choice;
	bool flag=false;
	do {
		cout << "Choose volume (1-" << volumes.size() << "). 0 for quit" << endl;
		validation(choice, 0, volumes.size());
		--choice;
		if (choice == -1) break;
		list<Disk>::iterator it = volumes.begin();
		advance(it, choice);
		if (it->getFileSystemName() != L"FAT32") {
			cout << "File system of this volume is not FAT32. Input again" << endl;
			continue;
		}
		flag = true;
	} while (!flag);
	return choice;
}

void Menu::printDisks(SystemInfo& info) const
{
	list<Disk> volumes = info.getDisks();
	list<Disk>::iterator it = volumes.begin();
	int i=1;
	int lenShifts = to_string(volumes.size()).length() + 3;
	for (it = volumes.begin(); it != volumes.end(); ++it, ++i) {
		wcout << i << ". " <<"Drive letter : " << it->getLetter() << endl
		<<"   File system: " << it->getFileSystemName() << endl
		<<"   Total capacity of volume: " << it->getTotalCapacity().QuadPart / pow(2, 30) << " Gb" << "\n" << endl;
	}
}