#include "all.h"
#include <imgui.h>
#include "../hook/threadEx.h"
#include "../NameSpace/cheat.h"
#include "../NameSpace/stat.h"
#include "../hook/health.h"
#include "../hook/speed.h"


void vehicles()
{
    ImGui::Spacing();
    if (ImGui::CollapsingHeader("Airplane")) {
        ImGui::Indent(30.0f);
        if (ImGui::Button("Andromada")) spawnCar(592);
        if (ImGui::Button("AT-400")) spawnCar(577);
        if (ImGui::Button("Beagle")) spawnCar(511);
        if (ImGui::Button("Cropduster")) spawnCar(512);
        if (ImGui::Button("Dodo")) spawnCar(593);
        if (ImGui::Button("Hydra")) spawnCar(520);
        if (ImGui::Button("Nevada")) spawnCar(553);
        if (ImGui::Button("Rustler")) spawnCar(476);
        if (ImGui::Button("Shamal")) spawnCar(519);
        if (ImGui::Button("Skimmer")) spawnCar(460);
        if (ImGui::Button("Stuntplane")) spawnCar(513);
        ImGui::Unindent(30.0f);
    }
    ImGui::Spacing();
    if (ImGui::CollapsingHeader("Helicopter")) {
        ImGui::Indent(30.0f);

        if (ImGui::Button("Cargobob")) spawnCar(548);
        if (ImGui::Button("Hunter")) spawnCar(425);
        if (ImGui::Button("Leviathan")) spawnCar(417);
        if (ImGui::Button("Maverick")) spawnCar(487);
        if (ImGui::Button("News Chopper")) spawnCar(488);
        if (ImGui::Button("Police Maverick")) spawnCar(497);
        if (ImGui::Button("Raindance")) spawnCar(563);
        if (ImGui::Button("Seasparrow")) spawnCar(447);
        if (ImGui::Button("Sparrow")) spawnCar(469);

        ImGui::Unindent(30.0f);
    }
    ImGui::Spacing();
    if (ImGui::CollapsingHeader("Boat")) {
        ImGui::Indent(30.0f);

        if (ImGui::Button("Coastguard")) spawnCar(472);
        if (ImGui::Button("Dinghy")) spawnCar(473);
        if (ImGui::Button("Jetmax")) spawnCar(493);
        if (ImGui::Button("Launch")) spawnCar(595);
        if (ImGui::Button("Marquis")) spawnCar(484);
        if (ImGui::Button("Predator")) spawnCar(430);
        if (ImGui::Button("Reefer")) spawnCar(453);
        if (ImGui::Button("Speeder")) spawnCar(452);
        if (ImGui::Button("Squalo")) spawnCar(446);
        if (ImGui::Button("Tropic")) spawnCar(454);

        ImGui::Unindent(30.0f);
    }
    ImGui::Spacing();
    if (ImGui::CollapsingHeader("Bike")) {
        ImGui::Indent(30.0f);

        if (ImGui::Button("BF-400")) spawnCar(581);
        if (ImGui::Button("Bike_")) spawnCar(509);
        if (ImGui::Button("BMX")) spawnCar(481);
        if (ImGui::Button("Faggio")) spawnCar(462);
        if (ImGui::Button("FCR-900")) spawnCar(521);
        if (ImGui::Button("Freeway")) spawnCar(463);
        if (ImGui::Button("Mountain Bike")) spawnCar(510);
        if (ImGui::Button("NRG-500")) spawnCar(522);
        if (ImGui::Button("PCJ-600")) spawnCar(461);
        if (ImGui::Button("Pizzaboy")) spawnCar(448);
        if (ImGui::Button("Sanchez")) spawnCar(468);
        if (ImGui::Button("Wayfarer")) spawnCar(586);

        ImGui::Unindent(30.0f);
    }
    ImGui::Spacing();
    if (ImGui::CollapsingHeader("2-Door & Compact cars")) {
        ImGui::Indent(30.0f);

        if (ImGui::Button("Alpha")) spawnCar(602);
        if (ImGui::Button("Blista Compact")) spawnCar(496);
        if (ImGui::Button("Bravura")) spawnCar(401);
        if (ImGui::Button("Buccaneer")) spawnCar(518);
        if (ImGui::Button("Cadrona")) spawnCar(527);
        if (ImGui::Button("Club")) spawnCar(589);
        if (ImGui::Button("Esperanto")) spawnCar(419);
        if (ImGui::Button("Euros")) spawnCar(587);
        if (ImGui::Button("Feltzer")) spawnCar(533);
        if (ImGui::Button("Fortune")) spawnCar(526);
        if (ImGui::Button("Hermes")) spawnCar(474);
        if (ImGui::Button("Hustler")) spawnCar(545);
        if (ImGui::Button("Majestic")) spawnCar(517);
        if (ImGui::Button("Manana")) spawnCar(410);
        if (ImGui::Button("Picador")) spawnCar(600);
        if (ImGui::Button("Previon")) spawnCar(436);
        if (ImGui::Button("Stallion")) spawnCar(439);
        if (ImGui::Button("Tampa")) spawnCar(549);
        if (ImGui::Button("Virgo")) spawnCar(491);

        ImGui::Unindent(30.0f);
    }
    ImGui::Spacing();
    if (ImGui::CollapsingHeader("4-Door & Luxury cars")) {
        ImGui::Indent(30.0f);

        if (ImGui::Button("Admiral")) spawnCar(445);
        if (ImGui::Button("Damaged Glendale")) spawnCar(604);
        if (ImGui::Button("Elegant")) spawnCar(507);
        if (ImGui::Button("Emperor")) spawnCar(585);
        if (ImGui::Button("Glendale")) spawnCar(466);
        if (ImGui::Button("Greenwood")) spawnCar(492);
        if (ImGui::Button("Intruder")) spawnCar(546);
        if (ImGui::Button("Merit")) spawnCar(551);
        if (ImGui::Button("Nebula")) spawnCar(516);
        if (ImGui::Button("Oceanic")) spawnCar(467);
        if (ImGui::Button("Premier")) spawnCar(426);
        if (ImGui::Button("Primo")) spawnCar(547);
        if (ImGui::Button("Sentinel")) spawnCar(405);
        if (ImGui::Button("Stafford")) spawnCar(580);
        if (ImGui::Button("Stretch")) spawnCar(409);
        if (ImGui::Button("Sunrise")) spawnCar(550);
        if (ImGui::Button("Tahoma")) spawnCar(566);
        if (ImGui::Button("Vincent")) spawnCar(540);
        if (ImGui::Button("Washington")) spawnCar(421);
        if (ImGui::Button("Willard")) spawnCar(529);

        ImGui::Unindent(30.0f);
    }
    ImGui::Spacing();
    if (ImGui::CollapsingHeader("Civil Service")) {
        ImGui::Indent(30.0f);

        if (ImGui::Button("Baggage")) spawnCar(485);
        if (ImGui::Button("Bus")) spawnCar(431);
        if (ImGui::Button("Cabbie")) spawnCar(438);
        if (ImGui::Button("Coach")) spawnCar(437);
        if (ImGui::Button("Sweeper")) spawnCar(574);
        if (ImGui::Button("Taxi")) spawnCar(420);
        if (ImGui::Button("Towtruck")) spawnCar(525);
        if (ImGui::Button("Trashmaster")) spawnCar(408);
        if (ImGui::Button("Utility Van")) spawnCar(552);

        ImGui::Unindent(30.0f);
    }
    ImGui::Spacing();
    if (ImGui::CollapsingHeader("Government vehicles")) {
        ImGui::Indent(30.0f);

        if (ImGui::Button("Ambulance")) spawnCar(416);
        if (ImGui::Button("Barracks")) spawnCar(433);
        if (ImGui::Button("Enforcer")) spawnCar(427);
        if (ImGui::Button("FBI Rancher")) spawnCar(490);
        if (ImGui::Button("FBI Truck")) spawnCar(528);
        if (ImGui::Button("Fire Truck")) spawnCar(407);
        if (ImGui::Button("Fire Truck (LA)")) spawnCar(544);
        if (ImGui::Button("HPV1000")) spawnCar(523);
        if (ImGui::Button("Patriot")) spawnCar(470);
        if (ImGui::Button("Police LS")) spawnCar(596);
        if (ImGui::Button("Police LV")) spawnCar(598);
        if (ImGui::Button("Police Ranger")) spawnCar(599);
        if (ImGui::Button("Police SF")) spawnCar(597);
        if (ImGui::Button("Rhino")) spawnCar(432);
        if (ImGui::Button("S.W.A.T.")) spawnCar(601);
        if (ImGui::Button("Securicar")) spawnCar(428);

        ImGui::Unindent(30.0f);
    }
    ImGui::Spacing();
    if (ImGui::CollapsingHeader("Heavy & Utility trucks")) {
        ImGui::Indent(30.0f);

        if (ImGui::Button("Benson")) spawnCar(499);
        if (ImGui::Button("Boxville Mission")) spawnCar(609);
        if (ImGui::Button("Boxville")) spawnCar(498);
        if (ImGui::Button("Cement Truck")) spawnCar(524);
        if (ImGui::Button("Combine Harvester")) spawnCar(532);
        if (ImGui::Button("DFT-30")) spawnCar(578);
        if (ImGui::Button("Dozer")) spawnCar(486);
        if (ImGui::Button("Dumper")) spawnCar(406);
        if (ImGui::Button("Dune")) spawnCar(573);
        if (ImGui::Button("Flatbed")) spawnCar(455);
        if (ImGui::Button("Hotdog")) spawnCar(588);
        if (ImGui::Button("Linerunner")) spawnCar(403);
        if (ImGui::Button("Mr. Whoopee")) spawnCar(423);
        if (ImGui::Button("Mule")) spawnCar(414);
        if (ImGui::Button("Packer")) spawnCar(443);
        if (ImGui::Button("Roadtrain")) spawnCar(515);
        if (ImGui::Button("Tanker")) spawnCar(514);
        if (ImGui::Button("Tractor")) spawnCar(531);
        if (ImGui::Button("Yankee")) spawnCar(456);

        ImGui::Unindent(30.0f);
    }
    ImGui::Spacing();
    if (ImGui::CollapsingHeader("Light trucks & Vans")) {
        ImGui::Indent(30.0f);

        if (ImGui::Button("Berkley's RC Van")) spawnCar(459);
        if (ImGui::Button("Bobcat")) spawnCar(422);
        if (ImGui::Button("Burrito")) spawnCar(482);
        if (ImGui::Button("Damaged Sadler")) spawnCar(605);
        if (ImGui::Button("Forklift")) spawnCar(530);
        if (ImGui::Button("Moonbeam")) spawnCar(418);
        if (ImGui::Button("Mower")) spawnCar(572);
        if (ImGui::Button("News Van")) spawnCar(582);
        if (ImGui::Button("Pony")) spawnCar(413);
        if (ImGui::Button("Rumpo")) spawnCar(440);
        if (ImGui::Button("Sadler")) spawnCar(543);
        if (ImGui::Button("Tug")) spawnCar(583);
        if (ImGui::Button("Walton")) spawnCar(478);
        if (ImGui::Button("Yosemite")) spawnCar(554);

        ImGui::Unindent(30.0f);
    }
    ImGui::Spacing();
    if (ImGui::CollapsingHeader("SUVs & Wagons")) {
        ImGui::Indent(30.0f);

        if (ImGui::Button("Huntley")) spawnCar(579);
        if (ImGui::Button("Landstalker")) spawnCar(400);
        if (ImGui::Button("Perennial")) spawnCar(404);
        if (ImGui::Button("Rancher")) spawnCar(489);
        if (ImGui::Button("Rancher Lure")) spawnCar(505);
        if (ImGui::Button("Regina")) spawnCar(479);
        if (ImGui::Button("Romero")) spawnCar(442);
        if (ImGui::Button("Solair")) spawnCar(458);

        ImGui::Unindent(30.0f);
    }
    ImGui::Spacing();
    if (ImGui::CollapsingHeader("Lowriders")) {
        ImGui::Indent(30.0f);

        if (ImGui::Button("Blade")) spawnCar(536);
        if (ImGui::Button("Broadway")) spawnCar(575);
        if (ImGui::Button("Remington")) spawnCar(534);
        if (ImGui::Button("Savanna")) spawnCar(567);
        if (ImGui::Button("Slamvan")) spawnCar(535);
        if (ImGui::Button("Tornado")) spawnCar(576);
        if (ImGui::Button("Voodoo")) spawnCar(412);

        ImGui::Unindent(30.0f);
    }
    ImGui::Spacing();
    if (ImGui::CollapsingHeader("Muscle cars")) {
        ImGui::Indent(30.0f);

        if (ImGui::Button("Buffalo")) spawnCar(402);
        if (ImGui::Button("Clover")) spawnCar(542);
        if (ImGui::Button("Phoenix")) spawnCar(603);
        if (ImGui::Button("Sabre")) spawnCar(475);

        ImGui::Unindent(30.0f);
    }
    ImGui::Spacing();
    if (ImGui::CollapsingHeader("Street racers")) {
        ImGui::Indent(30.0f);

        if (ImGui::Button("Banshee")) spawnCar(429);
        if (ImGui::Button("Bullet")) spawnCar(541);
        if (ImGui::Button("Cheetah")) spawnCar(415);
        if (ImGui::Button("Comet")) spawnCar(480);
        if (ImGui::Button("Elegy")) spawnCar(562);
        if (ImGui::Button("Flash")) spawnCar(565);
        if (ImGui::Button("Hotknife")) spawnCar(434);
        if (ImGui::Button("Hotring Racer")) spawnCar(494);
        if (ImGui::Button("Hotring Racer 2")) spawnCar(502);
        if (ImGui::Button("Hotring Racer 3")) spawnCar(503);
        if (ImGui::Button("Infernus")) spawnCar(411);
        if (ImGui::Button("Jester")) spawnCar(559);
        if (ImGui::Button("Stratum")) spawnCar(561);
        if (ImGui::Button("Sultan")) spawnCar(560);
        if (ImGui::Button("Super GT")) spawnCar(506);
        if (ImGui::Button("Turismo")) spawnCar(451);
        if (ImGui::Button("Uranus")) spawnCar(558);
        if (ImGui::Button("Windsor")) spawnCar(555);
        if (ImGui::Button("ZR-350")) spawnCar(477);

        ImGui::Unindent(30.0f);
    }
    ImGui::Spacing();
    if (ImGui::CollapsingHeader("Recreational")) {
        ImGui::Indent(30.0f);

        if (ImGui::Button("Bandito")) spawnCar(568);
        if (ImGui::Button("BF Injection")) spawnCar(424);
        if (ImGui::Button("Bloodring Banger")) spawnCar(504);
        if (ImGui::Button("Caddy")) spawnCar(457);
        if (ImGui::Button("Camper")) spawnCar(483);
        if (ImGui::Button("Journey")) spawnCar(508);
        if (ImGui::Button("Kart")) spawnCar(571);
        if (ImGui::Button("Mesa")) spawnCar(500);
        if (ImGui::Button("Monster")) spawnCar(444);
        if (ImGui::Button("Monster 2")) spawnCar(556);
        if (ImGui::Button("Monster 3")) spawnCar(557);
        if (ImGui::Button("Quadbike")) spawnCar(471);
        if (ImGui::Button("Sandking")) spawnCar(495);
        if (ImGui::Button("Vortex")) spawnCar(539);

        ImGui::Unindent(30.0f);
    }
    ImGui::Spacing();
}
void player() {
    ImGui::Indent(20.f);

    static bool goodMod = false;
    static bool flyhack_ = false;
    static bool superSpeed = false;
    if (ImGui::Checkbox("Infinite Health", &goodMod)) {
        *(StaticOffsets::PlayerStat::healthAddrs) = 1000.0f;
        goodMod ? healthHook::ON() : healthHook::OFF();
    }
    if (ImGui::Checkbox("Fly Hack (A : forward / alt : up / ctrl : down)", &flyhack_)) {
        flyhack_ ? flyToogle::ON() : flyToogle::OFF();
    }
    if (ImGui::Checkbox("Super Speed", &superSpeed)) {
        superSpeed ? speedPlayerFuncToogle::ON() : speedPlayerFuncToogle::OFF();
    }
    ImGui::SliderFloat("Speed", &speedPlayer, 1.0f, 10.0f);
    speedPlayer = speedPlayer;

    //---------------
    static bool superJump = false;
    if (ImGui::Checkbox("Super Jump", &superJump)) {
        superJump ? CheatCode::superJumpToogle::ON() : CheatCode::superJumpToogle::OFF();
    }
    //---------------
    static bool noCoop = false;
    if (ImGui::Checkbox("No Coops", &noCoop)) {
        (noCoop) ? CheatCode::noCopsToogle::ON() : CheatCode::noCopsToogle::OFF();
    }
    //---------------
    static bool infAmmo = false;
    if (ImGui::Checkbox("Infinite Ammo", &infAmmo)) {
        (infAmmo) ? CheatCode::noReloadToogle::ON() : CheatCode::noReloadToogle::OFF();
    }
    //---------------
    static bool infiniteRun = false;
    if (ImGui::Checkbox("Infinite Sprint", &infiniteRun)) {
        (infiniteRun) ? *(BYTE*)0xB7CEE4 = 1 : *(BYTE*)0xB7CEE4 = 0;
    }
    //---------------
    static bool fireProof = false;
    if (ImGui::Checkbox("Fireproof", &fireProof)) {
        (fireProof) ? *(BYTE*)0xB7CEE6 = 1 : *(BYTE*)0xB7CEE6 = 0;
    }
    if (ImGui::CollapsingHeader("Stat")) {
        //------ STAT 
        ImGui::Indent(20.f);
        static int moneyValue = *(int*)0xB7CE50;
        static int* moneyAddress = (int*)0xB7CE50;
        if (ImGui::SliderInt("Money", &moneyValue, 0, 10000000)) {
            *moneyAddress = moneyValue;
        }
        static float muscle = (float)*StaticOffsets::PlayerStat::muscleAddrs;
        static float fat = (float)*StaticOffsets::PlayerStat::fatAddrs;
        static float respect = (float)*StaticOffsets::PlayerStat::respectAddrs;
        static float stamina = (float)*StaticOffsets::PlayerStat::respectAddrs;
        static int energy = *(int*)0xB790B4;
        static int lungCapacity = *(int*)0xB791A4;
        static int driving = *(int*)0xB790A0;
        static int biking = *(int*)0xB7919C;
        static int flying = *(int*)0xB791B4;
        static int cycling = *(int*)0xB791B8;
        ImGui::SliderInt("Energy", &energy, 0, 1000);
        *(int*)0xB790B4 = energy;
        ImGui::SliderInt("Lung Capacity", &lungCapacity, 0, 1000);
        *(int*)0xB791A4 = lungCapacity;
        ImGui::SliderInt("Driving", &driving, 0, 1000);
        *(int*)0xB790A0 = driving;
        ImGui::SliderInt("Biking", &biking, 0, 1000);
        *(int*)0xB7919C = biking;
        ImGui::SliderInt("Flying", &flying, 0, 1000);
        *(int*)0xB791B4 = flying;
        ImGui::SliderInt("Cycling", &cycling, 0, 1000);
        *(int*)0xB791B8 = cycling;

        ImGui::SliderFloat("Muscle", &muscle, 0.0f, 1000.0f);
        *StaticOffsets::PlayerStat::muscleAddrs = muscle;
        ImGui::SliderFloat("fat", &fat, 0.0f, 1000.0f);
        *StaticOffsets::PlayerStat::fatAddrs = fat;
        ImGui::SliderFloat("Respect", &respect, 0.0f, 1000.0f);
        *StaticOffsets::PlayerStat::respectAddrs = respect;
        ImGui::SliderFloat("Stamina", &stamina, 0.0f, 1000.0f);
        *StaticOffsets::PlayerStat::staminaAddrs = stamina;
        //-- Gun stat
        if (ImGui::Button("Max Gun Stat")) {
            for (int i = 0; i < StaticOffsets::GunStat::All.size(); i++) {
                *(StaticOffsets::GunStat::All.at(i)) = 1000.0f;
            }
        }
        ImGui::Unindent(20.f);
    }
    ImGui::Unindent(20.f);
}
void world()
{
    ImGui::Indent(20.f);

    static int meteo = (int)*StaticOffsets::Time::meteo;
    static int hour = (int)*StaticOffsets::Time::hour;
    static int minute = (int)*StaticOffsets::Time::minute;
    static int* timerMissionAddress = (int*)0xA519D8;
    static int timerMission = 9999999;
    if (ImGui::SliderInt("Mission Timer", &timerMission, 0, 9999999))
        *timerMissionAddress = timerMission;
    if (ImGui::SliderInt("Weather Type", &meteo, 0, 19))
        *StaticOffsets::Time::meteo = (BYTE)meteo;
    //------------------
    if (ImGui::SliderInt("Hours", &hour, 0, 23))
        *StaticOffsets::Time::hour = (BYTE)hour;
    //-------------------
    if (ImGui::SliderInt("Minute", &minute, 0, 59))
        *StaticOffsets::Time::minute = (BYTE)minute;
    ImGui::Unindent(20.f);
}
