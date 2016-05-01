
#include "stdafx.h"
#include <Windows.h>

int calculateDevHash(char *str)
{
	for (char *p = str; *p; p++)
		*p = tolower(*p);

	int sum = 0;

	for (char *p = str; *p; p++)
	{
		char c = *p;
		sum = (16 * sum) + c;
		int upperNibble = sum & 0xF0000000;
		if (upperNibble > 0)
			sum ^= upperNibble ^ (upperNibble >> 24);
	}
	int tmp = 1812433253 * (sum >> 16) - 1989869568 * sum;
	return 1142332463 * tmp;

}
//HKEY_LOCAL_MACHINE\SOFTWARE\Blue Byte\The Settlers - Heritage of Kings\Development\DevelopmentMachine DWORD
int _tmain(int argc, _TCHAR* argv[])
{
	char namBuf[256];
	DWORD bufLen = 256;
	GetComputerNameA(namBuf, &bufLen);
	printf("PC Name: %s\n", namBuf);
	printf("Hash (Hex): %x\n", calculateDevHash(namBuf));
	getchar();
	return 0;
}

