#pragma once
#include <string>
#include <Windows.h>
#include <memory>

class MyRegKey {
public:
    MyRegKey();
    MyRegKey(const MyRegKey& other);
    MyRegKey& operator=(const MyRegKey& other);
    void setValue(const char* sub_key_path, const char* value_name, const char* value_data);
    ~MyRegKey();
private:
    /**
    * Returns true if 'value_name' is already defined in subkey
    * Returns false if it does not exist
    */
    bool doesValueExist(const char* sub_key_path, const char* value_name);

    std::unique_ptr<HKEY> m_phkey;
};