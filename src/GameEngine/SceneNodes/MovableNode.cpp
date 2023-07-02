#include "GameEngine/SceneNodes/MovableNode.hpp"
#include "GameEngine/Utils/UtilsFunctions.hpp"

#include <cmath>

EntityMover::EntityMover(Direction direction)
: mDirection(direction) {

}
void EntityMover::operator() (SceneNode& node, sf::Time dt) const {
    MovableNode& entity = dynamic_cast<MovableNode&>(node);
    entity.accelerateTo(mDirection);
}

void MovableNode::resetVelocity() {
    velocity.x = 0.f;
    velocity.y = 0.f;
}

void MovableNode::updateCurrent(sf::Time dt) {
    move(velocity * dt.asSeconds());
    resetVelocity();
}

sf::Vector2f MovableNode::getVelocity() {
    return velocity;
}

MovableNode::MovableNode(float baseSpeed)
: velocity()
, baseSpeed(baseSpeed) {

}

void MovableNode::accelerateTo(Direction direction) {
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

void MovableNode::accelerateTo(const sf::Vector2f& direction) {
    if (direction.x == 0.f && direction.y == 0.f) {
        velocity = sf::Vector2f(0.f, 0.f);
    } else {
        velocity = normalizeVector(direction) * baseSpeed;
    }
}
