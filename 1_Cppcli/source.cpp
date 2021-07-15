#include <windows.h>
//#include <filesystem>
//#include <string>

#define DllExport extern "C" __declspec(dllexport)

// ä÷êîÉ|ÉCÉìÉ^å^
typedef int(*FUNC1)(int num);

//using wstr = std::wstring;
//namespace fs = std::filesystem;


//#ifdef _M_IX86 // 32bitîªíË

//DllExport void /*__stdcall*/ wrap_32()
//{
//    //wstr dir = wstr(fs::current_path()) + L"\\0_CppProject32.dll";
//    wchar_t* dir = L"C:\\Users\\KOUDO\\source\\repos\\DLLSample\\2_CsMain\\bin\\Debug\\netcoreapp3.1\\0_CppProject32.dll";
//    HMODULE hModule = LoadLibrary(dir/*.c_str()*/);
//
//    if (hModule == NULL)
//        return /*-1*/;
//
//    FUNC1 func = (FUNC1)GetProcAddress(hModule, "Test");
//
//    //return func(num) + 32;
//}

DllExport void __stdcall func() {
    ;
}

////#else
// 
//DllExport int __stdcall wrap_64(int num) {
//    wstr dir = wstr(fs::current_path()) + L"\\0_CppProject32.dll";
//
//    HMODULE hModule = LoadLibrary(dir.c_str());
//
//    if (hModule == NULL)
//        return -1;
//
//    FUNC1 func = (FUNC1)GetProcAddress(hModule, "Test");
//
//    return func(num) + 64;
//}

//#endif