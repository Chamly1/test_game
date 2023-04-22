#include "Animation.h"

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Texture.hpp"

void Animation::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(sprite, states);
}

Animation::Animation()
: sprite()
, firstFrame()
, numFrames(0)
, currentFrame(0)
, frameDuration(sf::Time::Zero)
, elapsedTime(sf::Time::Zero)
, repeat(false) {

}

Animation::Animation(const sf::Texture& texture, sf::IntRect firstFrame, int numFrames, sf::Time frameDuration, bool repeat)
: sprite(texture)
, firstFrame(firstFrame)
, numFrames(numFrames)
, currentFrame(0)
, frameDuration(frameDuration)
, elapsedTime(sf::Time::Zero)
, repeat(repeat) {

}

void Animation::init(const sf::Texture& texture, sf::IntRect firstFrame, int numFrames, sf::Time frameDuration, bool repeat) {
    this->sprite.setTexture(texture);
    this->firstFrame = firstFrame;
    this->numFrames = numFrames;
    this->currentFrame = 0;
    this->frameDuration = frameDuration;
    this->elapsedTime = sf::Time::Zero;
    this->repeat = repeat;
}

void Animation::update(sf::Time dt) {
    elapsedTime += dt;

    sf::IntRect textureRect;
    if (currentFrame == 0) {
        textureRect = firstFrame;
    } else {
        textureRect = sprite.getTextureRect();
    }

    sf::Vector2i textureBounds(sprite.getTexture()->getSize());
    while (elapsedTime >= frameDuration && (currentFrame <= numFrames || repeat)) {
        textureRect.left += textureRect.width;

        // If we reach the end of the texture, move to the next line
//        if(textureRect.left + textureRect.width > textureBounds.x) {
//            textureRect.left = 0;
//            textureRect.top += textureRect.height;
//        }

        elapsedTime -= frameDuration;
        if (repeat) {
            currentFrame = (currentFrame + 1) % numFrames;
            if (currentFrame == 0) {
                textureRect = firstFrame;
            }
        } else {
            currentFrame++;
        }
    }

    sprite.setTextureRect(textureRect);
}

bool Animation::isFinished() const {
    return currentFrame >= numFrames;
}

sf::FloatRect Animation::getLocalBounds() const {
    return sf::FloatRect(getOrigin(), sf::Vector2f(firstFrame.width, firstFrame.height));
}
