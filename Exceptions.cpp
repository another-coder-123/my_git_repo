#include "exceptions.h"


const char* RegistryAccessException::what() const noexcept
{
    return error_msg.c_str();
};

const char* MutexException::what() const noexcept
{
    return error_msg.c_str();
};
