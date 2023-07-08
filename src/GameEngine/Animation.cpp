#include "GameEngine/Animation.hpp"

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Texture.hpp"

void Animation::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(mSprite, states);
}

Animation::Animation()
: mSprite()
, mFirstFrame()
, mNumFrames(0)
, mCurrentFrame(0)
, mFrameDuration(sf::Time::Zero)
, mElapsedTime(sf::Time::Zero)
, mRepeat(false) {

}

Animation::Animation(const sf::Texture& texture, sf::IntRect firstFrame, int numFrames, sf::Time frameDuration, bool repeat)
: mSprite(texture)
, mFirstFrame(firstFrame)
, mNumFrames(numFrames)
, mCurrentFrame(0)
, mFrameDuration(frameDuration)
, mElapsedTime(sf::Time::Zero)
, mRepeat(repeat) {

}

void Animation::init(const sf::Texture& texture, sf::IntRect firstFrame, int numFrames, sf::Time frameDuration, bool repeat) {
    this->mSprite.setTexture(texture);
    this->mFirstFrame = firstFrame;
    this->mNumFrames = numFrames;
    this->mCurrentFrame = 0;
    this->mFrameDuration = frameDuration;
    this->mElapsedTime = sf::Time::Zero;
    this->mRepeat = repeat;
}

void Animation::update(sf::Time dt) {
    mElapsedTime += dt;

    sf::IntRect textureRect;
    if (mCurrentFrame == 0) {
        textureRect = mFirstFrame;
    } else {
        textureRect = mSprite.getTextureRect();
    }

    sf::Vector2i textureBounds(mSprite.getTexture()->getSize());
    while (mElapsedTime >= mFrameDuration && (mCurrentFrame <= mNumFrames || mRepeat)) {
        textureRect.left += textureRect.width;

        // If we reach the end of the texture, move to the next line
//        if(textureRect.left + textureRect.width > textureBounds.x) {
//            textureRect.left = 0;
//            textureRect.top += textureRect.height;
//        }

        mElapsedTime -= mFrameDuration;
        if (mRepeat) {
            mCurrentFrame = (mCurrentFrame + 1) % mNumFrames;
            if (mCurrentFrame == 0) {
                textureRect = mFirstFrame;
            }
        } else {
            mCurrentFrame++;
        }
    }

    mSprite.setTextureRect(textureRect);
}

bool Animation::isFinished() const {
    return mCurrentFrame >= mNumFrames;
}

void Animation::restart() {
    mCurrentFrame = 0;
    mElapsedTime = sf::Time::Zero;
}

bool Animation::isRepeating() const {
    return mRepeat;
}

sf::FloatRect Animation::getLocalBounds() const {
    return sf::FloatRect(getOrigin(), sf::Vector2f(mFirstFrame.width, mFirstFrame.height));
}
