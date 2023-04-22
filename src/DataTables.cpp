#include "DataTables.h"

Animation createAnimation(const TextureHolder& textures, UnitData& unitData, AnimationType animationType, DirectionType directionType) {
#define ANIMATION_DATA unitData.animationData[animationType]
#define ANIMATION_TEXTURE_DATA unitData.animationTextureData[animationType][directionType]

    return Animation(textures.get(ANIMATION_TEXTURE_DATA.textureId),
                     sf::IntRect(ANIMATION_TEXTURE_DATA.firstFramePosition, ANIMATION_DATA.frameSize),
                     ANIMATION_DATA.numFrames, ANIMATION_DATA.frameDuration, ANIMATION_DATA.repeat);
}

std::unordered_map<UnitType, UnitData> initUnitData() {
    std::unordered_map<UnitType, UnitData> data;

    data[UnitType::Human].baseSpeed = 75.f;

    data[UnitType::Human].animationData[AnimationType::Idle].frameSize = sf::Vector2i(32, 32);
    data[UnitType::Human].animationData[AnimationType::Idle].numFrames = 16;
    data[UnitType::Human].animationData[AnimationType::Idle].frameDuration = sf::milliseconds(400);
    data[UnitType::Human].animationData[AnimationType::Idle].repeat = true;
    data[UnitType::Human].animationTextureData[AnimationType::Idle][DirectionType::BottomRight].textureId = TextureIdentifier::HumanBaseIdleAnimation;
    data[UnitType::Human].animationTextureData[AnimationType::Idle][DirectionType::BottomRight].firstFramePosition = sf::Vector2i(0, 0);
    data[UnitType::Human].animationTextureData[AnimationType::Idle][DirectionType::BottomLeft].textureId = TextureIdentifier::HumanBaseIdleAnimation;
    data[UnitType::Human].animationTextureData[AnimationType::Idle][DirectionType::BottomLeft].firstFramePosition = sf::Vector2i(0, 32);
    data[UnitType::Human].animationTextureData[AnimationType::Idle][DirectionType::TopRight].textureId = TextureIdentifier::HumanBaseIdleAnimation;
    data[UnitType::Human].animationTextureData[AnimationType::Idle][DirectionType::TopRight].firstFramePosition = sf::Vector2i(0, 64);
    data[UnitType::Human].animationTextureData[AnimationType::Idle][DirectionType::TopLeft].textureId = TextureIdentifier::HumanBaseIdleAnimation;
    data[UnitType::Human].animationTextureData[AnimationType::Idle][DirectionType::TopLeft].firstFramePosition = sf::Vector2i(0, 96);

    data[UnitType::Human].animationData[AnimationType::Walk].frameSize = sf::Vector2i(32, 32);
    data[UnitType::Human].animationData[AnimationType::Walk].numFrames = 4;
    data[UnitType::Human].animationData[AnimationType::Walk].frameDuration = sf::milliseconds(150);
    data[UnitType::Human].animationData[AnimationType::Walk].repeat = true;
    data[UnitType::Human].animationTextureData[AnimationType::Walk][DirectionType::BottomRight].textureId = TextureIdentifier::HumanBaseWalkAnimation;
    data[UnitType::Human].animationTextureData[AnimationType::Walk][DirectionType::BottomRight].firstFramePosition = sf::Vector2i(0, 0);
    data[UnitType::Human].animationTextureData[AnimationType::Walk][DirectionType::BottomLeft].textureId = TextureIdentifier::HumanBaseWalkAnimation;
    data[UnitType::Human].animationTextureData[AnimationType::Walk][DirectionType::BottomLeft].firstFramePosition = sf::Vector2i(0, 32);
    data[UnitType::Human].animationTextureData[AnimationType::Walk][DirectionType::TopRight].textureId = TextureIdentifier::HumanBaseWalkAnimation;
    data[UnitType::Human].animationTextureData[AnimationType::Walk][DirectionType::TopRight].firstFramePosition = sf::Vector2i(0, 64);
    data[UnitType::Human].animationTextureData[AnimationType::Walk][DirectionType::TopLeft].textureId = TextureIdentifier::HumanBaseWalkAnimation;
    data[UnitType::Human].animationTextureData[AnimationType::Walk][DirectionType::TopLeft].firstFramePosition = sf::Vector2i(0, 96);

    return data;
}
