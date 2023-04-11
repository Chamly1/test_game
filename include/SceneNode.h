#ifndef TEST_GAME_SCENENODE_H
#define TEST_GAME_SCENENODE_H

#include <vector>
#include <memory>
#include <algorithm>
#include <cassert>

#include "SFML/Graphics.hpp"

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable {
private:
    std::vector<std::unique_ptr<SceneNode>> children;
    SceneNode* parent;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time dt);
    void updateChildren(sf::Time dt);

public:
    SceneNode();
    void attachChild(std::unique_ptr<SceneNode> child);
    std::unique_ptr<SceneNode> detachChild(const SceneNode& node);
    void update(sf::Time dt);
};

#endif //TEST_GAME_SCENENODE_H
