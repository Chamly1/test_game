#ifndef TEST_GAME_SCENENODE_H
#define TEST_GAME_SCENENODE_H

#include "Command.h"

#include "SFML/Graphics/Transformable.hpp"
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/System/NonCopyable.hpp"
#include "SFML/System/Time.hpp"

#include <memory>
#include <set>

namespace SceneNodeCategory {
    enum Type {
        None = 0,
        Scene = 1 << 0,
        PlayerUnit = 1 << 1,
        EnemyUnit = 1 << 2,
        Player = 1 << 3,
        ImpassableZone = 1 << 4
    };
}

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable {
private:
    std::vector<std::unique_ptr<SceneNode>> children;
    SceneNode* parent;

    unsigned int sceneNodeCategory;
    sf::Vector2f collisionBoxSize;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time dt);
    void updateChildren(sf::Time dt);
    void drawCollisionRec(sf::RenderTarget& target, sf::RenderStates states) const;

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

    void setCollisionBoxSize(sf::Vector2f collisionBoxSize);
    sf::FloatRect getCollisionBoxRect() const;

    virtual bool isCollidable() const;
    bool isIntersect(SceneNode& intersectWith) const;
    virtual void onCollision(SceneNode& collisionWith);

    /**
     * Check collisions between:
     *  - this node and nodeToCheck
     *  - children(and all tree) of this node and nodeToCheck.
     * Store detected collision to collisionPairs.
     *
     * @param nodeToCheck SceneNode with which collision check.
     * @param collisionPairs container where detected collision pairs are stored.
     */
    void checkNodeCollisions(SceneNode& nodeToCheck, std::set<std::pair<SceneNode*, SceneNode*>>& collisionPairs);

    /**
     * Check collisions between:
     *  - this node and nodeToCheck
     *  - each child(and all tree) of this node and each child(and all tree) of nodeToCheck.
     * Store detected collision to collisionPairs.
     *
     * @param nodeToCheck SceneNode with which collision check.
     * @param collisionPairs container where detected collision pairs are stored.
     */
    void checkNodeAndChildrenCollisions(SceneNode& nodeToCheck, std::set<std::pair<SceneNode*, SceneNode*>>& collisionPairs);

    /**
     * Check collisions of each SceneNode with each in tree. Store detected collision to collisionPairs.
     *
     * @param collisionPairs container where detected collision pairs are stored.
     */
    void checkAllCollisions(std::set<std::pair<SceneNode*, SceneNode*>>& collisionPairs);
};

#endif //TEST_GAME_SCENENODE_H
