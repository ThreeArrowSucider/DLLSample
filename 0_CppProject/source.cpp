#include <iostream>
#include <string>

// extern"C"...C����̎d�l�ŃR���p�C����������, __declspec(dllexport)...�O������Q�Ƃł���悤�ɂ���(dll�Ɋ܂߂�j
#define DllExport extern "C" __declspec(dllexport)

DllExport int Test(int num)
{
    return num * 1000;
}

DllExport void strout(char* str)
{
    std::cout << str << std::endl;

    return;
}