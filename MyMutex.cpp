#include <stdio.h>
#include <Windows.h>
#include "MyMutex.h"
#include <iostream>


const char* MutexException::what() const noexcept
{
    return error_msg.c_str();
}


MyMutex::MyMutex(LPCSTR name)
{
    m_hmutex = CreateMutexA(NULL, FALSE, name);
};

bool MyMutex::IsValid()
{
    if (this->m_hmutex == NULL)
    {
        std::cout << "Mutex Invalid - unknown reason" << std::endl;
        return false;
    }
    std::cout << "Mutex Is Valid" << std::endl;
    return true;
};

MyMutex::~MyMutex()
{
    if (IsValid() == true) {
        CloseHandle(m_hmutex);
    }
};
