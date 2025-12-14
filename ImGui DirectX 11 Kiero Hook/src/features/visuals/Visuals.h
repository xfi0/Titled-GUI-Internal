#pragma once
#include "../../../imgui/imgui.h";
#include "../../SDK/Offsets.h";
#include "../../SDK/math.h";
#include "../../SDK/GameState.h"
#include <stdio.h>
#include <list>
#include "../../SDK/DataTypes/StrongHandle.h"
#include "../../SDK/Material.h"

namespace Visuals {
	namespace BoxESP {
		void BoxESP();
		static bool boxESPEnabled = false;
		static ImColor boxColor = ImColor(255, 0, 0);
		static float rounding = 0.0f;
	}
	namespace BoneESP
	{
		void BoneESP();
	}
	namespace Chams
	{
		CStrongHandle<SDK::CMaterial2> CreateMaterial(const char* szMaterialName, const char szVmatBuffer[]);
		void Chams();
	}
}

