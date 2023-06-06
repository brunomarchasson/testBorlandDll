// ConsoleApplication1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include "windows.h"
#include <iostream>
#include <libloaderapi.h>
#include <strsafe.h>


extern "C" {
    typedef int (__stdcall *init_func_ptr)(const wchar_t * param1);
    typedef wchar_t* (__stdcall*hi_func_ptr)();
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

int main()
{
    std::string name;
    std::cout << "Test dll app" << std::endl << std::endl;
    std::cout << "Enter name" << std::endl;
    std::cin >> name;
    std::wstring widestr = std::wstring(name.begin(), name.end());
    const wchar_t* widecstr = widestr.c_str();

    auto hdl = LoadLibraryA("C:/Users/bruno/Documents/Dev/kayros/testBorlandDll/Win32/Debug/CalDevLib.dll");

    if (hdl)
    {
        auto init_func = reinterpret_cast<init_func_ptr>(GetProcAddress(hdl, "init"));
        auto hi_func = reinterpret_cast<hi_func_ptr>(GetProcAddress(hdl, "hi"));
        auto hello_func = reinterpret_cast<hi_func_ptr>(GetProcAddress(hdl, "hello"));
        const wchar_t* s = hello_func();
        std::wcout << s << std::endl;
        if (init_func)
           init_func(widecstr);
        else
            printf("no function\n");
        
        
        std::wcout << hi_func() << std::endl;
        
        FreeLibrary(hdl);
    }
    else {
        printf("can't load dll\n");
        ErrorExit(TEXT("LOAD DLL"));
    }


    /*init(widecstr);
    std::cout << hi();*/
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
