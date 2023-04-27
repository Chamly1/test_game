#ifndef TEST_GAME_DATATABLES_H
#define TEST_GAME_DATATABLES_H

#include "Animation.h"
#include "SceneNodes/UnitType.h"
#include "ResourceHolders/TextureHolder.h"

#include <unordered_map>
#include <memory>

struct AnimationData {
    TextureIdentifier textureId;
    sf::Vector2i frameSize;
    int numFrames;
    sf::Time frameDuration;
    bool repeat;
};

struct UnitData {
    float baseSpeed;
    sf::Vector2f collisionBoxSize;
    sf::Vector2f collisionBoxOrigin;
    sf::Vector2f animationsScaleFactor;
    std::unordered_map<AnimationType, AnimationData> animationData;
    std::unordered_map<AnimationType, std::unordered_map<DirectionType, sf::Vector2i>> firstFramePosition;
};

std::unordered_map<UnitType, UnitData> initUnitData();

#endif //TEST_GAME_DATATABLES_H
