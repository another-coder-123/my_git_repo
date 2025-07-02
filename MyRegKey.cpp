#include <stdio.h>
#include <Windows.h>
#include "MyRegKey.h"
#include <memory>
#include <iostream>

const char* RegistryAccessException::what() const noexcept
{
    return error_msg.c_str();
};

MyRegKey::MyRegKey()
{
    int error_code;
    m_hkey = std::make_unique<HKEY>();

    error_code = RegOpenCurrentUser(KEY_ALL_ACCESS, &*m_hkey);
    if (error_code != ERROR_SUCCESS) {
        std::cout << "error code " << error_code << std::endl;
        throw RegistryAccessException("RegOpenCurrentUser Failed! Error code: " + error_code);
    }
    std::cout << "Key was opened" << std::endl;
};

bool MyRegKey::IsValueExists(LPCSTR sub_key_path, LPCSTR value_name)
{
    int error_code;

    error_code = RegGetValueA(*m_hkey, sub_key_path, value_name, RRF_RT_ANY, NULL, NULL, NULL);
    if (error_code == ERROR_SUCCESS) {
        return true;
    }
    else if (error_code == ERROR_FILE_NOT_FOUND) {
        return false;
    }
    throw RegistryAccessException("RegGetValueA Failed! Error code: " + error_code);
};

void MyRegKey::SetValue(LPCSTR sub_key_path, LPCSTR value_name, LPCSTR value_data)
{
    int error_code;

    if (this->IsValueExists(sub_key_path, value_name) == false) {
        error_code = RegSetKeyValueA(*this->m_hkey, sub_key_path, value_name, REG_SZ, value_data, strlen(value_data) + 1);
        if (error_code == ERROR_SUCCESS) {
            std::cout << "New value was set" << std::endl;
            return;
        }
        else {
            throw RegistryAccessException("RegSetKeyValueA Failed! Error code: " + error_code);
        }
    }
    std::cout << "Value already exists" << std::endl;
};

MyRegKey::~MyRegKey()
{
    RegCloseKey(*m_hkey);
    
};