#include "AnimationManager.h"

#include "SFML/Graphics/RenderTarget.hpp"

void AnimationManager::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(*currentAnimation, states);
}

AnimationManager::AnimationManager(const TextureHolder& textures, UnitData& unitData)
: currentAnimation()
, currentAnimationType()
, currentDirectionType()
, animations() {
    for (auto const& animationData : unitData.animationData) {
        for (auto const& firstFramePosition : unitData.firstFramePosition[animationData.first]) {
            animations[animationData.first][firstFramePosition.first] =
                    std::make_shared<Animation>(textures.get(animationData.second.textureId),
                                                sf::IntRect(firstFramePosition.second, animationData.second.frameSize),
                                                animationData.second.numFrames, animationData.second.frameDuration, animationData.second.repeat);
        }
    }

    // set first animation
    setAnimation(animations.begin()->first, animations.begin()->second.begin()->first);
}

void AnimationManager::addAnimation(const TextureHolder& textures, UnitData& unitData, AnimationType animationType,
                                    DirectionType directionType) {
#define ANIMATION_DATA unitData.animationData[animationType]
#define FIRST_FRAME_POSITION unitData.firstFramePosition[animationType][directionType]
    animations[animationType][directionType] =
    std::make_shared<Animation>(textures.get(ANIMATION_DATA.textureId),
                                sf::IntRect(FIRST_FRAME_POSITION, ANIMATION_DATA.frameSize),
                                ANIMATION_DATA.numFrames, ANIMATION_DATA.frameDuration, ANIMATION_DATA.repeat);
}

void AnimationManager::setAnimation(AnimationType animationType, DirectionType directionType) {
    currentAnimation = animations[animationType][directionType];
    currentAnimationType = animationType;
    currentDirectionType = directionType;
}

void AnimationManager::update(sf::Time dt) {
    currentAnimation->update(dt);
}

AnimationType AnimationManager::getCurrentAnimationType() const {
    return currentAnimationType;
}

DirectionType AnimationManager::getCurrentDirectionType() const {
    return currentDirectionType;
}
