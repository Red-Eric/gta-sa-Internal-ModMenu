#include <Windows.h>
#include<iostream>
#include "Memory/mem.h"
#include "Global/global.h"
#include "NameSpace/cheat.h"
#include "NameSpace/stat.h"
#include "hook/hook.h"
#include "hook/health.h"
#include "Entity/player.h"


DWORD WINAPI injected_thread(LPVOID lpParam) {
    HMODULE hModule = (HMODULE)lpParam;
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);

    while (true) {
        if (GetKeyState(VK_F2) < 0) {
            system("cls");
            std::cout <<"called" << std::endl;
            Sleep(100);
        }

        if (GetKeyState(VK_F12) < 0) {
            system("cls");
            healthHook::OFF();
            std::cout << "Dettach" << std::endl;
            break;
        }
        Sleep(100);
    }
    FreeConsole();
    FreeLibraryAndExitThread(hModule, 0);
    return 0;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    if (fdwReason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hinstDLL);
        CreateThread(NULL, 0, injected_thread, hinstDLL, 0, NULL);
    }
    return TRUE;
}
