#pragma once
#include "Windows.h"
#include "unordered_map"
#include "math.h"
#include <d3d11.h>
#include <DirectXMath.h>
using namespace DirectX;

enum class BONEINDEX : std::size_t
{
    Pelvis = 0,
    Spine_1 = 2,
    Spine_2 = 3,
    Spine_3 = 4,
    Neck_0 = 5,
    Head = 6,
    Arm_Upper_L = 8,
    Arm_Lower_L = 9,
    Hand_L = 10,
    Arm_Upper_R = 13,
    Arm_Lower_R = 14,
    Hand_R = 15,
    Leg_Upper_L = 22,
    Leg_Lower_L = 23,
    Ankle_L = 24,
    Leg_Upper_R = 25,
    Leg_Lower_R = 26,
    Ankle_R = 27,
};


struct BonePosition
{
    math::vector3 Location;
    math::vector2 ScreenPosition;
    bool WorldVisible;
    bool RayTraceVisible;
};
struct BoneMatrix_t 
{
    XMFLOAT4X4 mat;
};

inline XMVECTOR XM_CALLCONV
ToXM(const math::vector3& v)
{
    return XMLoadFloat3(reinterpret_cast<const XMFLOAT3*>(&v));
}
struct CBone
{
    std::vector<BonePosition> BonePositions;
};


struct CBoneData
{
    math::vector3 Location;
    float Scale;
    char Padding[0x16];
};

namespace BoneJointList
{
    inline std::list<std::size_t> Trunk = { (std::size_t)BONEINDEX::Pelvis, (std::size_t)BONEINDEX::Spine_1, (std::size_t)BONEINDEX::Spine_2, (std::size_t)BONEINDEX::Spine_3, (std::size_t)BONEINDEX::Neck_0, (std::size_t)BONEINDEX::Head };
    inline std::list<std::size_t> LeftArm = { (std::size_t)BONEINDEX::Spine_3, (std::size_t)BONEINDEX::Arm_Upper_L, (std::size_t)BONEINDEX::Arm_Lower_L, (std::size_t)BONEINDEX::Hand_L };
    inline std::list<std::size_t> RightArm = { (std::size_t)BONEINDEX::Spine_3, (std::size_t)BONEINDEX::Arm_Upper_R, (std::size_t)BONEINDEX::Arm_Lower_R, (std::size_t)BONEINDEX::Hand_R };
    inline std::list<std::size_t> LeftLeg = { (std::size_t)BONEINDEX::Pelvis, (std::size_t)BONEINDEX::Leg_Upper_L, (std::size_t)BONEINDEX::Leg_Lower_L, (std::size_t)BONEINDEX::Ankle_L };
    inline std::list<std::size_t> RightLeg = { (std::size_t)BONEINDEX::Pelvis, (std::size_t)BONEINDEX::Leg_Upper_R, (std::size_t)BONEINDEX::Leg_Lower_R, (std::size_t)BONEINDEX::Ankle_R };

    inline std::vector<std::list<std::size_t>> List = { Trunk, LeftArm, RightArm, LeftLeg, RightLeg };
}