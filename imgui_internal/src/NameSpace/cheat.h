#pragma once
#include <Windows.h>
#include "../Global/global.h"

namespace CheatCode {
	extern BYTE* noCops;
	extern BYTE* noReload;
	extern BYTE* SuperJump;

	namespace noCopsToogle {
		void ON();
		void OFF();
	}

	namespace noReloadToogle {
		void ON();
		void OFF();
	}

	namespace superJumpToogle {
		void ON();
		void OFF();
	}
}