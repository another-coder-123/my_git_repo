#include <stdio.h>
#include <Windows.h>
#include "msg_on_startup.h"
#include <iostream>

const LPCSTR SUB_KEY_PATH = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";
const LPCSTR VALUE_NAME = "ManagementProgram";
const LPCSTR VALUE_DATA = "\"C:\\Users\\mikad\\source\\repos\\msgonstartup\\x64\\Debug\\msgonstartup.exe\"";
const DWORD MILISECS_TO_SLEEP = 10000;

MyRegKey::MyRegKey()
{
    m_phkey = new HKEY;
};

MyRegKey::~MyRegKey()
{
    RegCloseKey(*m_phkey);
    delete m_phkey;
};
MyMutex::MyMutex()
{
    m_hmutex = CreateMutexA(NULL, FALSE, "msgonstartup.exe");
};

MyMutex::~MyMutex()
{
    CloseHandle(m_hmutex);
};

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

void AddRegValue()
{
    int return_code;
    MyRegKey current_user_phkey;
    
    // Get key: HKEY_CURRENT_USER 
    return_code = RegOpenCurrentUser(KEY_ALL_ACCESS, current_user_phkey.m_phkey);
    if (return_code != ERROR_SUCCESS) {
        std::cout << "RegOpenCurrentUser Failed! code: " << return_code << std::endl;
        return;
    }

    // If value does not exist then create it 
    return_code = RegGetValueA(*current_user_phkey.m_phkey, SUB_KEY_PATH, VALUE_NAME, RRF_RT_ANY, NULL, NULL, NULL);
    if (return_code == ERROR_FILE_NOT_FOUND) {
        std::cout << "RegGetValueA value not defined" << std::endl;

        // Set new value
        return_code = RegSetKeyValueA(*current_user_phkey.m_phkey, SUB_KEY_PATH, VALUE_NAME, REG_SZ, VALUE_DATA, strlen(VALUE_DATA) + 1);
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
    
    std::cout << "RegGetValueA - SUCCESS" << std::endl;
}

int main()
{
    // Check if process is already ruuning
    MyMutex existingMutex;

    if (GetLastError() == ERROR_ALREADY_EXISTS)
    {
        std::cout << "Mutex was not created : mutex already exists" << std::endl;
        return 1;
    }
    if (existingMutex.m_hmutex == NULL)
    {
        std::cout << "Mutex was not created : unknown reason" << std::endl;
        return 1;
    }
    
    // Run desired logic
    std::cout << "New Mutex created" << std::endl;
    MakePopUp();
    AddRegValue();
    Sleep(MILISECS_TO_SLEEP);
    
    std::cout << "Done" << std::endl;
    return 0;
}
