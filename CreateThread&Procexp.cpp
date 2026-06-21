//#include "pch.h"
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <synchapi.h>
struct MyStruct
{
	INT a;
	INT b;
};

DWORD WINAPI bla(LPVOID lparam) {
	struct MyStruct* nums = (MyStruct*)lparam;
	INT count = nums->a + nums->b;
	for (INT i = 1; i <= count; i++) {
		printf("bla\n");
	}
	return 1;
}
int main()
{
	struct MyStruct* my_struct =
		(MyStruct*)malloc(sizeof(MyStruct));
	my_struct->a = 3;
	my_struct->b = 4;
	LPVOID pstruct = my_struct;
	HANDLE hThread = CreateThread(
		NULL, //default security attributes
		0, //default stack size
		bla, //thread function
		pstruct, //thread param
		0, //default creation flags
		NULL //return thread identifier
	);
    WaitForSingleObject(hThread, INFINITE);
	DWORD mlsec = 1000000000000000;
	Sleep(mlsec);
}
