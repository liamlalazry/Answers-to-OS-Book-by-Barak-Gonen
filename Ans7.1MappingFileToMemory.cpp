// Ans7.1MappingFileToMemory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <windows.h>
#include <iostream>
#include <fileapi.h>
#include <filesystem>
#include <fstream>
#include <cstdlib> 
#define FILE_PATH "C:\\Users\\cyber\\Downloads\\gibrish.bin"


int main()
{
    DWORD BytesRead = 0;
    LARGE_INTEGER FileSize;
    HANDLE hFile = CreateFileA(
        FILE_PATH, GENERIC_READ,
        FILE_SHARE_READ,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL

    );
    int counter = 0;
    if (hFile == INVALID_HANDLE_VALUE)
    {
        printf("CreateFileA failed. Error: %lu\n", GetLastError());
        return 1;
    }
    GetFileSizeEx(hFile, &FileSize);
    CHAR* buffer = (CHAR*)malloc((size_t)FileSize.QuadPart +1);

    DWORD BytesToRead = (DWORD)FileSize.QuadPart;
    ReadFile(hFile,buffer,BytesToRead,&BytesRead,NULL);
    buffer[BytesRead] = '\0';
   // printf("%s\n", buffer);
    for (int i = 0;i < BytesToRead;i++) {
        
        if (buffer[i] == 'A')
        {
            counter++;
           
        }
    }
    printf("%d", counter);
    CloseHandle(hFile);
    free(buffer);
    return 0;
}
