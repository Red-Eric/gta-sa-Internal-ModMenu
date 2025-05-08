#include "frontEnd.h"
#include <Windows.h>
#include <imgui.h>
#include <imgui_impl_dx9.h>
#include <imgui_impl_win32.h>
#include "../menuToggle.h"
#include "../hook/health.h"
#include "../NameSpace/cheat.h"
#include "../NameSpace/stat.h"
#include "../hook/threadEx.h"

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


namespace frontEnd {
    static IDirect3DDevice9* gDevice = nullptr;
    static WNDPROC oWndProc = nullptr;

    LRESULT CALLBACK hkWndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
        if (showMenu && ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
            return true;
        return CallWindowProc(oWndProc, hWnd, msg, wParam, lParam);
    }

    HRESULT Render(IDirect3DDevice9* pDevice, HRESULT(__stdcall* originalEndScene)(IDirect3DDevice9*)) {
        if (!gDevice) {
            gDevice = pDevice;
            HWND hWnd = GetForegroundWindow();
            ImGui::CreateContext();
            ImGui_ImplWin32_Init(hWnd);
            ImGui_ImplDX9_Init(pDevice);
            oWndProc = (WNDPROC)SetWindowLongPtr(hWnd, GWLP_WNDPROC, (LONG_PTR)hkWndProc);
        }

        ImGui_ImplDX9_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        ImGui::GetIO().MouseDrawCursor = showMenu;

        if (showMenu) {
            ImGui::SetNextWindowSize(ImVec2(500, 450), ImGuiCond_Always);

            ImGui::Begin("Menu (F2/F12)");
            // Player Section
            if (ImGui::CollapsingHeader("Player")) {
                ImGui::Indent(20.f);
                static bool goodMod = false;
                if (ImGui::Checkbox("Infinite Health", &goodMod)) {
                    goodMod ? healthHook::ON() : healthHook::OFF();
                }

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
                //------ STAT 
                static float muscle = (float)*StaticOffsets::PlayerStat::muscleAddrs;
                static float fat = (float)*StaticOffsets::PlayerStat::fatAddrs;
                static float respect = (float)*StaticOffsets::PlayerStat::respectAddrs;
                static float stamina = (float)*StaticOffsets::PlayerStat::respectAddrs;
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
            ImGui::Spacing();
            // Time h w
            if (ImGui::CollapsingHeader("World")) {
                ImGui::Indent(20.f);

                static int meteo = (int)*StaticOffsets::Time::meteo;
                static int hour = (int)*StaticOffsets::Time::hour;
                static int minute = (int)*StaticOffsets::Time::minute;
                static int* timerMissionAddress = (int*)0xA519D8;
                static int timerMission = 9999999;
                if (ImGui::SliderInt("Mission Timer", &timerMission, 0, 99999999))
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
            ImGui::Spacing();

            if (ImGui::CollapsingHeader("Vehicle")) {
                ImGui::Indent(20.0f);
                if (ImGui::CollapsingHeader("AirPlane")) {
                    static int planeIDs[] = { 577, 511, 512, 593, 520, 553, 476, 519, 460, 513 };
                    static int indexPlane = 0;
                    if (ImGui::SliderInt("PlaneID", &indexPlane, 0, sizeof(planeIDs) / sizeof(planeIDs[0]) - 1))
                        spawnCar(planeIDs[indexPlane]);

                }
                if (ImGui::CollapsingHeader("Helicopter")) {
                    static int heliIDs[] = { 548, 425, 417, 487, 488, 497, 563, 447, 469 };
                    static int indexHeli = 0;
                    if (ImGui::SliderInt("HeliID", &indexHeli, 0, sizeof(heliIDs) / sizeof(heliIDs[0]) - 1))
                        spawnCar(heliIDs[indexHeli]);

                }
                if (ImGui::CollapsingHeader("Boats")) {
                    static int boatIDs[] = { 472, 473, 493, 595, 484, 430, 453, 452, 446, 454 };
                    static int indexBoat = 0;
                    if (ImGui::SliderInt("BoatID", &indexBoat, 0, sizeof(boatIDs) / sizeof(boatIDs[0]) - 1))
                        spawnCar(boatIDs[indexBoat]);

                }
                if (ImGui::CollapsingHeader("Bikes")) {
                    static int bikeIDs[] = { 581, 509, 481, 462, 521, 463, 510, 522, 461, 448, 468, 586 };
                    static int indexBike = 0;
                    if (ImGui::SliderInt("BikeID", &indexBike, 0, sizeof(bikeIDs) / sizeof(bikeIDs[0]) - 1))
                        spawnCar(bikeIDs[indexBike]);
                }
                if (ImGui::CollapsingHeader("Car")) {
                    static int carIDs[] = { 602, 496, 401, 518, 527, 589, 419, 587, 533, 526, 474, 545, 517, 410, 600, 436, 439, 549, 491, 445, 604, 507, 585, 466, 492, 546, 551, 516, 467, 426, 547, 405, 580, 409, 550, 566, 540, 421, 529, 416, 433, 427, 490, 528, 407, 544, 523, 470, 596, 598, 599, 597, 432, 601, 428, 499, 609, 498, 524, 532, 578, 486, 406, 573, 455, 588, 403, 423, 414, 443, 515, 514, 531, 456, 459, 422, 482, 605, 530, 418, 572, 582, 413, 440, 543, 583, 478, 554, 579, 400, 536, 575, 534, 567, 535, 576, 412, 404, 489, 505, 479, 442, 458, 402, 542, 603, 475, 429, 541, 415, 480, 562, 565, 434, 494, 502, 503, 411, 559, 561, 560, 506, 451, 558, 555, 477 };
                    static int indexCar = 0;
                    if (ImGui::SliderInt("CarID", &indexCar, 0, sizeof(carIDs) / sizeof(carIDs[0]) - 1))
                        spawnCar(carIDs[indexCar]);

                }
                ImGui::Unindent(20.f);
            }
            ImGui::Spacing();
            ImGui::End();
        }

        ImGui::Render();
        ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

        return originalEndScene(pDevice);
    }
}
