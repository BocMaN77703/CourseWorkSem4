#pragma once
#include "Reader.h"
#include "BootSector.h"
#include "FileInfo.h"
#include <list>


class FileSystem
{
	Reader* reader;
	BootSector bootSector;
	UINT32* fatTable;
	UINT32 fatTableSize;
	UCHAR* rootDirectory;
	UINT32 rootDirectorySize;
public:
	FileSystem(Reader* reader) {
		this->reader = reader;
	};
	~FileSystem() {
		delete[] fatTable;
		delete[] rootDirectory;
	};
	void parseBootSector(UCHAR* info);
	void parseFatTable(UCHAR* buffer, int size);
	void createFatTable();
	void createBootSector();
	void createRootDirectory();
	int getStartSectorOfActiveFat();
	list<int> getFileClusters(const FileInfo& file);
	list<int> getRootDirectoryClusters();
	void recovery(wstring folderName);
	void recoverDeletedFile(UINT32 offset, FileInfo& fileRecord, wstring folderName);
	bool isCorrectLFN(UINT32 offset);
	bool isFreeCluster(UINT32 offset, int clusterNumber);
	void getFileInfo(UINT32 offset, FileInfo& file);
};