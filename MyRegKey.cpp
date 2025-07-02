#include "MyRegKey.h"

#include <stdio.h>
#include <Windows.h>
#include <memory>
#include <iostream>

#include "CustomExceptions.h"

MyRegKey::MyRegKey()
{
    int errorCode;
    m_phkey = std::make_unique<HKEY>();

    errorCode = RegOpenCurrentUser(KEY_ALL_ACCESS, m_phkey.get());
    if (errorCode != ERROR_SUCCESS) {
        std::cout << "error code " << errorCode << std::endl;
        throw RegistryAccessException("RegOpenCurrentUser Failed! Error code: " + errorCode);
    }
    std::cout << "Key was opened" << std::endl;
};

MyRegKey::MyRegKey(const MyRegKey& other)
{
    int errorCode;
    *this->m_phkey = *other.m_phkey;

    errorCode = RegOpenCurrentUser(KEY_ALL_ACCESS, m_phkey.get());
    if (errorCode != ERROR_SUCCESS) {
        std::cout << "error code " << errorCode << std::endl;
        throw RegistryAccessException("RegOpenCurrentUser Failed! Error code: " + errorCode);
    }
    std::cout << "Key was opened" << std::endl;
};

MyRegKey& MyRegKey::operator=(const MyRegKey& other)
{
    int errorCode;
    *this->m_phkey = *other.m_phkey;

    errorCode = RegOpenCurrentUser(KEY_ALL_ACCESS, m_phkey.get());
    if (errorCode != ERROR_SUCCESS) {
        std::cout << "error code " << errorCode << std::endl;
        throw RegistryAccessException("RegOpenCurrentUser Failed! Error code: " + errorCode);
    }
    std::cout << "Key was opened" << std::endl;
    return *this;
};

bool MyRegKey::doesValueExist(const char* sub_key_path, const char* value_name)
{
    int errorCode;

    errorCode = RegGetValueA(*m_phkey, (LPCSTR)sub_key_path, (LPCSTR)value_name, RRF_RT_ANY, NULL, NULL, NULL);
    if (errorCode == ERROR_SUCCESS) {
        return true;
    }
    else if (errorCode == ERROR_FILE_NOT_FOUND) {
        return false;
    }
    throw RegistryAccessException("RegGetValueA Failed! Error code: " + errorCode);
};



void MyRegKey::setValue(const char* sub_key_path, const char* value_name, const char* value_data)
{
    int errorCode;

    if (this->doesValueExist(sub_key_path, value_name) == false) {
        errorCode = RegSetKeyValueA(*this->m_phkey, (LPCSTR)sub_key_path, (LPCSTR)value_name, REG_SZ, value_data, strlen(value_data) + 1);
        if (errorCode == ERROR_SUCCESS) {
            std::cout << "New value was set" << std::endl;
            return;
        }
        else {
            throw RegistryAccessException("RegSetKeyValueA Failed! Error code: " + errorCode);
        }
    }
    std::cout << "Value already exists" << std::endl;
};

MyRegKey::~MyRegKey()
{
    RegCloseKey(*m_phkey);
    
};