#include <windows.h>
#include <filesystem>
#include <string>

#define DllExport extern "C" __declspec(dllexport)

// ä÷êîÉ|ÉCÉìÉ^å^
typedef int(*FUNC1)(int num);

using wstr = std::wstring;
namespace fs = std::filesystem;


#ifdef _M_IX86 // 32bitîªíË
#endif
DllExport int __stdcall wrap_32(int num)
{
    wstr dir = wstr(fs::current_path()) + L"\\0_CppProject32.dll";

    HMODULE hModule = LoadLibrary(dir.c_str());

    if (hModule == NULL)
        return -1;

    FUNC1 func = (FUNC1)GetProcAddress(hModule, "Test");

    return func(num) + 32;
}

 
DllExport int __stdcall wrap_64(int num) 
{
    wstr dir = wstr(fs::current_path()) + L"\\0_CppProject64.dll";

    HMODULE hModule = LoadLibrary(dir.c_str());

    if (hModule == NULL)
        return -1;

    FUNC1 func = (FUNC1)GetProcAddress(hModule, "Test");

    return func(num) + 64;
}

