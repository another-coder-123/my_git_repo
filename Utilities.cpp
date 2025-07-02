#include <Windows.h>
#include <iostream>

void MakePopUp()
{
    int msgboxID = MessageBox(NULL, (LPCWSTR)L"Hey! Its my popup!", (LPCWSTR)L"Message by Mika", NULL);
    switch (msgboxID)
    {
    case IDOK:
        std::cout << "OK was Pressed" << std::endl;
        break;
    default:
        break;
    }
}
