#include <iostream>
#include <string>

// extern"C"...C言語の仕様でコンパイルをかける, __declspec(dllexport)...外部から参照できるようにする(dllに含める）
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