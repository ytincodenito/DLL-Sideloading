// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

// Exports a function by name or ordinal, or data, from your program.
//EXPORT:entryname[,@ordinal[,NONAME]][,DATA] 
//#pragma comment(linker, "/export:PlainFuncName=_PlainFuncName@4")
//https://learn.microsoft.com/en-us/cpp/build/reference/export-exports-a-function?view=msvc-170
#pragma comment(linker, "/export:PauseMe=_addlib.PauseMe,@2")
#pragma comment(linker, "/export:AddInts=_addlib.AddInts,@1")

// You can export data, functions, classes, or class member functions from a DLL using the __declspec(dllexport) keyword. 
// __declspec(dllexport) adds the export directive to the object file so you do not need to use a .def file.
// ex: __declspec(dllexport) void __cdecl Function1(void);
// If you have functions in a DLL written in C, you can use a preprocessor macro to make them easy to access from both C language and C++ language code.
// ex: extern "C" __declspec(dllexport) void __cdecl Function1(void);
// https://learn.microsoft.com/en-us/cpp/build/exporting-from-a-dll-using-declspec-dllexport?view=msvc-170
// https://learn.microsoft.com/en-us/cpp/build/exporting-c-functions-for-use-in-c-or-cpp-language-executables?view=msvc-170
extern "C" __declspec(dllexport) VOID PauseMe(void)
{
    //int MessageBox(
    //    [in, optional] HWND    hWnd,      //  handle to the owner window of the message box to be created.
    //    [in, optional] LPCTSTR lpText,    // The message to be displayed.
    //    [in, optional] LPCTSTR lpCaption, // The dialog box title.
    //    [in]           UINT    uType      // The contents and behavior of the dialog box.
    //);
    // https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-messagebox
    MessageBoxA(
        NULL,
        "Called when the export function PauseMe is called",
        "PauseMe Export",
        MB_OK);
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        //int MessageBox(
        //    [in, optional] HWND    hWnd,      //  handle to the owner window of the message box to be created.
        //    [in, optional] LPCTSTR lpText,    // The message to be displayed.
        //    [in, optional] LPCTSTR lpCaption, // The dialog box title.
        //    [in]           UINT    uType      // The contents and behavior of the dialog box.
        //);
        // https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-messagebox
        MessageBoxA(
            NULL,
            "Called when the DLL is attached to the process.",
            "DLL_PROCESS_ATTACH",
            MB_OK);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

