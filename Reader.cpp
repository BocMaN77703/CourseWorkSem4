#include "pch.h"
#include "Reader.h"



HANDLE Reader::getHandle()
{
	return diskHandle;
}

bool Reader::OpenDevice(wstring diskName)
{
	if (diskHandle != INVALID_HANDLE_VALUE) return false;
	bool returnValue = true;
	int len = diskName.length();
	diskName.at(len - 1) = 0;
	diskHandle = CreateFileW(diskName.c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE , 
		NULL, OPEN_EXISTING, FILE_ATTRIBUTE_DEVICE, NULL);
	if (diskHandle == INVALID_HANDLE_VALUE) returnValue = false;
	return returnValue;
}

int Reader::ReadSector(UINT64 sector, int sectorSize,int bytesToRead, UCHAR* buffer)
{
	if (diskHandle == INVALID_HANDLE_VALUE) return 0;
	int result = 0;
	int remainBytes = bytesToRead % sectorSize;
	int tempBytesToRead = bytesToRead - remainBytes;
	LARGE_INTEGER shiftInSectors;
	shiftInSectors.QuadPart = sector * sectorSize;
	SetFilePointerEx(diskHandle, shiftInSectors, NULL, FILE_BEGIN);
	DWORD alreadyReadBytes=0;
	ReadFile(diskHandle, buffer, tempBytesToRead, &alreadyReadBytes, NULL);
	result = alreadyReadBytes;
	if (remainBytes != 0) {
		UCHAR tempBuf[1024] = {};
		ReadFile(diskHandle, tempBuf, sectorSize, &alreadyReadBytes, NULL);
		memcpy(buffer + tempBytesToRead, tempBuf, remainBytes);
		result += remainBytes;
	}
	return result;
}