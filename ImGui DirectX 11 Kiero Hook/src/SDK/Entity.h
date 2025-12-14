#pragma once
#include "math.h"
#include "Bone.h"

namespace SDK {
    struct controller {
        uintptr_t address = 0;
    };
    struct pawn {
        CBone BoneData;
        math::vector3 origin{};
        int team = 0;
        int health = 0;
        uintptr_t address = 0;
        uintptr_t gameSceneNode = 0;
        bool isDormant;
        bool IsValid() const {
			return true;
		}
    };
    struct Entity {
        controller controller{};
        pawn pawn{};
    };
}