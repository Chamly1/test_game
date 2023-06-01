#include "GameEngine/SceneNodes/CollidableNode.hpp"

CollidableNode::CollidableNode(sf::Vector2f collisionBoxSize) {
    setCollisionBoxSize(collisionBoxSize);
}

bool CollidableNode::isCollidable() const {
    return true;
}
