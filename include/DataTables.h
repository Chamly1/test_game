#ifndef TEST_GAME_DATATABLES_H
#define TEST_GAME_DATATABLES_H

#include "Animation.h"
#include "SceneNodes/Unit.h"
#include "ResourceHolders/TextureHolder.h"

#include <unordered_map>
#include <memory>

struct AnimationData {
    sf::Vector2i frameSize;
    int numFrames;
    sf::Time frameDuration;
    bool repeat;
};

struct AnimationTextureData {
    TextureIdentifier textureId;
    sf::Vector2i firstFramePosition;
};

struct UnitData {
    float baseSpeed;
    std::unordered_map<AnimationType, AnimationData> animationData;
    std::unordered_map<AnimationType, std::unordered_map<DirectionType, AnimationTextureData>> animationTextureData;
};

Animation createAnimation(const TextureHolder& textures, UnitData& unitData, AnimationType animationType,
                          DirectionType directionType);

std::unordered_map<UnitType, UnitData> initUnitData();

#endif //TEST_GAME_DATATABLES_H
