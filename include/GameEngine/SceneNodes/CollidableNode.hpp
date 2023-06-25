#ifndef TEST_GAME_COLLIDABLENODE_HPP
#define TEST_GAME_COLLIDABLENODE_HPP

#include "GameEngine/SceneNodes/SceneNode.hpp"

class CollidableNode : virtual public SceneNode {
private:
    sf::Vector2f mCollisionBoxSize;
    sf::Vector2f mCollisionBoxOrigin;

    void drawCollisionRec(sf::RenderTarget& target, sf::RenderStates states) const;

protected:
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    CollidableNode(sf::Vector2f collisionBoxSize);

    void setCollisionBoxSize(sf::Vector2f collisionBoxSize);
    void setCollisionBoxOrigin(sf::Vector2f collisionBoxOrigin);
    sf::FloatRect getCollisionBoxRect() const;

    bool isIntersect(CollidableNode& intersectWith) const;
    virtual void onCollision(CollidableNode& collisionWith);
};

#endif //TEST_GAME_COLLIDABLENODE_HPP
