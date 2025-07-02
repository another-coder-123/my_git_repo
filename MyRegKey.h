#pragma once
#include <string>
#include <memory>

class RegistryAccessException : public std::exception
{
private:
    std::string error_msg;

public:
    RegistryAccessException(const std::string& error) : error_msg(error) {}
    const char* what() const noexcept;
};


class MyRegKey {
public:
    MyRegKey();
    void SetValue(LPCSTR sub_key_path, LPCSTR value_name, LPCSTR value_data);
    ~MyRegKey();
private:
    /**
    * Returns true if 'value_name' is already defined in subkey
    * Returns false if it does not exist
    */
    bool IsValueExists(LPCSTR sub_key_path, LPCSTR value_name);

    std::unique_ptr<HKEY> m_hkey;
};