#pragma once
#include <iostream>
#include <exception>

class RegistryAccessException : public std::exception
{
public:
    RegistryAccessException(const std::string& error) : errorMsg(error) {}
    const char* what() const noexcept;
private:
    std::string errorMsg;
};

class MutexException : public std::exception
{
public:
    MutexException(const std::string& error) : errorMsg(error) {}
    const char* what() const noexcept;
private:
    std::string errorMsg;
};
