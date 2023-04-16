#include "SceneNodes/SceneNode.h"

#include <cassert>

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();

    drawCurrent(target, states);

    for (const std::unique_ptr<SceneNode>& child : children) {
        child->draw(target, states);
    }
}

void SceneNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {

}

void SceneNode::updateCurrent(sf::Time dt) {

}

void SceneNode::updateChildren(sf::Time dt) {
    for (const std::unique_ptr<SceneNode>& child : children) {
        child->update(dt);
    }
}

SceneNode::SceneNode()
: children()
, parent(nullptr)
, sceneNodeCategory(SceneNodeCategory::None) {

}

void SceneNode::attachChild(std::unique_ptr<SceneNode> child) {
    child->parent = this;
    children.push_back(std::move(child));
}

std::unique_ptr<SceneNode> SceneNode::detachChild(const SceneNode& node) {
    auto found = std::find_if(children.begin(), children.end(),
                              [&] (std::unique_ptr<SceneNode>& p) -> bool {return p.get() == &node;});

    assert(found != children.end());

    std::unique_ptr<SceneNode> res = std::move(*found);
    res->parent = nullptr;
    children.erase(found);
    return res;
}

void SceneNode::update(sf::Time dt) {
    updateCurrent(dt);
    updateChildren(dt);
}

sf::Transform SceneNode::getWorldTransform() const {
    sf::Transform transform = sf::Transform::Identity;
    for (const SceneNode* node = this; node != nullptr; node = node->parent) {
        transform = node->getTransform() * transform;
    }
    return transform;
}

sf::Vector2f SceneNode::getWorldPosition() const {
    return getWorldTransform() * sf::Vector2f();
}

unsigned int SceneNode::getSceneNodeCategory() const {
    return sceneNodeCategory;
}

void SceneNode::addSceneNodeCategory(unsigned int sceneNodeCategory) {
    this->sceneNodeCategory |= sceneNodeCategory;
}

void SceneNode::onCommand(const Command& command, sf::Time dt) {
    if (command.sceneNodeCategory & sceneNodeCategory) {
        command.action(*this, dt);
    }

    for (const std::unique_ptr<SceneNode>& child : children) {
        child->onCommand(command, dt);
    }
}