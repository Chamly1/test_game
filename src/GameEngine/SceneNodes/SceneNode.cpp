#include "GameEngine/SceneNodes/SceneNode.hpp"

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

#include <cassert>

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();

    drawCurrent(target, states);
#ifndef NDEBUG
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

void SceneNode::drawNodePosition(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::RectangleShape shape;
    shape.setPosition(getPosition());
    shape.setSize(sf::Vector2f(5.f, 5.f));
    shape.setFillColor(sf::Color(0, 0, 255, 255));

    target.draw(shape);
}

SceneNode::SceneNode()
: mChildren()
, mParent(nullptr)
, mSceneNodeCategory(0) {

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

SceneNode* SceneNode::getRootPtr() {
    if (mParent == nullptr) {
        return this;
    } else {
        return mParent->getRootPtr();
    }
}

SceneNode* SceneNode::getFirstNodeOfCategoryPtr(unsigned int sceneNodeCategory) {
    SceneNode* resPtr = nullptr;

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

void SceneNode::getAllNodeOfCategoryPtrs(unsigned int sceneNodeCategory, std::vector<SceneNode*>& res) {

    if (mSceneNodeCategory & sceneNodeCategory) {
        res.push_back(this);
    }

    for (const std::unique_ptr<SceneNode>& child : mChildren) {
        child->getAllNodeOfCategoryPtrs(sceneNodeCategory, res);
    }
}
