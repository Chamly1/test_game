#ifndef TEST_GAME_COLLIDABLENODE_HPP
#define TEST_GAME_COLLIDABLENODE_HPP

#include "GameEngine/SceneNodes/SceneNode.hpp"

class CollidableNode : public SceneNode {
public:
    CollidableNode(sf::Vector2f collisionBoxSize);
    virtual bool isCollidable() const;
};

#endif //TEST_GAME_COLLIDABLENODE_HPP
