#ifndef TEST_GAME_COLLIDABLENODE_H
#define TEST_GAME_COLLIDABLENODE_H

#include "SceneNodes/SceneNode.h"

class CollidableNode : public SceneNode {
public:
    CollidableNode(sf::Vector2f collisionBoxSize);
    virtual bool isCollidable() const;
};

#endif //TEST_GAME_COLLIDABLENODE_H
