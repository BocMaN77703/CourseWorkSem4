#include "pch.h"
#include "Convertation.h"



UINT32 Convertation::convert(const UCHAR* bytes, int startBorder, int endBorder)
{
	UINT32 number=0;
	for (int i = endBorder; i >= startBorder; --i) {
		number = number << 8;
		number += bytes[i];
	}
	return number;
}
