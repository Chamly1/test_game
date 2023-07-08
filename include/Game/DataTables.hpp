#ifndef TEST_GAME_DATATABLES_HPP
#define TEST_GAME_DATATABLES_HPP

#include "GameEngine/Animation.hpp"
#include "Game/SceneNodes/UnitType.hpp"
#include "GameEngine/ResourceHolders/TextureHolder.hpp"

#include <unordered_map>
#include <memory>

struct AnimationData {
    unsigned int textureId;
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
    Walk,
    Attack
};

struct UnitData {
    float baseSpeed;
    sf::Time attackDuration;
    sf::Vector2f collisionBoxSize;
    sf::Vector2f collisionBoxOrigin;
    sf::Vector2f animationsScaleFactor;

    AnimationType defaultAnimationType;
    DirectionType defaultAnimationDirectionType;
    std::unordered_map<AnimationType, AnimationData> animationData;
    std::unordered_map<AnimationType, std::unordered_map<DirectionType, sf::Vector2i>> firstFramePosition;
};

std::unordered_map<UnitType, UnitData> initUnitData();

#endif //TEST_GAME_DATATABLES_HPP
