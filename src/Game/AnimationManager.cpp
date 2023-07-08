#include "Game/AnimationManager.hpp"
#include "Game/Utils/Utils.hpp"

#include "SFML/Graphics/RenderTarget.hpp"

void AnimationManager::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(*mCurrentAnimation, states);
}

AnimationManager::AnimationManager(const TextureHolder& textures, UnitData& unitData)
: mCurrentAnimation()
, mCurrentAnimationType()
, mCurrentDirectionType()
, mAnimations() {
    mDefaultAnimationType = unitData.defaultAnimationType;
    mDefaultDirectionType = unitData.defaultAnimationDirectionType;

    for (auto const& animationData : unitData.animationData) {
        for (auto const& firstFramePosition : unitData.firstFramePosition[animationData.first]) {
            mAnimations[animationData.first][firstFramePosition.first] =
                    std::make_shared<Animation>(textures.get(animationData.second.textureId),
                                                sf::IntRect(firstFramePosition.second, animationData.second.frameSize),
                                                animationData.second.numFrames, animationData.second.frameDuration, animationData.second.repeat);
            mAnimations[animationData.first][firstFramePosition.first]->setOrigin(animationData.second.frameOrigin);
            mAnimations[animationData.first][firstFramePosition.first]->scale(unitData.animationsScaleFactor);
        }
    }

    // set default animation
    setAnimation(mDefaultAnimationType, mDefaultDirectionType);
}

void AnimationManager::addAnimation(const TextureHolder& textures, UnitData& unitData, AnimationType animationType,
                                    DirectionType directionType) {
#define ANIMATION_DATA unitData.animationData[animationType]
#define FIRST_FRAME_POSITION unitData.firstFramePosition[animationType][directionType]
    mAnimations[animationType][directionType] =
    std::make_shared<Animation>(textures.get(ANIMATION_DATA.textureId),
                                sf::IntRect(FIRST_FRAME_POSITION, ANIMATION_DATA.frameSize),
                                ANIMATION_DATA.numFrames, ANIMATION_DATA.frameDuration, ANIMATION_DATA.repeat);
    mAnimations[animationType][directionType]->setOrigin(ANIMATION_DATA.frameOrigin);
    mAnimations[animationType][directionType]->scale(unitData.animationsScaleFactor);
}

void AnimationManager::setAnimation(AnimationType animationType, DirectionType directionType) {
    mCurrentAnimation = mAnimations[animationType][directionType];
    mCurrentAnimationType = animationType;
    mCurrentDirectionType = directionType;
    if (!mCurrentAnimation->isRepeating()) {
        mCurrentAnimation->restart();
    }
}

void AnimationManager::update(sf::Time dt) {
    mCurrentAnimation->update(dt);

    if (mCurrentAnimation->isFinished()) {
        setAnimation(mDefaultAnimationType, mDefaultDirectionType);
    }
}

AnimationType AnimationManager::getCurrentAnimationType() const {
    return mCurrentAnimationType;
}

DirectionType AnimationManager::getCurrentDirectionType() const {
    return mCurrentDirectionType;
}
