#pragma once

typedef int(__stdcall* weaponN)();

weaponN GetTestFuncFromAddress(void* addr);
