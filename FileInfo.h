#pragma once
#include "pch.h"
#include "BootSector.h"

using namespace std;
class FileInfo
{
protected:
	UINT32 firstCluster;
	UINT32 size;
	wstring fileName;
public:
	FileInfo() {};
	~FileInfo() {};
	UINT32 getFirstCluster() const;
	void setFirstCluster(UINT32 startCluster);
	UINT32 getSize() const;
	void setSize(UINT32 size);
	wstring getFileName() const;
	void setFileName(wstring& fileName);
	void removeSpaces();
	virtual void createFileName(const UCHAR* record);
	virtual void createSize(const UCHAR* record);
	virtual UINT32 createFirstCluster(const UCHAR* record);
};