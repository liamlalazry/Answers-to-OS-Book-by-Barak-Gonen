// Ans4.5SummaryExercise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <synchapi.h>
#define NUM_OF_THREADS 4

DWORD WINAPI Printloop(LPVOID param);
int main()
{
	
	HANDLE hThread[NUM_OF_THREADS];
	for (INT i = 0;i < NUM_OF_THREADS;i++) {
		hThread[i] = CreateThread(NULL, //default security attributes
			0, //default stack size
			Printloop, //thread function
			NULL, //thread param
			0, //default creation flags
			NULL //return thread identifier

		);
		WaitForSingleObject(hThread, INFINITE);
		printf("abcccccccccccccccccccccccccccccccc %d\n", i);
	}
	WaitForMultipleObjects(NUM_OF_THREADS, hThread, TRUE, INFINITE);
	getchar();
}


DWORD WINAPI Printloop(LPVOID param) {
	for (INT i = 0;i < 1000;i++) {
		DWORD Id = GetCurrentThreadId();
		printf("The Loop counter: %d The Thread ID: %lu\n", i,Id);
		
	}
	return 0;
}
