#include "GameState.h";

uintptr_t GameState::client = (uintptr_t)GetModuleHandle("client.dll");
std::list<SDK::Entity> GameState::entities;
namespace GameState {
	void updateEntities()
	{
		if (!GameState::client)
			return;

		entities.clear();
		auto localPlayerPawn = *(uintptr_t*)(GameState::client + Offsets::client_dll::dwLocalPlayerPawn);

		if (!localPlayerPawn)
			return;

		int localPlayerTeam = *(int*)(localPlayerPawn + Offsets::C_BaseEntity::m_iTeamNum);
		if (!localPlayerTeam)
			return;

		auto entityList = *(uintptr_t*)(GameState::client + Offsets::client_dll::dwEntityList);
		if (!entityList)
			return;

		for (int i = 0; i < 64; i++) {
			auto listEntry1 = *(uintptr_t*)(entityList + (0x8 * (i & 0x7FFF) >> 9) + 0x10);
			if (!listEntry1)
				continue;

			auto playerController = *(uintptr_t*)(listEntry1 + 0x70 * (i & 0x1FF));
			if (!playerController)
				continue;

			auto playerPawn = *(uintptr_t*)(playerController + Offsets::CCSPlayerController::m_hPlayerPawn);
			if (!playerPawn)
				continue;

			auto listEntry2 = *(uintptr_t*)(entityList + 0x8 * ((playerPawn & 0x7FFF) >> 9) + 0x10);

			if (!listEntry2)
				continue;

			auto pCSPlayerPawn = *(uintptr_t*)(listEntry2 + 0x70 * (playerPawn & 0x1FF));
			if (!pCSPlayerPawn)
				continue;


			auto health = *(int*)(pCSPlayerPawn + Offsets::C_BaseEntity::m_iHealth);
			if (!health || health > 100)
				continue;

			int playerTeam = *(int*)(pCSPlayerPawn + Offsets::C_BaseEntity::m_iTeamNum);
			if (playerTeam == localPlayerTeam)
				continue;


			SDK::Entity ent{};
			ent.pawn.address = pCSPlayerPawn;
			ent.controller.address = playerController;
			ent.pawn.health = health;
			ent.pawn.team = playerTeam;
			ent.pawn.origin = *(math::vector3*)(ent.pawn.address + Offsets::C_BasePlayerPawn::m_vOldOrigin);
			ent.pawn.gameSceneNode = *(uintptr_t*)(ent.pawn.address + Offsets::C_BaseEntity::m_pGameSceneNode);
			//ent.pawn.isDormant = *(bool*)(ent.pawn.address + ent.pawn.gameSceneNode + Offsets::CGameSceneNode::m_bDormant);

			entities.push_back(ent);

		}
	}
}
