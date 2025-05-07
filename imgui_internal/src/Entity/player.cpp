#include "player.h"

Player::Player()
{
	HealthAddr = (float*)getPointerAddress((uintptr_t)(gameBase + 0x76F3B8), { 0x540 });
	pos.X = (float*)getPointerAddress((uintptr_t)(gameBase + 0x76F5F0), { 0x14, 0x30 });
	pos.Y = (float*)getPointerAddress((uintptr_t)(gameBase + 0x76F5F0), { 0x14, 0x34 });
	pos.Z = (float*)getPointerAddress((uintptr_t)(gameBase + 0x76F5F0), { 0x14, 0x38 });
}
