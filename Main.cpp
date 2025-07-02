#include <Windows.h>
#include <iostream>

#include "Utilities.h"
#include "MyMutex.h"
#include "MyRegKey.h"
#include "CustomExceptions.h"

const char* SUB_KEY_PATH = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
const char* VALUE_NAME = "ManagementProgram";
const char* VALUE_DATA = "\"C:\\Users\\mikad\\source\\repos\\msgonstartup\\x64\\Debug\\msgonstartup.exe\"";
const unsigned long MILISECS_TO_SLEEP = 10000;
LPCSTR MUTEX_NAME = "msgonstartup.exe";

int main()
{
    MyMutex existingMutex(MUTEX_NAME);
    
    MyRegKey myRegKey;

    myRegKey.setValue(SUB_KEY_PATH, VALUE_NAME, VALUE_DATA);
    makePopUp();
    Sleep(MILISECS_TO_SLEEP);

    std::cout << "Done" << std::endl;
    return 0;
}