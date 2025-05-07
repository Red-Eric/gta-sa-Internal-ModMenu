#pragma once
#include <Windows.h>
#include <vector>

namespace StaticOffsets {

	namespace Time {
		extern BYTE* hour;
		extern BYTE* minute;
		extern BYTE* meteo;
	}
	namespace Scores {
		extern int* dance;
		extern int* money;
		extern int* carDance;

	}

	namespace PlayerStat {
		extern float* staminaAddrs;
		extern float* muscleAddrs;
		extern float* fatAddrs;
		extern float* healthAddrs;
		extern float* sexAppealAddrs;
		extern float* respectAddrs;

		extern std::vector<float*> All;
	}

	namespace GunStat {
		extern float* pistol;
		extern float* silencedPistol;
		extern float* desertEagle;
		extern float* shotgun;
		extern float* sawnOffShotgun;
		extern float* combatShotgun;
		extern float* machinePistol;
		extern float* smg;
		extern float* ak47;
		extern float* m4;
		extern float* rifle;

		extern std::vector<float*> All;
	}

	namespace Skills {
		extern int* driving;
		extern int* flying;
		extern int* bike;
		extern int* cycling;
		extern int* luckGambling;

		extern std::vector<int*> All;
	}

}
