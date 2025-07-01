#pragma once

class MyRegKey {
public:
    MyRegKey();
    ~MyRegKey();
    PHKEY m_phkey;
};

class MyMutex {
public:
    MyMutex();
    ~MyMutex();
    HANDLE m_hmutex;
};

void MakePopUp();
void AddRegValue();
