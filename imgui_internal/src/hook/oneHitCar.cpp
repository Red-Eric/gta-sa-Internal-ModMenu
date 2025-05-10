#include "oneHitCar.h"

uintptr_t carShootAddrs = (gameBase + 0x2D8083);
uintptr_t jumbBack = carShootAddrs + 0x06;

__declspec(naked) void oneHitCarHookFunc() {
	__asm {
		push eax
		mov eax, [0xB6F3B8]
		mov eax, [eax]          
		cmp edi, eax            
		jne exitOneHitHook

		onehitk :
		fstp dword ptr[esi + 0x4C0]
			mov dword ptr[esi + 0x4C0], 0x0

		exitOneHitHook :
			pop eax
			jmp[jumbBack]
	}
}

void oneHitCarToogle::ON()
{
	Hook((void*)carShootAddrs, oneHitCarHookFunc, 6);
}

void oneHitCarToogle::OFF()
{
	RestoreBytes((uintptr_t*)carShootAddrs, { 0xD9, 0x9E, 0xC0, 0x04, 0x00, 0x00 });
}

