// HelloWorldMutex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <Windows.h>
#include <stdio.h>
#include <synchapi.h>
#include <cstdint>


DWORD WINAPI HelloWorldMutex(LPVOID param,CHAR* param2) 
{

	DWORD IsFree = WaitForSingleObject(param, 0);
	//printf("%lu", IsFree);
	if (IsFree == WAIT_TIMEOUT){
		//Dont care for now about the other types of return values, just check if the mutex is free or not
		printf("Mutex is already locked by another process\n");
		WaitForSingleObject(param, INFINITE);
		printf("%s\n", param2);
		ReleaseMutex(param);
	}
	else {
		printf("Mutex is free\n");
		printf("%s\n",param2);
		ReleaseMutex(param);
	}
	
	return 0;

		

	



}
int main(int argc, char* argv[])
{
	if (argc < 2) {
		printf("Usage: program <argument>\n");
		return 1;
	}
	HANDLE PrintingMutex = CreateMutexA(NULL, FALSE, "MyFirstMutex");
	if (PrintingMutex == NULL) {
		printf("CreateMutexA failed: %lu\n", GetLastError());
	}
	HelloWorldMutex(PrintingMutex, argv[1]);
	fflush(stdout);
	printf("Press Enter to exit...\n");
	fflush(stdout);
	getchar();          // <-- keeps the window open
	CloseHandle(PrintingMutex);
	return 0;
}