#include <stdio.h>
#include <Windows.h>
#include "msg_on_startup.h"
#include "MyMutex.h"
#include "MyRegKey.h"
#include <iostream>

const LPCSTR SUB_KEY_PATH = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
const LPCSTR VALUE_NAME = "ManagementProgram";
const LPCSTR VALUE_DATA = "\"C:\\Users\\mikad\\source\\repos\\msgonstartup\\x64\\Debug\\msgonstartup.exe\"";
const DWORD MILISECS_TO_SLEEP = 10000;
const LPCSTR MUTEX_NAME = "msgonstartup.exe";

void MakePopUp()
{
    int msgboxID = MessageBox(NULL, (LPCWSTR)L"Hey! Its my popup!", (LPCWSTR)L"Message by Mika", NULL);
    switch (msgboxID)
    {
    case IDOK:
        std::cout << "OK was Pressed" << std::endl;
        break;
    default:
        break;
    }
}

int main()
{
    MyMutex existingMutex(MUTEX_NAME);
    MyRegKey my_reg_key;

    my_reg_key.SetValue(SUB_KEY_PATH, VALUE_NAME, VALUE_DATA);
    
    MakePopUp();
    
    std::cout << "Sleeping..." << std::endl;
    Sleep(MILISECS_TO_SLEEP);
    
    std::cout << "Done" << std::endl;
    return 0;
}
