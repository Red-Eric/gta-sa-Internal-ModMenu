#include "health.h"

uintptr_t healthHookAddrss = gameBase + 0xB331F;
uintptr_t jmpback = healthHookAddrss + 0x6;
float* playerHealthAddrs = (float*)getPointerAddress((gameBase + 0x76F3B8), { 0x540 }) + 0x00;

// [400000+76F3B8]+540

__declspec(naked) void healthHookFunction() {
	
	__asm {
		cmp dword ptr [esi+0x544], 0x43300000
		je exitCodeCaveHealth

		normalHealthComp:
			mov dword ptr[esi + 0x540], edx
		exitCodeCaveHealth:
			jmp[jmpback]
	}
	
}

void healthHook::ON()
{
	Hook((void*)healthHookAddrss, healthHookFunction, 6);
	system("cls");
	std::cout << "Health Hook ON" << std::endl;
}

void healthHook::OFF()
{
	RestoreBytes((uintptr_t*)healthHookAddrss, { 0x89 ,0x96 ,0x40 ,0x05 ,0x00 ,0x00 });
	system("cls");
	std::cout << "Health Hook OFF" << std::endl;
}
