#include "GameEngine/SceneNodes/CollidableNode.h"

CollidableNode::CollidableNode(sf::Vector2f collisionBoxSize) {
    setCollisionBoxSize(collisionBoxSize);
}

bool CollidableNode::isCollidable() const {
    return true;
}
