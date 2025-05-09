#include <Windows.h>
#include <iostream>
#include "d9hook.h"
#include "menuToggle.h"

HINSTANCE DllHandle;

DWORD __stdcall EjectThread(LPVOID) {
    Sleep(100);
    FreeLibraryAndExitThread(DllHandle, 0);
    return 0;
}


DWORD WINAPI Menue(HINSTANCE hModule) {
    AllocConsole();
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);

    hookEndScene();
    setupCursorHook();

    while (true) {
        Sleep(50);
        if (GetAsyncKeyState(VK_F2) & 0x8000) {
            showMenu = !showMenu;
            Sleep(200);
        }

        if (GetAsyncKeyState(VK_F12) & 0x8000) {
            removeCursorHook();
            break;
        }
    }

    std::cout << "Detaching and exiting..." << std::endl;
    fclose(fp);
    FreeConsole();
    CreateThread(0, 0, EjectThread, 0, 0, 0);
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        DllHandle = hModule;
        CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Menue, hModule, 0, NULL);
    }
    return TRUE;
}
