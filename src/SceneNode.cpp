#include "SceneNode.h"

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();

    drawCurrent(target, states);

    for (const std::unique_ptr<SceneNode>& child : children) {
        child->draw(target, states);
    }
}

void SceneNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {

}

SceneNode::SceneNode() :children(), parent(nullptr) {

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
