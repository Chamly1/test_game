#include <cmath>

#include "Entities/Entity.h"

void Entity::resetVelocity() {
    velocity.x = 0.f;
    velocity.y = 0.f;
}

void Entity::updateCurrent(sf::Time dt) {
    move(velocity * dt.asSeconds());
    resetVelocity();
}

void Entity::accelerateTo(Direction direction) {
    switch (direction) {
        case Direction::Up:
            velocity.y = -baseSpeed;
            break;
        case Direction::Down:
            velocity.y = baseSpeed;
            break;
        case Direction::Left:
            velocity.x = -baseSpeed;
            break;
        case Direction::Right:
            velocity.x = baseSpeed;
            break;
    }

    if (velocity.x != 0 && velocity.y != 0) {
        velocity /= std::sqrt(2.f);
    }
}
