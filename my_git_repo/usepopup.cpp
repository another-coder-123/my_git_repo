#include <Windows.h>
#include <stdio.h>
#define LIBRARY "C:\\Users\\mikad\\source\\repos\\popupdll\\x64\\Debug\\popupdll.dll"

typedef void (*PFUNC)(void);

int main()
{
    HMODULE hModule = LoadLibraryA(LIBRARY);
    if (NULL == hModule)
    {
        printf("Failed to load\n");
        return 0;
    }
    PFUNC pFunc = (PFUNC)GetProcAddress(hModule, "MakePopUp");
    if (NULL != pFunc)
    {
        printf("loaded!\n");
    }
    else
    {
        printf("Failed to load function\n");
    }
    return 0;
}