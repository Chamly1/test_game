#include "Animation.h"

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Texture.hpp"

void Animation::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(sprite, states);
}

Animation::Animation(const sf::Texture& texture, sf::Vector2i frameSize, int numFrames, sf::Time frameDuration, bool repeat)
: sprite(texture)
, frameSize(frameSize)
, numFrames(numFrames)
, currentFrame(0)
, frameDuration(frameDuration)
, elapsedTime(sf::Time::Zero)
, repeat(repeat) {

}

void Animation::update(sf::Time dt) {
    elapsedTime += dt;

    sf::IntRect textureRect;
    if (currentFrame == 0) {
        textureRect = sf::IntRect(0, 0, frameSize.x, frameSize.y);
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
                textureRect = sf::IntRect(0, 0, frameSize.x, frameSize.y);
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
