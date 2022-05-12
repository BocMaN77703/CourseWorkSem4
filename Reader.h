#pragma once
#include "pch.h"
using namespace std;
class Reader
{
	HANDLE diskHandle;
public:
	Reader() {
		diskHandle = INVALID_HANDLE_VALUE;
	}
	Reader(HANDLE volumeHandle) {
		this->diskHandle = volumeHandle;
	}
	~Reader() {
		if (diskHandle != INVALID_HANDLE_VALUE) 
			CloseHandle(diskHandle);
	}
	HANDLE getHandle();
	bool OpenDevice(wstring volumeName);
	int ReadSector(UINT64 sector, int sectorSize,int bytesToRead, UCHAR* buffer);
};