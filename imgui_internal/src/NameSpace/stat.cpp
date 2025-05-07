#include "stat.h"

namespace StaticOffsets {

	namespace Time {
		BYTE* hour = (BYTE*)0xB70153;
		BYTE* minute = (BYTE*)0xB70152;
		BYTE* meteo = (BYTE*)0xc81320;
	}

	namespace Scores {
		int* dance = (int*)0xa4ec20;
		int* money = (int*)0xb7ce50;
		int* carDance = (int*)0xa4a948;
	}

	namespace PlayerStat {
		float* staminaAddrs = (float*)0xB793D8;
		float* muscleAddrs = (float*)0xB793DC;
		float* fatAddrs = (float*)0xB793D4;
		float* healthAddrs = (float*)0xB793E0;
		float* sexAppealAddrs = (float*)0xB793E4;
		float* respectAddrs = (float*)0xB79480;

		std::vector<float*> All = {
			staminaAddrs,
			muscleAddrs,
			fatAddrs,
			healthAddrs,
			sexAppealAddrs,
			respectAddrs
		};
	}

	namespace GunStat {
		float* pistol = (float*)0xB79494;
		float* silencedPistol = (float*)0xB79498;
		float* desertEagle = (float*)0xB7949C;
		float* shotgun = (float*)0xB794A0;
		float* sawnOffShotgun = (float*)0xB794A4;
		float* combatShotgun = (float*)0xB794A8;
		float* machinePistol = (float*)0xB794AC;
		float* smg = (float*)0xB794B0;
		float* ak47 = (float*)0xB794B4;
		float* m4 = (float*)0xB794B8;
		float* rifle = (float*)0xB794BC;

		std::vector<float*> All = {
			pistol,
			silencedPistol,
			desertEagle,
			shotgun,
			sawnOffShotgun,
			combatShotgun,
			machinePistol,
			smg,
			ak47,
			m4,
			rifle
		};
	}

	namespace Skills {
		int* driving = (int*)0xB790A0;
		int* flying = (int*)0xB7919C;
		int* bike = (int*)0xB791B4;
		int* cycling = (int*)0xB791B8;
		int* luckGambling = (int*)0xB791C4;

		std::vector<int*> All = {
			driving,
			flying,
			bike,
			cycling,
			luckGambling
		};
	}

}
