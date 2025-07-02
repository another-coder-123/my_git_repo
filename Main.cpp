#include <Windows.h>
#include <iostream>

#include "Utilities.h"
#include "MyMutex.h"
#include "MyRegKey.h"

const LPCSTR SUB_KEY_PATH = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
const LPCSTR VALUE_NAME = "ManagementProgram";
const LPCSTR VALUE_DATA = "\"C:\\Users\\mikad\\source\\repos\\msgonstartup\\x64\\Debug\\msgonstartup.exe\"";
const DWORD MILISECS_TO_SLEEP = 10000;
const char* MUTEX_NAME = "msgonstartup.exe";

int main()
{
    MyMutex existingMutex(MUTEX_NAME);
    MyRegKey my_reg_key;

    my_reg_key.SetValue(SUB_KEY_PATH, VALUE_NAME, VALUE_DATA);
    MakePopUp();
    Sleep(MILISECS_TO_SLEEP);

    std::cout << "Done" << std::endl;
    return 0;
}