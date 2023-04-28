#ifndef TEST_GAME_DATATABLES_H
#define TEST_GAME_DATATABLES_H

#include "GameEngine/Animation.h"
#include "SceneNodes/UnitType.h"
#include "GameEngine/ResourceHolders/TextureHolder.h"

#include <unordered_map>
#include <memory>

struct AnimationData {
    TextureIdentifier textureId;
    sf::Vector2i frameSize;
    sf::Vector2f frameOrigin;
    int numFrames;
    sf::Time frameDuration;
    bool repeat;
};

enum class DirectionType {
    BottomRight,
    BottomLeft,
    TopRight,
    TopLeft,
};

enum class AnimationType {
    Idle,
    Walk
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
