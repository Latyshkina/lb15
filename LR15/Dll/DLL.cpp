// DLL.cpp: определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include "DLL.h"


EXPORT  int Function()
{
	char buffer[4];
	int n, k = 0;;
	DWORD dr = GetLogicalDrives();
	for (int i = 1; i < 6; i++)
	{
		n = ((dr >> i) & 0x00000001);
		if (n == 1)
		{
			buffer[0] = char(65 + i);
			buffer[1] = ':';
			buffer[2] = '\\';
			buffer[3] = 0;
			k++;
			MessageBox(NULL, (LPTSTR)buffer, "Function from  DLL", MB_OK);
		}
		else
		{
			MessageBox(NULL, NULL, "Disk not found", MB_OK);
			k++;
		}
	}
	return 1;
}

MyClass::MyClass()
{
}

EXPORT int MyClass::FunctionFromClass()
{
	char buffer[4];
	int n, k = 0;;
	DWORD dr = GetLogicalDrives();
	for (int i = 1; i < 6; i++)
	{
		n = ((dr >> i) & 0x00000001);
		if (n == 1)
		{
			buffer[0] = char(65 + i);
			buffer[1] = ':';
			buffer[2] = '\\';
			buffer[3] = 0;
			k++;
			MessageBox(NULL, (LPTSTR)buffer, "Function from class DLL", MB_OK);
		}
		else
		{
			MessageBox(NULL, NULL, "Disk not found(class)", MB_OK);
			k++;
		}
	}
	return 1;
}

MyClass::~MyClass()
{
}

EXPORT int fun()
{
	MyClass::FunctionFromClass();
	return 1;
}