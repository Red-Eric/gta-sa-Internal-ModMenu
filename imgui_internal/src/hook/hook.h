#pragma once
#include <Windows.h>
#include <vector>

bool Hook(void* toHook, void* ourFunct, int len);
void RestoreBytes(uintptr_t* address, const std::vector<BYTE> originalBytes);