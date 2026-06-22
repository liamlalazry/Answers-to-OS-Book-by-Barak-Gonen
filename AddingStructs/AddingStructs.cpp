#include <stdio.h>
#include <windows.h>
struct MyStruct {
    int num1;
    int num2;
};

DWORD WINAPI bla(LPVOID lparam) {
    int result = ((struct MyStruct*)lparam)->num2 + ((struct MyStruct*)lparam)->num1;
	printf("Result: %d\n", result);
    return 1;
}

int main()
{
    struct MyStruct MyBStruct = { 1 ,2 };   // <-- Declare variable here
    LPVOID pMyBStruct = &MyBStruct;
    bla(pMyBStruct);
}
