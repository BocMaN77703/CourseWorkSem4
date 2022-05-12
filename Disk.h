#pragma once
#include "pch.h"
#include <list>
#include <vector>
using namespace std;

class Disk
{
	LPWSTR GUIDPath;
	wstring letter;
	wstring fileSystemName;
	ULARGE_INTEGER totalCapacity;
public:
	Disk() { 
		GUIDPath = new WCHAR[100];
		totalCapacity.QuadPart = 0; 
	}
	Disk(LPCWSTR path) {
		GUIDPath = new WCHAR[100];
		wcscpy(GUIDPath, path);
		totalCapacity.QuadPart = 0;
	};
	Disk(const Disk& v) {
		GUIDPath = new WCHAR[100];
		wcscpy(GUIDPath, v.GUIDPath);
		totalCapacity = v.totalCapacity;
		letter = v.letter;
		fileSystemName = v.fileSystemName;
	}
	~Disk() { 
		delete[] GUIDPath;
	};
	wstring getLetter();
	void setLetter();
	wstring getFileSystemName();
	void setFileSystemName();
	LPCWSTR getGUIDPath() const;
	ULARGE_INTEGER getTotalCapacity();
	void setTotalCapacity();
};