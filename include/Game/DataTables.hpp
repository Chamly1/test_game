#ifndef TEST_GAME_DATATABLES_HPP
#define TEST_GAME_DATATABLES_HPP

#include "GameEngine/Animation.hpp"
#include "Game/SceneNodes/UnitType.hpp"
#include "GameEngine/ResourceHolders/TextureHolder.hpp"
#include "GameEngine/DirectionType.hpp"

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

enum class AnimationType {
    Idle,
    Walk,
    Attack,
    Damage
};

struct UnitData {
    float baseSpeed;

    sf::Time attackDuration;
    float attackCollisionBoxShift; // shit from Unit's center
    sf::Vector2f attackCollisionBoxSize;

    int maxHP;
    sf::Vector2f hitBoxSize;
    sf::Time afterDamageInvulnerabilityTime;
    sf::Time afterDamageUncontrolTime;

    sf::Vector2f collisionBoxSize;
    sf::Vector2f collisionBoxOrigin;
    sf::Vector2f animationsScaleFactor;

    // animations data
    AnimationType defaultAnimationType;
    DirectionType defaultAnimationDirectionType;
    std::unordered_map<AnimationType, AnimationData> animationData;
    std::unordered_map<AnimationType, std::unordered_map<DirectionType, sf::Vector2i>> firstFramePosition;
};

std::unordered_map<UnitType, UnitData> initUnitData();

#endif //TEST_GAME_DATATABLES_HPP
