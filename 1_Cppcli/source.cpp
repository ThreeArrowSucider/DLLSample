#include <windows.h>
#include <filesystem>
#include <string>

#define DllExport extern "C" __declspec(dllexport)

// 関数ポインタ型
typedef int(*FUNC1)(int num);
typedef void(*FUNC2)(char* str);

using wstr = std::wstring;
namespace fs = std::filesystem;


#ifdef _M_IX86 // 32bitか64bitか判定

DllExport int __stdcall wrap(int num)
{
    wstr dir = wstr(fs::current_path()) + L"\\0_CppProject32.dll";

    HMODULE hModule = LoadLibrary(dir.c_str());

    if (hModule == NULL)
        return -1;

    FUNC1 func = (FUNC1)GetProcAddress(hModule, "Test");

    return func(num) + 32;
}

#else

DllExport int __stdcall wrap(int num)
{
    wstr dir = wstr(fs::current_path()) + L"\\0_CppProject64.dll";

    HMODULE hModule = LoadLibrary(dir.c_str());

    if (hModule == NULL)
        return -1;

    FUNC1 func = (FUNC1)GetProcAddress(hModule, "Test");

    return func(num) + 64;
}

#endif


#ifdef _M_IX86

DllExport void __stdcall strout(char* str)
{
    wstr dir = wstr(fs::current_path()) + L"\\0_CppProject32.dll";

    HMODULE hModule = LoadLibrary(dir.c_str());

    if (hModule == NULL)
        return;

    FUNC2 func = (FUNC2)GetProcAddress(hModule, "strout");

    func(str);

    return;
}

#else

DllExport void __stdcall strout(char* str)
{
    wstr dir = wstr(fs::current_path()) + L"\\0_CppProject64.dll";

    HMODULE hModule = LoadLibrary(dir.c_str());

    if (hModule == NULL)
        return;

    FUNC2 func = (FUNC2)GetProcAddress(hModule, "strout");

    func(str);

    return;
}

#endif