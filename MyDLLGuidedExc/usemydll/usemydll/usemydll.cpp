// usemydll.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

extern "C" __declspec(dllimport) void Share();
// Other option would be-
// #include "mydll.h"
int main()
{
	Share();
	return 0;
}