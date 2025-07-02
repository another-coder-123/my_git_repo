#pragma once
#include <iostream>

class RegistryAccessException : public std::exception
{
private:
    std::string error_msg;

public:
    RegistryAccessException(const std::string& error) : error_msg(error) {}
    const char* what() const noexcept;
};

class MutexException : public std::exception
{
private:
    std::string error_msg;

public:
    MutexException(const std::string& error) : error_msg(error) {}
    const char* what() const noexcept;
};
