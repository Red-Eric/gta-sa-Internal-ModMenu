#include "cheat.h"

namespace CheatCode {
	BYTE* noCops = (BYTE*)(gameBase + 0x569171);
	BYTE* noReload = (BYTE*)(gameBase + 0x569178);
	BYTE* SuperJump = (BYTE*)(gameBase + 0x56916C);
}


void CheatCode::noCopsToogle::ON()
{
	*noCops = 1;
}

void CheatCode::noCopsToogle::OFF()
{
	*noCops = 0;
}

void CheatCode::noReloadToogle::ON()
{
	*noReload = 1;
}

void CheatCode::noReloadToogle::OFF()
{
	*noReload = 0;
}

void CheatCode::superJumpToogle::ON()
{
	*SuperJump = 1;
}

void CheatCode::superJumpToogle::OFF()
{
	*SuperJump = 0;
}
