#include "Visuals.h"
#include "../../SDK/Hooks.h"
//#include "../../SDK/"
void Visuals::BoxESP::BoxESP()
{
	float(*ViewMatrix)[4][4] = (float(*)[4][4])(GameState::client + Offsets::client_dll::dwViewMatrix);

	if (!ViewMatrix)
		return;

	for (SDK::Entity& ent : GameState::entities) {
		if (!ent.pawn.IsValid())
			continue;

		math::vector3 headPos = { ent.pawn.origin.x + 0.0f,ent.pawn.origin.y + 0.0f, ent.pawn.origin.z + 67.0f };

		math::vector2 footPos2D, headPos2D;
		if (!ent.pawn.origin.WorldToScreen(footPos2D, ViewMatrix) || !headPos.WorldToScreen(headPos2D, ViewMatrix))
			continue;

		float heightOffset = 1.43f;
		float widthOffset = 1.6f;
		float height = (footPos2D.y - headPos2D.y) * heightOffset;
		float width = height / widthOffset;
		float x = footPos2D.x - width / 2;
		float y = headPos2D.y;

		ImGui::GetBackgroundDrawList()->AddRect({ x, y }, { x + width, y + height }, boxColor, rounding);
	}
}
void Visuals::BoneESP::BoneESP()
{
    float(*ViewMatrix)[4][4] = (float(*)[4][4])(GameState::client + Offsets::client_dll::dwViewMatrix);
    if (!ViewMatrix) return;
	
 
}
CStrongHandle<SDK::CMaterial2>  Visuals::Chams::CreateMaterial(const char* szMaterialName, const char szVmatBuffer[])
{
	return CStrongHandle<SDK::CMaterial2>();
}
void Visuals::Chams::Chams()
{
}
