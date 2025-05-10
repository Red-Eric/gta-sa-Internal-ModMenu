#include <iostream>
#include <d3d9.h>
#include <d3dx9.h>
#include <imgui.h>
#include <imgui_impl_dx9.h>
#include <imgui_impl_win32.h>
#include <Windows.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "detours.lib")

#include "detours.h"
#include "frontEnd/frontEnd.h"

HINSTANCE DllHandle;
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


typedef HRESULT(__stdcall* endScene)(IDirect3DDevice9* pDevice);
endScene pEndScene = nullptr;

typedef BOOL(WINAPI* tSetCursorPos)(int X, int Y);
tSetCursorPos oSetCursorPos = nullptr;

WNDPROC oWndProc = nullptr;
LPD3DXFONT font;
IDirect3DDevice9* pCurrentDevice = nullptr;
bool showMenu = true;

BOOL WINAPI hkSetCursorPos(int X, int Y) {
    if (showMenu) {
        return TRUE;
    }
    return oSetCursorPos(X, Y);
}


LRESULT CALLBACK hkWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    if (showMenu && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
        return true;
    return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}


HRESULT __stdcall hookedEndScene(IDirect3DDevice9* pDevice) {
    if (!pCurrentDevice) {
        pCurrentDevice = pDevice;
        HWND hWnd = GetForegroundWindow();
        ImGui::CreateContext();
        ImGui_ImplWin32_Init(hWnd);
        ImGui_ImplDX9_Init(pDevice);
        oWndProc = (WNDPROC)SetWindowLongPtr(hWnd, GWLP_WNDPROC, (LONG_PTR)hkWndProc);
    }

    ImGui_ImplDX9_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();

    ImGui::GetIO().MouseDrawCursor = showMenu;

    f_showMenu(showMenu);

    ImGui::Render();
    ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

    return pEndScene(pDevice);
}

void hookEndScene() {
    IDirect3D9* pD3D = Direct3DCreate9(D3D_SDK_VERSION);
    if (!pD3D)
        return;

    D3DPRESENT_PARAMETERS d3dparams = {};
    d3dparams.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dparams.hDeviceWindow = GetForegroundWindow();
    d3dparams.Windowed = true;

    IDirect3DDevice9* pDevice = nullptr;
    if (FAILED(pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, d3dparams.hDeviceWindow,
        D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dparams, &pDevice))) {
        pD3D->Release();
        return;
    }

    void** vTable = *reinterpret_cast<void***>(pDevice);
    pEndScene = (endScene)DetourFunction((PBYTE)vTable[42], (PBYTE)hookedEndScene);

    pDevice->Release();
    pD3D->Release();
}

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

    oSetCursorPos = (tSetCursorPos)DetourFunction(
        (PBYTE)GetProcAddress(GetModuleHandleA("user32.dll"), "SetCursorPos"),
        (PBYTE)hkSetCursorPos
    );

    while (true) {
        Sleep(50);

        if (GetAsyncKeyState(VK_F2) & 0x8000) {
            showMenu = !showMenu;
            Sleep(200);
        }

        if (GetAsyncKeyState(VK_F12) & 0x8000) {
            HWND hWnd = GetForegroundWindow();
            SetWindowLongPtr(hWnd, GWLP_WNDPROC, (LONG_PTR)oWndProc);
            DetourRemove((PBYTE)pEndScene, (PBYTE)hookedEndScene);
            DetourRemove((PBYTE)oSetCursorPos, (PBYTE)hkSetCursorPos);
            break;
        }
    }
    std::cout << "Detaching" << std::endl;
    fclose(fp);
    FreeConsole();
    CreateThread(0, 0, EjectThread, 0, 0, 0);
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        DllHandle = hModule;
        CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Menue, NULL, 0, NULL);
    }
    return TRUE;
}