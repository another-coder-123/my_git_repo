#pragma once
#include <string>
#include <Windows.h>

class MyMutex {
public:
    MyMutex(const char* name);
    MyMutex(const MyMutex& other);
    MyMutex& operator=(const MyMutex& other);
    bool isValid();
    ~MyMutex();
private:
    HANDLE m_hmutex;
    const char* m_name;
};

