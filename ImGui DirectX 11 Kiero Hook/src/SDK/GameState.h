#pragma once
#include <Windows.h>
#include <libloaderapi.h>
#include <cstddef>
#include <list>
#include "Entity.h"
#include "Offsets.h"

namespace GameState {
	extern uintptr_t client;
	void updateEntities();
	extern std::list<SDK::Entity> entities;
}
