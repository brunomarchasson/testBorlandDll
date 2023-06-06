#include "windows.h"
#include <iostream>
#include <string>
#include "caldev.h"
#include "CalDev.h"
#include <libloaderapi.h>
#include <strsafe.h>

auto hdl = LoadLibraryA("../Win32/Debug/CalDevLib.dll");

auto init_func = reinterpret_cast<init_func_ptr>(GetProcAddress(hdl, "init"));
auto hi_func = reinterpret_cast<hi_func_ptr>(GetProcAddress(hdl, "hi"));
auto hello_func = reinterpret_cast<hi_func_ptr>(GetProcAddress(hdl, "hello"));

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

void init( std::wstring name ) {
   hdl = LoadLibraryA("C:/Users/bruno/Documents/Dev/kayros/testBorlandDll/Win64/Debug/CalDevLib.dll");
if (hdl == NULL)
    ErrorExit(TEXT("LOAD DLL"));
    //  init_func = reinterpret_cast<init_func_ptr>(GetProcAddress(hdl, "init"));

    printf("init%s", hdl);
    printf("init_func%s", init_func);
    init_func(name.c_str());
}
std::wstring hi( void ){
return hi_func();
}