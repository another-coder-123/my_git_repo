#include <stdio.h>
#include <Windows.h>
#define DLL_EXPORT
#include "popupdll.h"

extern "C"
{
    DECLDIR void MakePopUp()
    {
        int msgboxID = MessageBox(NULL, (LPCWSTR)L"Hey! Its my popup!", (LPCWSTR)L"Message by Mika", NULL);
        switch (msgboxID)
        {
        case IDOK:
            printf("OK was Pressed\n");
            break;
        }
    }
  
}

BOOL APIENTRY DllMain(HANDLE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    lpReserved = lpReserved;
    hModule = hModule;

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        MakePopUp();
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}