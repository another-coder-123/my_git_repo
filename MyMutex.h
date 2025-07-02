#pragma once
#include <string>


class MyMutex {
public:
    MyMutex(const char* name);
    MyMutex(const MyMutex& other);
    MyMutex& operator=(const MyMutex& other);
    bool IsValid();
    ~MyMutex();
private:
    HANDLE m_hmutex;
};

