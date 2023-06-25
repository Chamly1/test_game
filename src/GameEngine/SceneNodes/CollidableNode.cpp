#include "GameEngine/SceneNodes/CollidableNode.hpp"

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

void CollidableNode::drawCollisionRec(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::RectangleShape shape;
    sf::FloatRect collisionBoxRect = getCollisionBoxRect();
    shape.setPosition(sf::Vector2f(collisionBoxRect.left, collisionBoxRect.top));
    shape.setSize(sf::Vector2f(collisionBoxRect.width, collisionBoxRect.height));
    shape.setFillColor(sf::Color(0, 255, 0, 50));
    shape.setOutlineColor(sf::Color(0, 255, 0, 150));
    shape.setOutlineThickness(1.f);

    target.draw(shape);
}

void CollidableNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
#ifndef NDEBUG
    drawCollisionRec(target, states);
#endif
}

CollidableNode::CollidableNode(sf::Vector2f collisionBoxSize) {
    setCollisionBoxSize(collisionBoxSize);
}

void CollidableNode::setCollisionBoxSize(sf::Vector2f collisionBoxSize) {
    this->mCollisionBoxSize = collisionBoxSize;
}

void CollidableNode::setCollisionBoxOrigin(sf::Vector2f collisionBoxOrigin) {
    this->mCollisionBoxOrigin = collisionBoxOrigin;
}

sf::FloatRect CollidableNode::getCollisionBoxRect() const {
    return sf::FloatRect(getPosition() - mCollisionBoxOrigin, mCollisionBoxSize);
}

bool CollidableNode::isIntersect(CollidableNode& intersectWith) const {
    return getCollisionBoxRect().intersects(intersectWith.getCollisionBoxRect());
}

void CollidableNode::onCollision(CollidableNode& collisionWith) {

}
