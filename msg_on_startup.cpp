#include <stdio.h>
#include <Windows.h>
#include "msg_on_startup.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

const LPCSTR SUB_KRY_PATH = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
const LPCSTR VALUE_NAME = "ManagementProgram";
const char* VALUE_DATA = "\"C:\\Users\\mikad\\source\\repos\\msgonstartup\\x64\\Debug\\msgonstartup.exe\"";

void MakePopUp()
{
    int msgboxID = MessageBox(NULL, (LPCWSTR)L"Hey! Its my popup!", (LPCWSTR)L"Message by Mika", NULL);
    switch (msgboxID)
    {
    case IDOK:
        std::cout << "OK was Pressed" << std::endl;
        break;
    }
}

void AddRegValue()
{
    int return_code;
    PHKEY current_user_key_pointer = NULL;
    current_user_key_pointer = new HKEY;
    
    // Get key: HKEY_CURRENT_USER 
    return_code = RegOpenCurrentUser(KEY_ALL_ACCESS, current_user_key_pointer);
    if (return_code != ERROR_SUCCESS) {
        std::cout << "RegOpenCurrentUser Failed! code: " << return_code << std::endl;
        return;
    }

    // If value does not exist then create it 
    return_code = RegGetValueA(*current_user_key_pointer, SUB_KRY_PATH, VALUE_NAME, RRF_RT_ANY, NULL, NULL, NULL);
    if (return_code == ERROR_FILE_NOT_FOUND) {
        std::cout << "RegGetValueA value not defined" << std::endl;

        // Set new value
        return_code = RegSetKeyValueA(*current_user_key_pointer, SUB_KRY_PATH, VALUE_NAME, REG_SZ, VALUE_DATA, strlen(VALUE_DATA) + 1);
        if (return_code != ERROR_SUCCESS) {
            std::cout << "RegSetKeyValueA Failed! code: " << return_code << std::endl;
            return;
        }
        else {
            std::cout << "RegSetKeyValueA - SUCCESS" << std::endl;
        }
    }
    else if (return_code != ERROR_SUCCESS) {
        std::cout << "RegGetValueA function failed" << std::endl;
        return;
    }
    // Close the key
    std::cout << "RegGetValueA - SUCCESS" << std::endl;
    RegCloseKey(*current_user_key_pointer);
    delete current_user_key_pointer;
}

void SleepForHour()
{
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(10s);
    std::cout << "Waited 3600s" << std::endl;
}

int main()
{
    // Check if process is already ruuning
    HANDLE existingMutex;
    existingMutex = CreateMutexA(NULL, FALSE, "msgonstartup.exe");
    if (GetLastError() == ERROR_ALREADY_EXISTS)
    {
        std::cout << "Mutex was not created : mutex already exists" << std::endl;
        return 1;
    }
    if (existingMutex == NULL)
    {
        std::cout << "Mutex was not created : unknown reason" << std::endl;
        return 1;
    }
    
    // Run desired logic
    std::cout << "New Mutex created" << std::endl;
    MakePopUp();
    AddRegValue();
    SleepForHour();
    
    std::cout << "Done" << std::endl;
    return 0;
}
