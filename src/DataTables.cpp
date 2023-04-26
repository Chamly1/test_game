#include "DataTables.h"

std::unordered_map<UnitType, UnitData> initUnitData() {
    std::unordered_map<UnitType, UnitData> data;

    const float scaleFactor = 4.f;

    data[UnitType::Human].baseSpeed = 300.f;
    data[UnitType::Human].animationsScaleFactor = sf::Vector2f(scaleFactor, scaleFactor);
    data[UnitType::Human].collisionBoxSize = sf::Vector2f(7.f * scaleFactor, 7.f * scaleFactor);

    data[UnitType::Human].animationData[AnimationType::Idle].textureId = TextureIdentifier::HumanBaseIdleAnimation;
    data[UnitType::Human].animationData[AnimationType::Idle].frameSize = sf::Vector2i(32, 32);
    data[UnitType::Human].animationData[AnimationType::Idle].numFrames = 16;
    data[UnitType::Human].animationData[AnimationType::Idle].frameDuration = sf::milliseconds(400);
    data[UnitType::Human].animationData[AnimationType::Idle].repeat = true;
    data[UnitType::Human].firstFramePosition[AnimationType::Idle][DirectionType::BottomRight] = sf::Vector2i(0, 0);
    data[UnitType::Human].firstFramePosition[AnimationType::Idle][DirectionType::BottomLeft] = sf::Vector2i(0, 32);
    data[UnitType::Human].firstFramePosition[AnimationType::Idle][DirectionType::TopRight] = sf::Vector2i(0, 64);
    data[UnitType::Human].firstFramePosition[AnimationType::Idle][DirectionType::TopLeft] = sf::Vector2i(0, 96);

    data[UnitType::Human].animationData[AnimationType::Walk].textureId = TextureIdentifier::HumanBaseWalkAnimation;
    data[UnitType::Human].animationData[AnimationType::Walk].frameSize = sf::Vector2i(32, 32);
    data[UnitType::Human].animationData[AnimationType::Walk].numFrames = 4;
    data[UnitType::Human].animationData[AnimationType::Walk].frameDuration = sf::milliseconds(150);
    data[UnitType::Human].animationData[AnimationType::Walk].repeat = true;
    data[UnitType::Human].firstFramePosition[AnimationType::Walk][DirectionType::BottomRight] = sf::Vector2i(0, 0);
    data[UnitType::Human].firstFramePosition[AnimationType::Walk][DirectionType::BottomLeft] = sf::Vector2i(0, 32);
    data[UnitType::Human].firstFramePosition[AnimationType::Walk][DirectionType::TopRight] = sf::Vector2i(0, 64);
    data[UnitType::Human].firstFramePosition[AnimationType::Walk][DirectionType::TopLeft] = sf::Vector2i(0, 96);

    return data;
}
