#include "MyMutex.h"

#include <stdio.h>
#include <Windows.h>
#include <iostream>

#include "exceptions.h"

MyMutex::MyMutex(const char* name)
{
    m_hmutex = CreateMutexA(NULL, FALSE, name);
    if (!IsValid()) {
        throw MutexException("Mutex is invalid!");
    }
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
    if (IsValid()) {
        CloseHandle(m_hmutex);
    }
};
