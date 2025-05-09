#pragma once
#include "hook.h"
#include "../Global/global.h"
#include "../Memory/mem.h"
#include <iostream>

void healthHookFunction();

namespace healthHook {
	void ON();
	void OFF();
}