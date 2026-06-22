#include <Windows.h>
#include <stdio.h>
//InitializeCriticalSection(&test); // creating the lock for protecting other threads from accessing the critical section at the same time
//EnterCriticalSection(&test); // Trying to enter the critical section and if its locked it will wait even for infinite for it to open
//TryEnterCriticalSection(&test); // checks if the lock is open if so its locking it and writing to it if not it will return false and not wait for it to open
//LeaveCriticalSection(&test); // leaving the critical section and unlocking it for other threads to access it
//DeleteCriticalSection(&test); // deleting the critical section and freeing the memory allocated for it


CRITICAL_SECTION chopstick1;
CRITICAL_SECTION chopstick2;
CRITICAL_SECTION chopstick3;
CRITICAL_SECTION chopstick4;
CRITICAL_SECTION chopstick5;
DWORD WINAPI FirstEatingPhilosoferFunction(LPVOID param);
DWORD WINAPI WaitingPhilosoferFunction(LPVOID param);
int main()
{
	InitializeCriticalSection(&chopstick1);
	InitializeCriticalSection(&chopstick2);
	InitializeCriticalSection(&chopstick3);
	InitializeCriticalSection(&chopstick4);
	InitializeCriticalSection(&chopstick5);
	

	HANDLE EatingPhilosofer[5];
	for (INT i = 0; i < 2; i++) {
		EatingPhilosofer[i] = CreateThread(NULL, //default security attributes
			0, //default stack size
			FirstEatingPhilosoferFunction, //thread function
			pointerparam, //thread param
			0, //default creation flags
			NULL //return thread identifier

		);
	}
	DeleteCriticalSection(&chopstick1);
	DeleteCriticalSection(&chopstick2);
	DeleteCriticalSection(&chopstick3);
	DeleteCriticalSection(&chopstick4);
	DeleteCriticalSection(&chopstick5);
}
DWORD WINAPI FirstEatingPhilosoferFunction(LPVOID stilldontknow) {
	return 0;
}
