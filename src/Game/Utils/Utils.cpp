#include "Game/Utils/Utils.hpp"

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

    bool isRight = velocity.x > 0 || (velocity.x == 0 && (oldDirection == DirectionType::TopRight || oldDirection == DirectionType::BottomRight));
    bool isTop = velocity.y < 0 || (velocity.y == 0 && (oldDirection == DirectionType::TopRight || oldDirection == DirectionType::TopLeft));

    DirectionType newDirection;
    if (isRight) {
        if (isTop) {
            newDirection = DirectionType::TopRight;
        } else {
            newDirection = DirectionType::BottomRight;
        }
    } else {
        if (isTop) {
            newDirection = DirectionType::TopLeft;
        } else {
            newDirection = DirectionType::BottomLeft;
        }
    }

    return newDirection;
}
