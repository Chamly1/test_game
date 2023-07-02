#include "Game/SceneNodes/Entity.hpp"
#include "Game/Utils/Utils.hpp"

#include <cmath>

EntityMover::EntityMover(Direction direction)
: mDirection(direction) {

}
void EntityMover::operator() (SceneNode& node, sf::Time dt) const {
    Entity& entity = dynamic_cast<Entity&>(node);
    entity.accelerateTo(mDirection);
}

void Entity::resetVelocity() {
    mPreviousVelocity = velocity;

    velocity.x = 0.f;
    velocity.y = 0.f;
}

void Entity::updateCurrent(sf::Time dt) {
    move(velocity * dt.asSeconds());
    resetVelocity();
}

sf::Vector2f Entity::getVelocity() {
    return velocity;
}

sf::Vector2f Entity::getPreviousVelocity() {
    return mPreviousVelocity;
}

Entity::Entity(float baseSpeed)
: velocity()
, mPreviousVelocity()
, baseSpeed(baseSpeed) {

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

void Entity::accelerateTo(const sf::Vector2f& direction) {
    if (direction.x == 0.f && direction.y == 0.f) {
        velocity = sf::Vector2f(0.f, 0.f);
    } else {
        velocity = normalizeVector(direction) * baseSpeed;
    }
}
