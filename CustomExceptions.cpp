#include "CustomExceptions.h"

const char* RegistryAccessException::what() const noexcept
{
    return errorMsg.c_str();
};

const char* MutexException::what() const noexcept
{
    return errorMsg.c_str();
};
