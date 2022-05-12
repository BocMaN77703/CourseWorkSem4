#include "pch.h"
#include <iostream>
#include "Disk.h"
#include "Menu.h"
#include "SystemInfo.h"
#include "Reader.h"
#include "FileSystem.h"

using namespace std;


int main() {
	const int bufferSize = 100;
	wstring fat = L"FAT32";
	SystemInfo info;
	info.searchDisks();
	info.removeSystemDisks();
	while (true) {
		Menu menu;
		menu.printDisks(info);
		if (!info.isFAT(fat)) {
			cout << "Oops! There is no FAT32 in your computer!" << endl;
			break;
		}
		int diskNumber = menu.chooseDisk(info);
		if (diskNumber == -1) break;
		Disk disk = info.getDisk(diskNumber);
		Reader reader;
		reader.OpenDevice(disk.getGUIDPath());
		cout << "Parsing file system..." << endl;
		FileSystem fat32 = FileSystem(&reader);
		fat32.createBootSector();
		fat32.createFatTable();
		fat32.createRootDirectory();
		cout << "Recovering files..." << endl;
		wstring folderName = L"";
		folderName.push_back(disk.getLetter()[0]);
		folderName += L":\\RecoveredFiles\\";
		CreateDirectoryW(folderName.c_str(), NULL);
		fat32.recovery(folderName);
		cout << "Files were recovered successfully!!!" << endl;
		system("pause");
	}
	system("pause");
	return 0;
}