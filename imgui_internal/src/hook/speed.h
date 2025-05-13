#pragma once
#include "hook.h"
#include "../Global/global.h"
#include "../Memory/mem.h"
#include <iostream>

void speedPlayerFunc();
void flyFunc();
void forward();
namespace speedPlayerFuncToogle {
	void ON();
	void OFF();
}

namespace flyToogle {
	void ON();
	void OFF();
}