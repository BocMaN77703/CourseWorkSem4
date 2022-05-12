#pragma once
#include "FileInfo.h"

class FileLfn : public FileInfo
{
private:
	wstring getPartName(const UCHAR * record, int offsetStart, int offsetEnd);
public:
	FileLfn() {};
	~FileLfn() {};
	virtual void createFileName(const UCHAR* record);
	virtual void createSize(const UCHAR* record);
	virtual UINT32 createFirstCluster(const UCHAR* record);
};

