// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SystemUI.h"

int _tmain(int argc, _TCHAR* argv[])
{
	SystemUI* sysptr = new SystemUI();
	sysptr->showLoginMeunOperation();
	delete sysptr;
	system("Pause");
	return 0;
}