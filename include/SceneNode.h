#ifndef TEST_GAME_SCENENODE_H
#define TEST_GAME_SCENENODE_H

#include "Command.h"

#include "SFML/Graphics/Transformable.hpp"
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/System/NonCopyable.hpp"
#include "SFML/System/Time.hpp"

#include <memory>

namespace SceneNodeCategory {
    enum Type {
        None = 0,
        Scene = 1 << 0,
        PlayerUnit = 1 << 1,
        EnemyUnit = 1 << 2,
        Player = 1 << 3
    };
}

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable {
private:
    std::vector<std::unique_ptr<SceneNode>> children;
    SceneNode* parent;

    unsigned int sceneNodeCategory;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time dt);
    void updateChildren(sf::Time dt);

public:
    SceneNode();

    void attachChild(std::unique_ptr<SceneNode> child);
    std::unique_ptr<SceneNode> detachChild(const SceneNode& node);

    void update(sf::Time dt);

    sf::Transform getWorldTransform() const;
    sf::Vector2f getWorldPosition() const;

    unsigned int getSceneNodeCategory() const;
    /**
     * Add the scene node category with the bitwise OR.
     * You MUST use categories from SceneNodeCategory namespace.
     *
     * @param sceneNodeCategory category to add.
     */
    void addSceneNodeCategory(unsigned int sceneNodeCategory);

    /**
     * Execute the command if its sceneNodeCategory correspond to the SceneNode and pass the command to all children.
     *
     * @param command command to execute.
     * @param dt delta time depending on which the command will be processed.
     */
    void onCommand(const Command& command, sf::Time dt);
};

#endif //TEST_GAME_SCENENODE_H
