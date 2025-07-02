#pragma once
#include <string>

class MutexException : public std::exception
{
private:
    std::string error_msg;

public:
    MutexException(const std::string& error) : error_msg(error) {}
    const char* what() const noexcept;
};

class MyMutex {
public:
    MyMutex(LPCSTR name);
    bool IsValid();
    ~MyMutex();
private:
    HANDLE m_hmutex;
};

