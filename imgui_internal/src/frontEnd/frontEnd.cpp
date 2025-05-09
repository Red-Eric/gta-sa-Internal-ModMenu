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
#include "../hook/oneHitCar.h"

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
                static bool oneHitCarBool = false;
                if (ImGui::Checkbox("One Hit Car", &oneHitCarBool)) {
                    oneHitCarBool ? oneHitCarToogle::ON() : oneHitCarToogle::OFF();
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
                
                //------ STAT 
                static int moneyValue = 0;
                static int* moneyAddress = (int*)0xB7CE50;
                if (ImGui::SliderInt("Money", &moneyValue, 0, 10000000)) {
                    *moneyAddress = moneyValue;
                }
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
            if (ImGui::CollapsingHeader("Weapon")) {
                ImGui::Indent(20.f);
                if (ImGui::Button("Give WeaponSet1")) {
                    weaponN giveN = GetTestFuncFromAddress((void*)0x4385B0);
                    giveN();
                }
                ImGui::Spacing();
                if (ImGui::Button("Give WeaponSet2")) {
                    weaponN giveN = GetTestFuncFromAddress((void*)0x00438890);
                    giveN();
                }
                ImGui::Spacing();
                if (ImGui::Button("Give WeaponSet3")) {
                    weaponN giveN = GetTestFuncFromAddress((void*)0x00438B30);
                    giveN();
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
            ImGui::Spacing();

            if (ImGui::CollapsingHeader("Vehicle")) {
                ImGui::Indent(20.0f);
                if (ImGui::Button("Maverick"))
                    spawnCar(487);
                if (ImGui::Button("NRG-500"))
                    spawnCar(522);
                if (ImGui::Button("Turismo"))
                    spawnCar(451);
                ImGui::Unindent(20.0f);
            }
            ImGui::Spacing();
            ImGui::End();
        }

        ImGui::Render();
        ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

        return originalEndScene(pDevice);
    }
}
