#include <Windows.h>
#include <stdio.h>
#include <synchapi.h>
#include <cstdint>
#include <iostream>
#define EXE_FILENAME "C:\\Users\\Liam\\source\\repos\\HelloWorldMutex\\x64\\Debug\\HelloWorldMutex.exe"
//"C:\Users\Liam\source\repos\HelloWorldMutex\x64\Debug\HelloWorldMutex.exe"
int main() {
	STARTUPINFOA si[2];
	PROCESS_INFORMATION pi[2];
	CHAR exe_filename[] = EXE_FILENAME;
	CHAR num_str[20];
	std::cin >> num_str;
	INT size = strlen(exe_filename) + strlen(num_str) + 2;
	PCHAR param = (PCHAR)malloc(size * sizeof(CHAR));
	
	
	
	sprintf_s(param, size, "%s %s", exe_filename,num_str);

	printf("param: %s\n", param);
	for (int i = 0; i < 2; i++) {
		ZeroMemory(&si[i], sizeof(si[i]));
		si[i].cb = sizeof(si[i]);
		ZeroMemory(&pi[i], sizeof(pi[i]));
		CreateProcessA(NULL,
			//	param, // Command line
			param, // Command line
			NULL, // Process handle not inheritable
			NULL, // Thread handle not inheritable
			FALSE, // Set handle inheritance to FALSE
			CREATE_NEW_CONSOLE, // No creation flags
			NULL, // Use parent's environment block
			NULL, // Use parent's starting directory
			&si[i], // Pointer to STARTUPINFO structure
			&pi[i]);
		// Pointer to PROCESS_INFORMATION structure
	}
	for (int i = 0; i < 2; i++) {
		WaitForSingleObject(pi[i].hProcess, INFINITE);
		WaitForSingleObject(pi[i].hProcess, INFINITE); 
		CloseHandle(pi[i].hThread);
		CloseHandle(pi[i].hProcess);
	}

	return 0;
}













