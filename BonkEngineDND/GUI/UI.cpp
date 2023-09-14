#include "pch.h"

void RenderMainUI()
{
	ImGui::Begin(Xors("Flashlight")); {
		ImGui::Text(Xors("Enemy ESP"));
		ImGui::Separator();
		ImGui::Checkbox(Xors("Enable ESP"), &bEnableESP);
		ImGui::Checkbox(Xors("Names"), &bEnemyNames);
		ImGui::Checkbox(Xors("Health"), &bEnemyHealth);
		ImGui::Checkbox(Xors("Class"), &bEnemyClass);
		ImGui::Checkbox(Xors("Weapon"), &bEnemyWeapon);
		ImGui::Checkbox(Xors("Distance"), &bEnemyDistance);
		ImGui::Checkbox(Xors("Snaplines"), &bEnemySnaplines);
		ImGui::Checkbox(Xors("Skeleton"), &bEnemySkeleton);
		ImGui::Checkbox(Xors("View Angles"), &bEnemyViewAngle);
		ImGui::Checkbox(Xors("Boxs"), &bEnemyBoxs);
		ImGui::Combo("Box Type", &iSelectedEnemyBox, { Xors("None"), Xors("2D") , Xors("2D Filled") , Xors("Corners"), Xors("3D") });
		ImGui::Text(Xors("Monsters"));
		ImGui::Separator();
		ImGui::Checkbox(Xors("Enable Monsters"), &bMonsters);
		ImGui::Checkbox(Xors("Monster Health"), &bMonsterHealth);
		ImGui::Checkbox(Xors("Monster Distance"), &bMonsterDistance);
		ImGui::Text(Xors("Items"));
		ImGui::Separator();
		ImGui::Checkbox(Xors("Items"), &bRenderItems);
		ImGui::Text(Xors("Traps"));
		ImGui::Separator();
		ImGui::Checkbox(Xors("Traps"), &bAllTraps);
		ImGui::Text(Xors("Alter"));
		ImGui::Separator();
		ImGui::Checkbox(Xors("Alter"), &bAlter);
		ImGui::Text(Xors("Portals"));
		ImGui::Separator();
		ImGui::Checkbox(Xors("Floor Portal"), &bFloorPortal);
		ImGui::Text(Xors("Radar"));
		ImGui::Separator();
		ImGui::Checkbox(Xors("Enable Radar"), &bRadar);
		ImGui::SliderFloat(Xors("Radar X"), &RadarX, 0.f, 1200.f);
		ImGui::SliderFloat(Xors("Radar Y"), &RadarY, 0.f, 1200.f);
		ImGui::Text(Xors("Lobby Info"));
		ImGui::Separator();
		if (ImGui::Checkbox(Xors("Lobby Info"), &bPlayerStatList))
		{
			RenderLobbyList();
		}
		ImGui::Text(Xors("Exploits"));
		ImGui::Separator();
		ImGui::Checkbox(Xors("Free-Cam"), &bFreeCam);
		ImGui::BeginDisabled();
		if (ImGui::Checkbox(Xors("Fullbright"), &bFullbright))
		{
			ULocalPlayer::Singleton()->ViewportClient->ViewModeIndex = 1;
		}
		ImGui::EndDisabled();
		ImGui::SliderFloat(Xors("FOV"), &fFOV, 0.f, 175.f);
		ImGui::Text(Xors("Aimbot"));
		ImGui::Separator();
		ImGui::Checkbox(Xors("Enable Aimbot"), &bAimbot);
		ImGui::Checkbox(Xors("Show FOV"), &bShowFOV);
		ImGui::SliderFloat(Xors("FOV Circle"), &sFOVSize, 0.f, 1200.f);
		ImGui::Checkbox(Xors("Target Line"), &bDrawTargetLine);
		ImGui::Checkbox(Xors("Target Name"), &bDrawTargetName);
		ImGui::Checkbox(Xors("Smoothing"), &bAimSmoothness);
		ImGui::SliderFloat(Xors("Smoothing"), &sAimSmoothness, 0.f, 100.f);
		ImGui::Checkbox(Xors("Random Smoothing"), &bAimSmoothRandom);
		ImGui::Combo(Xors("Aim Bone"), &iAimBone, { Xors("None"), Xors("Head"), Xors("Neck"), Xors("Torso"), Xors("Left Hand"), Xors("Right Hand"), Xors("Pelvis"), Xors("Left Foot"), Xors("Right Foot") });
		ImGui::Combo(Xors("Aim Type"), &iAimType, { Xors("None"), Xors("FOV"), Xors("FOV-Visible"), Xors("Visible") });
	}
}

void RenderStyle()
{

}