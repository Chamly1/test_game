#include "GameEngine/SceneNodes/SceneNode.hpp"

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

#include <cassert>

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();

    drawCurrent(target, states);
#ifndef NDEBUG
    drawCollisionRec(target, states);
    drawNodePosition(target, states);
#endif

    for (const std::unique_ptr<SceneNode>& child : mChildren) {
        child->draw(target, states);
    }
}

void SceneNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {

}

void SceneNode::updateCurrent(sf::Time dt) {

}

void SceneNode::updateChildren(sf::Time dt) {
    for (const std::unique_ptr<SceneNode>& child : mChildren) {
        child->update(dt);
    }
}

void SceneNode::drawCollisionRec(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::RectangleShape shape;
    sf::FloatRect collisionBoxRect = getCollisionBoxRect();
    shape.setPosition(sf::Vector2f(collisionBoxRect.left, collisionBoxRect.top));
    shape.setSize(sf::Vector2f(collisionBoxRect.width, collisionBoxRect.height));
    shape.setFillColor(sf::Color(0, 255, 0, 50));
    shape.setOutlineColor(sf::Color(0, 255, 0, 150));
    shape.setOutlineThickness(1.f);

    target.draw(shape);
}

void SceneNode::drawNodePosition(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::RectangleShape shape;
    shape.setPosition(getPosition());
    shape.setSize(sf::Vector2f(5.f, 5.f));
    shape.setFillColor(sf::Color(0, 0, 255, 255));

    target.draw(shape);
}

void SceneNode::checkNodeCollisions(SceneNode& nodeToCheck, std::set<std::pair<SceneNode*, SceneNode*>>& collisionPairs) {
    if (!nodeToCheck.isCollidable()) {
        return;
    }

    if (this != &nodeToCheck && isCollidable() && isIntersect(nodeToCheck)) {
        // std::minmax() to avoid duplication
        collisionPairs.insert(std::minmax(this, &nodeToCheck));
    }

    for (std::unique_ptr<SceneNode>& child : mChildren) {
        child->checkNodeCollisions(nodeToCheck, collisionPairs);
    }
}

void SceneNode::checkNodeAndChildrenCollisions(SceneNode& nodeToCheck, std::set<std::pair<SceneNode*, SceneNode*>>& collisionPairs) {
    checkNodeCollisions(nodeToCheck, collisionPairs);

    for (std::unique_ptr<SceneNode>& child : nodeToCheck.mChildren) {
        checkNodeAndChildrenCollisions(*child, collisionPairs);
    }
}

SceneNode::SceneNode()
: mChildren()
, mParent(nullptr)
, mSceneNodeCategory(0)
, mCollisionBoxSize()
, mCollisionBoxOrigin() {

}

void SceneNode::attachChild(std::unique_ptr<SceneNode> child) {
    child->mParent = this;
    mChildren.push_back(std::move(child));
}

std::unique_ptr<SceneNode> SceneNode::detachChild(const SceneNode& node) {
    auto found = std::find_if(mChildren.begin(), mChildren.end(),
                              [&] (std::unique_ptr<SceneNode>& p) -> bool {return p.get() == &node;});

    assert(found != mChildren.end());

    std::unique_ptr<SceneNode> res = std::move(*found);
    res->mParent = nullptr;
    mChildren.erase(found);
    return res;
}

void SceneNode::update(sf::Time dt) {
    updateCurrent(dt);
    updateChildren(dt);
}

sf::Transform SceneNode::getWorldTransform() const {
    sf::Transform transform = sf::Transform::Identity;
    for (const SceneNode* node = this; node != nullptr; node = node->mParent) {
        transform = node->getTransform() * transform;
    }
    return transform;
}

sf::Vector2f SceneNode::getWorldPosition() const {
    return getWorldTransform() * sf::Vector2f();
}

unsigned int SceneNode::getSceneNodeCategory() const {
    return mSceneNodeCategory;
}

void SceneNode::addSceneNodeCategory(unsigned int sceneNodeCategory) {
    this->mSceneNodeCategory |= sceneNodeCategory;
}

void SceneNode::onCommand(const Command& command, sf::Time dt) {
    if (command.sceneNodeCategory & mSceneNodeCategory) {
        command.action(*this, dt);
    }

    for (const std::unique_ptr<SceneNode>& child : mChildren) {
        child->onCommand(command, dt);
    }
}

void SceneNode::setCollisionBoxSize(sf::Vector2f collisionBoxSize) {
    this->mCollisionBoxSize = collisionBoxSize;
}

void SceneNode::setCollisionBoxOrigin(sf::Vector2f collisionBoxOrigin) {
    this->mCollisionBoxOrigin = collisionBoxOrigin;
}

sf::FloatRect SceneNode::getCollisionBoxRect() const {
    return sf::FloatRect(getPosition() - mCollisionBoxOrigin, mCollisionBoxSize);
}

bool SceneNode::isCollidable() const {
    return false;
}

bool SceneNode::isIntersect(SceneNode& intersectWith) const {
    return getCollisionBoxRect().intersects(intersectWith.getCollisionBoxRect());
}

void SceneNode::onCollision(SceneNode& collisionWith) {

}

void SceneNode::checkAllCollisions(std::set<std::pair<SceneNode*, SceneNode*>>& collisionPairs) {
    checkNodeAndChildrenCollisions(*this, collisionPairs);
}

const SceneNode* SceneNode::getRootPtr() const {
    if (mParent == nullptr) {
        return this;
    } else {
        return mParent->getRootPtr();
    }
}

const SceneNode* SceneNode::getFirstNodeOfCategoryPtr(unsigned int sceneNodeCategory) const {
    const SceneNode* resPtr = nullptr;

    if (mSceneNodeCategory & sceneNodeCategory) {
        return this;
    } else {
        for (const std::unique_ptr<SceneNode>& child : mChildren) {
            resPtr = child->getFirstNodeOfCategoryPtr(sceneNodeCategory);
            if (resPtr != nullptr) {
                break;
            }
        }
    }

    return resPtr;
}
