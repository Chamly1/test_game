#include "Game/DataTables.hpp"
#include "Game/ResourceHolders/TextureIdentifier.hpp"

std::unordered_map<UnitType, UnitData> initUnitData() {
    std::unordered_map<UnitType, UnitData> data;

    const float scaleFactor = 5.f;

    //****************************** Human ******************************

    data[UnitType::Human].baseSpeed = 400.f;
    data[UnitType::Human].animationsScaleFactor = sf::Vector2f(scaleFactor, scaleFactor);
    data[UnitType::Human].collisionBoxSize = sf::Vector2f(6.f * scaleFactor, 7.f * scaleFactor);
    data[UnitType::Human].collisionBoxOrigin = data[UnitType::Human].collisionBoxSize / 2.f;

    data[UnitType::Human].animationData[AnimationType::Idle].textureId = TextureIdentifier::HumanBaseIdleAnimation;
    data[UnitType::Human].animationData[AnimationType::Idle].frameSize = sf::Vector2i(32, 32);
    data[UnitType::Human].animationData[AnimationType::Idle].frameOrigin = sf::Vector2f(32.f, 32.f) / 2.f;
    data[UnitType::Human].animationData[AnimationType::Idle].numFrames = 16;
    data[UnitType::Human].animationData[AnimationType::Idle].frameDuration = sf::milliseconds(400);
    data[UnitType::Human].animationData[AnimationType::Idle].repeat = true;
    data[UnitType::Human].firstFramePosition[AnimationType::Idle][DirectionType::BottomRight] = sf::Vector2i(0, 0);
    data[UnitType::Human].firstFramePosition[AnimationType::Idle][DirectionType::BottomLeft] = sf::Vector2i(0, 32);
    data[UnitType::Human].firstFramePosition[AnimationType::Idle][DirectionType::TopRight] = sf::Vector2i(0, 64);
    data[UnitType::Human].firstFramePosition[AnimationType::Idle][DirectionType::TopLeft] = sf::Vector2i(0, 96);

    data[UnitType::Human].animationData[AnimationType::Walk].textureId = TextureIdentifier::HumanBaseWalkAnimation;
    data[UnitType::Human].animationData[AnimationType::Walk].frameSize = sf::Vector2i(32, 32);
    data[UnitType::Human].animationData[AnimationType::Walk].frameOrigin = sf::Vector2f(32.f, 32.f) / 2.f;
    data[UnitType::Human].animationData[AnimationType::Walk].numFrames = 4;
    data[UnitType::Human].animationData[AnimationType::Walk].frameDuration = sf::milliseconds(150);
    data[UnitType::Human].animationData[AnimationType::Walk].repeat = true;
    data[UnitType::Human].firstFramePosition[AnimationType::Walk][DirectionType::BottomRight] = sf::Vector2i(0, 0);
    data[UnitType::Human].firstFramePosition[AnimationType::Walk][DirectionType::BottomLeft] = sf::Vector2i(0, 32);
    data[UnitType::Human].firstFramePosition[AnimationType::Walk][DirectionType::TopRight] = sf::Vector2i(0, 64);
    data[UnitType::Human].firstFramePosition[AnimationType::Walk][DirectionType::TopLeft] = sf::Vector2i(0, 96);

    data[UnitType::Human].animationData[AnimationType::Attack].textureId = TextureIdentifier::HumanBaseAttackAnimation;
    data[UnitType::Human].animationData[AnimationType::Attack].frameSize = sf::Vector2i(32, 32);
    data[UnitType::Human].animationData[AnimationType::Attack].frameOrigin = sf::Vector2f(32.f, 32.f) / 2.f;
    data[UnitType::Human].animationData[AnimationType::Attack].numFrames = 4;
    data[UnitType::Human].animationData[AnimationType::Attack].frameDuration = sf::milliseconds(150); // TODO
    data[UnitType::Human].animationData[AnimationType::Attack].repeat = false;
    data[UnitType::Human].firstFramePosition[AnimationType::Attack][DirectionType::BottomRight] = sf::Vector2i(0, 0);
    data[UnitType::Human].firstFramePosition[AnimationType::Attack][DirectionType::BottomLeft] = sf::Vector2i(0, 32);
    data[UnitType::Human].firstFramePosition[AnimationType::Attack][DirectionType::TopRight] = sf::Vector2i(0, 64);
    data[UnitType::Human].firstFramePosition[AnimationType::Attack][DirectionType::TopLeft] = sf::Vector2i(0, 96);

    //****************************** Zombie ******************************

    data[UnitType::Zombie].baseSpeed = 200.f;
    data[UnitType::Zombie].animationsScaleFactor = sf::Vector2f(scaleFactor, scaleFactor);
    data[UnitType::Zombie].collisionBoxSize = sf::Vector2f(6.f * scaleFactor, 7.f * scaleFactor);
    data[UnitType::Zombie].collisionBoxOrigin = data[UnitType::Zombie].collisionBoxSize / 2.f;

    data[UnitType::Zombie].animationData[AnimationType::Idle].textureId = TextureIdentifier::ZombieIdleAnimation;
    data[UnitType::Zombie].animationData[AnimationType::Idle].frameSize = sf::Vector2i(32, 32);
    data[UnitType::Zombie].animationData[AnimationType::Idle].frameOrigin = sf::Vector2f(32.f, 32.f) / 2.f;
    data[UnitType::Zombie].animationData[AnimationType::Idle].numFrames = 19;
    data[UnitType::Zombie].animationData[AnimationType::Idle].frameDuration = sf::milliseconds(400);
    data[UnitType::Zombie].animationData[AnimationType::Idle].repeat = true;
    data[UnitType::Zombie].firstFramePosition[AnimationType::Idle][DirectionType::BottomRight] = sf::Vector2i(0, 0);
    data[UnitType::Zombie].firstFramePosition[AnimationType::Idle][DirectionType::BottomLeft] = sf::Vector2i(0, 32);
    data[UnitType::Zombie].firstFramePosition[AnimationType::Idle][DirectionType::TopRight] = sf::Vector2i(0, 64);
    data[UnitType::Zombie].firstFramePosition[AnimationType::Idle][DirectionType::TopLeft] = sf::Vector2i(0, 96);

    data[UnitType::Zombie].animationData[AnimationType::Walk].textureId = TextureIdentifier::ZombieWalkAnimation;
    data[UnitType::Zombie].animationData[AnimationType::Walk].frameSize = sf::Vector2i(32, 32);
    data[UnitType::Zombie].animationData[AnimationType::Walk].frameOrigin = sf::Vector2f(32.f, 32.f) / 2.f;
    data[UnitType::Zombie].animationData[AnimationType::Walk].numFrames = 4;
    data[UnitType::Zombie].animationData[AnimationType::Walk].frameDuration = sf::milliseconds(150);
    data[UnitType::Zombie].animationData[AnimationType::Walk].repeat = true;
    data[UnitType::Zombie].firstFramePosition[AnimationType::Walk][DirectionType::BottomRight] = sf::Vector2i(0, 0);
    data[UnitType::Zombie].firstFramePosition[AnimationType::Walk][DirectionType::BottomLeft] = sf::Vector2i(0, 32);
    data[UnitType::Zombie].firstFramePosition[AnimationType::Walk][DirectionType::TopRight] = sf::Vector2i(0, 64);
    data[UnitType::Zombie].firstFramePosition[AnimationType::Walk][DirectionType::TopLeft] = sf::Vector2i(0, 96);

    return data;
}
