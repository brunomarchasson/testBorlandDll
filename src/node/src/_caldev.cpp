#include "windows.h"
#include "CalDevDefs.h"
#include <iostream>
#include <string>
#include "_caldev.h"
#include <libloaderapi.h>
#include <strsafe.h>

extern "C" {
    typedef int (__stdcall *init_func_ptr)(const wchar_t * param1);
    typedef wchar_t* (__stdcall*hi_func_ptr)();
}

auto hdl = LoadLibraryA("../Win64/Debug/CalDevLib.dll");
// auto hdl;// = LoadLibraryA("C:/Users/bruno/Documents/Dev/kayros/testBorlandDll/Win64/Debug/CalDevLib.dll");
auto init_func = reinterpret_cast<init_func_ptr>(GetProcAddress(hdl, "CalDev_init"));
auto hi_func= reinterpret_cast<hi_func_ptr>(GetProcAddress(hdl, "CalDev_hi"));
auto hello_func= reinterpret_cast<hi_func_ptr>(GetProcAddress(hdl, "CalDev_hello"));
// auto CalDev_load = reinterpret_cast<hi_func_ptr>(GetProcAddress(hdl, "hello"));

std::string helloUser( std::string name ) {
  return "Hello " + name + "!";
}

void ErrorExit(LPCTSTR lpszFunction)
{
    // Retrieve the system error message for the last-error code
    LPVOID lpMsgBuf;
    LPVOID lpDisplayBuf;
    DWORD dw = GetLastError();

    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER |
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dw,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR)&lpMsgBuf,
        0, NULL);

    // Display the error message and exit the process

    lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT,
        (lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)lpszFunction) + 40) * sizeof(TCHAR));
    StringCchPrintf((LPTSTR)lpDisplayBuf,
        LocalSize(lpDisplayBuf) / sizeof(TCHAR),
        TEXT("%s failed with error %d: %s"),
        lpszFunction, dw, lpMsgBuf);
    MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK);

    LocalFree(lpMsgBuf);
    LocalFree(lpDisplayBuf);
    ExitProcess(dw);
}

void CalDev_init( std::wstring name ) {
   if (hdl == NULL)
        hdl = LoadLibraryA("C:/Users/bruno/Documents/Dev/kayros/testBorlandDll/Win64/Debug/CalDevLib.dll");
    if (hdl == NULL)
        ErrorExit(TEXT("LOAD DLL"));
    init_func = reinterpret_cast<init_func_ptr>(GetProcAddress(hdl, "CalDev_init"));
    hi_func= reinterpret_cast<hi_func_ptr>(GetProcAddress(hdl, "CalDev_hi"));
    printf("init%s", hdl);
    printf("init_func%s", init_func);
    init_func(name.c_str());
}


std::wstring CalDev_hi( void ){
return hi_func();
}