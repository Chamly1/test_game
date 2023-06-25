#ifndef TEST_GAME_SCENENODE_HPP
#define TEST_GAME_SCENENODE_HPP

#include "GameEngine/Commands/Command.hpp"

#include "SFML/Graphics/Transformable.hpp"
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/System/NonCopyable.hpp"
#include "SFML/System/Time.hpp"

#include <memory>
#include <set>

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable {
private:
    std::vector<std::unique_ptr<SceneNode>> mChildren;
    SceneNode* mParent;

    unsigned int mSceneNodeCategory;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time dt);
    void updateChildren(sf::Time dt);
    void drawNodePosition(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    SceneNode();

    void attachChild(std::unique_ptr<SceneNode> child);
    std::unique_ptr<SceneNode> detachChild(const SceneNode& node);

    void update(sf::Time dt);

    sf::Transform getWorldTransform() const;
    sf::Vector2f getWorldPosition() const;

    unsigned int getSceneNodeCategory() const;
    /**
     * Add the scene node category with the bitwise OR. It is highly recommended to use one specific bit as one
     * category, as a result you can easily combine them.
     * For example:
     *      1 << 0 // category 1
     *      1 << 1 // category 2
     *      1 << 2 // category 3
     *      and so on...
     *
     * @param sceneNodeCategory category to add.
     */
    void addSceneNodeCategory(unsigned int sceneNodeCategory);

    /**
     * Execute the command if its sceneNodeCategory correspond to the SceneNode. Do the same for all children.
     *
     * @param command command to execute.
     * @param dt delta time depending on which the command will be processed.
     */
    void onCommand(const Command& command, sf::Time dt);

    const SceneNode* getRootPtr() const;
    const SceneNode* getFirstNodeOfCategoryPtr(unsigned int sceneNodeCategory) const;

    friend void checkNodeCollisions(SceneNode& thisNode, SceneNode& nodeToCheck, std::set<std::pair<SceneNode*, SceneNode*>>& collisionPairs);
    friend void checkNodeAndChildrenCollisions(SceneNode& thisNode, SceneNode& nodeToCheck, std::set<std::pair<SceneNode*, SceneNode*>>& collisionPairs);
};

#endif //TEST_GAME_SCENENODE_HPP
