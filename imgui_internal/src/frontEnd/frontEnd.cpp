#include "frontEnd.h"
#include <Windows.h>
#include <imgui.h>

#include "all.h"

void f_showMenu(bool isShowed) {
    if (isShowed) {
        ImGui::SetNextWindowSize(ImVec2(500, 450), ImGuiCond_Always);
        ImGui::Begin("Menu (F2/F12)");
        // Player Section
        if (ImGui::CollapsingHeader("Player")) {
            player();
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
            world();
        }
        ImGui::Spacing();
        if (ImGui::CollapsingHeader("Vehicle")) {
            ImGui::Indent(20.0f);
            vehicles();
            ImGui::Unindent(20.0f);
        }

        ImGui::Spacing();
        ImGui::End();
    }
}