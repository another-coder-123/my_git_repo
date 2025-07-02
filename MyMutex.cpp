#include "MyMutex.h"

#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <exception>

#include "CustomExceptions.h"

MyMutex::MyMutex(const char* name)
{
    m_name = name;
    m_hmutex = CreateMutexA(NULL, FALSE, name);
    if (!isValid()) {
        throw MutexException("Mutex is invalid!");
    }
};

MyMutex::MyMutex(const MyMutex& other)
{
    m_name = other.m_name;
    m_hmutex = CreateMutexA(NULL, FALSE, (LPCSTR)m_name);
    if (!isValid()) {
        throw MutexException("Mutex is invalid!");
    }
};

MyMutex& MyMutex::operator=(const MyMutex& other)
{
    m_name = other.m_name;
    m_hmutex = CreateMutexA(NULL, FALSE, (LPCSTR)m_name);
    if (!isValid()) {
        throw MutexException("Mutex is invalid!");
    }
    return *this;
};

bool MyMutex::isValid()
{
    if (GetLastError() == ERROR_ALREADY_EXISTS) {
        std::cout << "Mutex Invalid - already exists" << std::endl;
        return false;
    }
    if (this->m_hmutex == NULL) {
        std::cout << "Mutex Invalid - unknown reason" << std::endl;
        return false;
    }
    std::cout << "Mutex Is Valid" << std::endl;
    return true;
};

MyMutex::~MyMutex()
{
    if (isValid()) {
        CloseHandle(m_hmutex);
    }
};
