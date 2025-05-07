#include "hook.h"

bool Hook(void* toHook, void* ourFunct, int len)
{
    if (len < 5) {
        return false;
    }
    DWORD curProtection;
    VirtualProtect(toHook, len, PAGE_EXECUTE_READWRITE, &curProtection);
    // nop(0x90) x len 
    memset(toHook, 0x90, len);

    uintptr_t relativeAddress = ((uintptr_t)ourFunct - (uintptr_t)toHook) - 5;
    *(BYTE*)toHook = 0xE9;
    *(uintptr_t*)((uintptr_t)toHook + 1) = relativeAddress;

    DWORD temp;
    VirtualProtect(toHook, len, curProtection, &temp);
    return true;
}

void RestoreBytes(uintptr_t* address, const std::vector<BYTE> originalBytes) {
    DWORD oldProtect;
    if (VirtualProtect(address, originalBytes.size(), PAGE_EXECUTE_READWRITE, &oldProtect)) {
        memcpy(reinterpret_cast<void*>(address), originalBytes.data(), originalBytes.size());
        VirtualProtect(address, originalBytes.size(), oldProtect, &oldProtect);
    }
}

