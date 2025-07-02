#pragma once
#include <string>
#include <memory>

class MyRegKey {
public:
    MyRegKey();
    MyRegKey(const MyRegKey& other);
    MyRegKey& operator=(const MyRegKey& other);
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