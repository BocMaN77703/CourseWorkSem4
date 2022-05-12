#include "pch.h"
#include "FileInfo.h"
#include <algorithm>
#include "Convertation.h"


void FileInfo::removeSpaces()
{
	wstring::iterator it = fileName.begin();
	advance(it, 8);
	fileName.insert(it, '.');
	fileName.erase(std::remove(fileName.begin(), fileName.end(), ' '), fileName.end());
}


void FileInfo::createFileName(const UCHAR * record)
{
	char* nameBuffer = (char*)calloc(13, sizeof(char));
	copy(record, record + 11, nameBuffer);
	nameBuffer[0] = '$';
	string fileName(nameBuffer);
	wstring wName(fileName.begin(), fileName.end());
	this->fileName = wName;
	removeSpaces();
	free(nameBuffer);
}

void FileInfo::createSize(const UCHAR * record)
{
	Convertation conversion;
	UINT32 fileSize = conversion.convert(record, 28, 31);
	this->size = fileSize;
}

UINT32 FileInfo::createFirstCluster(const UCHAR * record)
{
	Convertation conversion;
	UINT16 highBytesOfFirstCluster = conversion.convert(record, 20, 21);
	UINT16 lowBytesOfFirstCluster = conversion.convert(record, 26, 27);
	UINT32 firstCluster;
	firstCluster = highBytesOfFirstCluster << 16;
	firstCluster += lowBytesOfFirstCluster;
	this->firstCluster = firstCluster;
	return firstCluster;
}

UINT32 FileInfo::getFirstCluster() const {
	return firstCluster;
}

void FileInfo::setFirstCluster(UINT32 firstCluster) {
	this->firstCluster = firstCluster;
}

UINT32 FileInfo::getSize() const {
	return size;
}

void FileInfo::setSize(UINT32 size) {
	this->size = size;
}

wstring FileInfo::getFileName() const
{
	return fileName;
}

void FileInfo::setFileName(wstring & fileName)
{
	this->fileName = fileName;
}