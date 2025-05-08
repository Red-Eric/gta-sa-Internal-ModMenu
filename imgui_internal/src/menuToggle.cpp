#include "menuToggle.h"
#include <detours.h>

typedef BOOL(WINAPI* tSetCursorPos)(int X, int Y);
static tSetCursorPos oSetCursorPos = nullptr;

bool showMenu = true;

BOOL WINAPI hkSetCursorPos(int X, int Y) {
    if (showMenu) return TRUE;
    return oSetCursorPos(X, Y);
}

void setupCursorHook() {
    oSetCursorPos = (tSetCursorPos)DetourFunction(
        (PBYTE)GetProcAddress(GetModuleHandleA("user32.dll"), "SetCursorPos"),
        (PBYTE)hkSetCursorPos
    );
}

void removeCursorHook() {
    if (oSetCursorPos) {
        DetourRemove((PBYTE)oSetCursorPos, (PBYTE)hkSetCursorPos);
    }
}
