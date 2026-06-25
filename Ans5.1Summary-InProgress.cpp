#include <Windows.h>
#include <stdio.h>
#include <synchapi.h>
#include <cstdint>
//InitializeCriticalSection(&test); // creating the lock for protecting other threads from accessing the critical section at the same time
//EnterCriticalSection(&test); // Trying to enter the critical section and if its locked it will wait even for infinite for it to open
//TryEnterCriticalSection(&test); // checks if the lock is open if so its locking it and writing to it if not it will return false and not wait for it to open
//LeaveCriticalSection(&test); // leaving the critical section and unlocking it for other threads to access it
//DeleteCriticalSection(&test); // deleting the critical section and freeing the memory allocated for it


CRITICAL_SECTION chopstick[5];
int IdentifierOfPhilosopher;
//DWORD WINAPI FirstEatingPhilosoferFunction(LPVOID param);
//DWORD WINAPI WaitingPhilosoferFunction(LPVOID param);
//DWORD WINAPI LastEatingPhilosoferFunction(LPVOID param);
DWORD WINAPI FirstEatingPhilosoferFunction(LPVOID philosoferIdentifier) {
	int philosoferIdentifier1 = (int)(uintptr_t)philosoferIdentifier;
	printf("%d",philosoferIdentifier1);
	if (philosoferIdentifier1 == 0) {
		EnterCriticalSection(&chopstick[0]);
		EnterCriticalSection(&chopstick[1]);
		printf("Philosopher 1 is eating\n");
		Sleep(4000);
		printf("Philosopher 1 is finished\n");
		LeaveCriticalSection(&chopstick[0]);
		LeaveCriticalSection(&chopstick[1]);
	
	}
	else if (philosoferIdentifier1 == 1) {
		EnterCriticalSection(&chopstick[2]);
		EnterCriticalSection(&chopstick[3]);
		printf("Philosopher 2 is eating\n");
		Sleep(4000);
		printf("Philosopher 2 is finished\n");
		LeaveCriticalSection(&chopstick[2]);
		LeaveCriticalSection(&chopstick[3]);
		
	}
	return 0;
}
DWORD WINAPI WaitingPhilosoferFunction(LPVOID waitingPhilosoferId){
	int waitingPhilosoferId1 = (int)(uintptr_t)waitingPhilosoferId;
	if (waitingPhilosoferId1 == 0) {
		EnterCriticalSection(&chopstick[1]);
		EnterCriticalSection(&chopstick[2]);
		printf("Philosopher 3 is eating\n");
		Sleep(4000);
		printf("Philosopher 3 is finished\n");
		LeaveCriticalSection(&chopstick[1]);
		LeaveCriticalSection(&chopstick[2]);
	
		
	}
	else if (waitingPhilosoferId1 == 1) {
		EnterCriticalSection(&chopstick[3]);
		EnterCriticalSection(&chopstick[4]);
		printf("Philosopher 4 is eating\n");
		Sleep(4000);
		printf("Philosopher 4 is finished\n");
		LeaveCriticalSection(&chopstick[3]);
		LeaveCriticalSection(&chopstick[4]);
		
	}
	return 0;
}
DWORD WINAPI LastEatingPhilosoferFunction(LPVOID param) {
	EnterCriticalSection(&chopstick[4]);
	EnterCriticalSection(&chopstick[0]);
	printf("Philosopher 5 is eating\n");
	Sleep(4000);
	printf("Philosopher 5 is finished\n");
	LeaveCriticalSection(&chopstick[4]);
	LeaveCriticalSection(&chopstick[0]);
	return 0;
}
int main()
{
	for (int j = 0; j < 5; j++) {
		InitializeCriticalSection(&chopstick[j]);
	}
	HANDLE EatingPhilosofer[2];
	for (INT i = 0; i < 2; i++) {
		
		EatingPhilosofer[i] = CreateThread(NULL, //default security attributes
			0, //default stack size
			FirstEatingPhilosoferFunction, //thread function
			(LPVOID)(uintptr_t)i, //thread param
			0, //default creation flags
			NULL //return thread identifier

		);
	}
	WaitForMultipleObjects(2, EatingPhilosofer, TRUE, INFINITE);
	HANDLE WaitingPhilosofer[2];
	for (int d = 0; d < 2; d++) {
	//	int IdentifierOfWaitingPhilosopher = d;
	//	LPVOID param2 = (LPVOID)IdentifierOfWaitingPhilosopher;

		WaitingPhilosofer[d] = CreateThread(NULL, //default security attributes
			0, //default stack size
			WaitingPhilosoferFunction, //thread function
			(LPVOID)(uintptr_t)d, //thread param
			0, //default creation flags
			NULL //return thread identifier
		);

	}
	WaitForMultipleObjects(2, WaitingPhilosofer, TRUE, INFINITE);

	HANDLE LastEatingPhilosofer = CreateThread(NULL, //default security attributes
		0, //default stack size
		LastEatingPhilosoferFunction, //thread function
		NULL, //thread param
		0, //default creation flags
		NULL //return thread identifier
	);
	WaitForSingleObject(LastEatingPhilosofer, INFINITE);
	for (int r = 0; r < 5; r++) {
		DeleteCriticalSection(&chopstick[r]);
	}
	

}
