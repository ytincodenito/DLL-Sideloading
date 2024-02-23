#include <iostream>
#include <windows.h>

// Exported from AddInts.dll
// Type definition for AddInts
// int AddInts(int a, int b);
typedef int (*AddInts)(int, int);

// Exported from AddInts.dll
// Type definition for PauseMe
// void PauseMe(void);
typedef void (*PauseMe)();


int main() {
    //HMODULE LoadLibraryA(
    //    [in] LPCSTR lpLibFileName // The name of the module.
    //);
    // If the function succeeds, the return value is a handle to the module.
    // https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya
    HINSTANCE hAddLib = LoadLibrary(L"addlib.dll");
    if (hAddLib == NULL) {
        printf("Failed to load DLL.\n");
        return -1;
    }

    //FARPROC GetProcAddress(
    //    [in] HMODULE hModule, // A handle to the DLL module that contains the function or variable.
    //    [in] LPCSTR  lpProcName   // The function or variable name, or the function's ordinal value.
    //);
    // If the function succeeds, the return value is the address of the exported function or variable.
    // https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress
    PauseMe exPauseMe = (PauseMe)GetProcAddress(hAddLib, "PauseMe");
    if (exPauseMe == NULL) {
        printf("Failed to find the PauseMe function.\n");
        FreeLibrary(hAddLib);
        return -1;
    }

    // Use the function
    exPauseMe();

    //FARPROC GetProcAddress(
    //    [in] HMODULE hModule, // A handle to the DLL module that contains the function or variable.
    //    [in] LPCSTR  lpProcName   // The function or variable name, or the function's ordinal value.
    //);
    // If the function succeeds, the return value is the address of the exported function or variable.
    // https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress
    AddInts exAddInts = (AddInts)GetProcAddress(hAddLib, "AddInts");
    if (exAddInts == NULL) {
        printf("Failed to find the AddInts function.\n");
        FreeLibrary(hAddLib);
        return -1;
    }

    // Use the function
    int mathRes = exAddInts(5, 3);
    printf("The result of adding 5 and 3 is %i\n", mathRes);

    // Cleanup
    //BOOL FreeLibrary(
    //    [in] HMODULE hLibModule   // A handle to the loaded library module.
    //);
    // If the function succeeds, the return value is nonzero.
    // https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-freelibrary
    FreeLibrary(hAddLib);
    return 0;
}