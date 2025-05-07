#include "threadEx.h"

void spawnCar(DWORD carID){
    BYTE shellcode[] = {
        0x68, 0x00, 0x00, 0x00, 0x00,
        0xB8, 0xB0, 0xA0, 0x43, 0x00,
        0xFF, 0xD0,
        0x59,
        0xC3
    };

    *(DWORD*)(shellcode + 1) = carID;

    void* exec = VirtualAlloc(NULL, sizeof(shellcode), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (exec) {
        memcpy(exec, shellcode, sizeof(shellcode));
        HANDLE hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)exec, NULL, 0, NULL);
        if (hThread)
            CloseHandle(hThread);
    }
}