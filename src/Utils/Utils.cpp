#include "Utils/Utils.h"

#include "cmath"

void setOriginToCenter(sf::Text& text) {
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
}

void setOriginToCenter(sf::Sprite& sprite) {
    sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
}

void setOriginToCenter(Animation& animation) {
    sf::FloatRect bounds = animation.getLocalBounds();
    animation.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
}

DirectionType moveVelocityToAnimationDirection(const sf::Vector2f& velocity, DirectionType oldDirection) {
    if (velocity.x == 0 && velocity.y == 0) {
        return oldDirection;
    }

    DirectionType newDirection;
    if (velocity.y >= 0) {
        if (velocity.x > 0) {
            newDirection = DirectionType::BottomRight;
        } else if (velocity.x < 0) {
            newDirection = DirectionType::BottomLeft;
        } else {
            if (oldDirection == DirectionType::BottomRight ||
                oldDirection == DirectionType::TopRight) {
                newDirection = DirectionType::BottomRight;
            } else {
                newDirection = DirectionType::BottomLeft;
            }
        }
    } else {
        if (velocity.x > 0) {
            newDirection = DirectionType::TopRight;
        } else if (velocity.x < 0) {
            newDirection = DirectionType::TopLeft;
        } else {
            if (oldDirection == DirectionType::BottomRight ||
                oldDirection == DirectionType::TopRight) {
                newDirection = DirectionType::TopRight;
            } else {
                newDirection = DirectionType::TopLeft;
            }
        }
    }

    return newDirection;
}
