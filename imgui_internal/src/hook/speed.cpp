#include "speed.h"
#include <Windows.h>
#include <iostream>
#include "../Global/global.h"
#include <cmath>
#define M_PI 3.14159265358979323846f

uintptr_t speedHookAddrs = gameBase + 0x1E52C7;
uintptr_t jmpbackSpeed = speedHookAddrs + 0x6;

// Speedddd
__declspec(naked) void speedPlayerFunc() {
    __asm {
        cmp esi, dword ptr ds : [0xB6F3B8]
        jne originalCode

        push eax
        push 0xA0
        call GetAsyncKeyState
        test ax, ax
        pop eax
        jz originalCode

        fmul dword ptr ds : [speedPlayer]
        fstp dword ptr[esi + 0x550]

        fld dword ptr[esi + 0x554]
        fmul dword ptr ds : [speedPlayer]
        fstp dword ptr[esi + 0x554]

        jmp jmpbackSpeed

        originalCode :
        fstp dword ptr[esi + 0x550]
            jmp jmpbackSpeed
    }
}


void speedPlayerFuncToogle::ON() {
	Hook((void*)speedHookAddrs, speedPlayerFunc, 6);
	system("cls");
	std::cout << "Speed ON" << std::endl;
}

void speedPlayerFuncToogle::OFF() {
	RestoreBytes((uintptr_t*)speedHookAddrs, { 0xD9, 0x9E, 0x50, 0x05, 0x00, 0x00 });
	system("cls");
	std::cout << "Speed OFF" << std::endl;
}

////////////////////////// FLYYYYYYYYYYYYYYYYy /////////////////////


uintptr_t flyHookAddress = gameBase + 0x144D26;
uintptr_t jmpbackFly = flyHookAddress + 0x6;

float* velXAddrs = (float*)(getPointerAddress((gameBase + 0x76F3B8), { 0x44 }));
float* velYAddrs = (float*)(getPointerAddress((gameBase + 0x76F3B8), { 0x48 }));


void forward() {
    
    float angle = *(float*)0xB7684C;
    angle -= static_cast<float>(M_PI) / 2.0f;
    float velX = -cosf(angle);
    float velY = -sinf(angle);
    *velXAddrs = velX * speedPlayer;
    *velYAddrs = velY * speedPlayer;
}



__declspec(naked) void flyFunc() {
    __asm {
        cmp esi, dword ptr ds : [0xB6F3B8]
        jne originalcodeFly

        
        push eax
        push 0x12
        call GetAsyncKeyState
        test ax, ax
        pop eax
        jz check_ctrl
        fstp dword ptr[esi + 0x4C]
        mov dword ptr[esi + 0x4C], 0x40000000
        jmp exitHookFly

        check_ctrl :
            push eax
            push 0x11
            call GetAsyncKeyState
            test ax, ax
            pop eax
            jz check_A_key
            fstp dword ptr[esi + 0x4C]
            mov dword ptr[esi + 0x4C], 0xC0000000
            jmp exitHookFly

        check_A_key :
            push eax
            push 0x41        
            call GetAsyncKeyState
            test ax, ax
            pop eax
            jz originalcodeFly

            // custom
            call forward
            fstp dword ptr[esi + 0x4C]
            mov dword ptr[esi + 0x4C], 0x00000000
            jmp exitHookFly

        originalcodeFly :
            fstp dword ptr[esi + 0x4C]
            mov dword ptr[esi + 0x4C], 0x00000000
            mov dword ptr[esi + 0x44], 0x00000000
            mov dword ptr[esi + 0x48], 0x00000000
        
        exitHookFly :

            fld dword ptr[esi + 0x50]
            jmp jmpbackFly
    }
}

//__declspec(naked) void flyFunc() {
//    __asm {
//        cmp esi, dword ptr ds : [0xB6F3B8]
//        jne originalcodeFly
//
//
//        push eax
//        push 0x12
//        call GetAsyncKeyState
//        test ax, ax
//        pop eax
//        jz check_ctrl
//        fstp dword ptr[esi + 0x4C]
//        mov dword ptr[esi + 0x4C], 0x40000000
//        jmp exitHookFly
//
//        check_ctrl :
//        push eax
//            push 0x11
//            call GetAsyncKeyState
//            test ax, ax
//            pop eax
//            jz check_A_key
//            fstp dword ptr[esi + 0x4C]
//            mov dword ptr[esi + 0x4C], 0xC0000000
//            jmp exitHookFly
//
//            check_A_key :
//        push eax
//            push 0x41
//            call GetAsyncKeyState
//            test ax, ax
//            pop eax
//            jz originalcodeFly
//
//            // custom
//
//            fstp dword ptr[esi + 0x4C]
//            mov dword ptr[esi + 0x4C], 0x00000000
//            jmp exitHookFly
//
//            originalcodeFly :
//        fstp dword ptr[esi + 0x4C]
//            mov dword ptr[esi + 0x4C], 0x00000000
//
//            exitHookFly :
//            fld dword ptr[esi + 0x50]
//            jmp jmpbackFly
//    }
//}





void flyToogle::ON()
{
	Hook((void*)flyHookAddress, flyFunc, 6);
	system("cls");
	std::cout << "Fly ON" << std::endl;
}

void flyToogle::OFF()
{
	RestoreBytes((uintptr_t*)flyHookAddress, { 0xD9, 0x5E, 0x4C, 0xD9, 0x46, 0x50 });
	system("cls");
	std::cout << "Fly OFF" << std::endl;
}
