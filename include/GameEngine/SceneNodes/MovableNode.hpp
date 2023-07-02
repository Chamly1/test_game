#ifndef TEST_GAME_MOVABLENODE_HPP
#define TEST_GAME_MOVABLENODE_HPP

#include "SceneNode.hpp"

enum class Direction {
    Up, Down, Left, Right
};

/**
 * Class to move the Entity through the Command class.
 */
class EntityMover {
private:
    Direction mDirection;

public:
    EntityMover(Direction direction);
    void operator() (SceneNode& node, sf::Time dt) const;
};

class MovableNode : virtual public SceneNode {
private:
    sf::Vector2f velocity;
    sf::Vector2f mPreviousVelocity;
    float baseSpeed;

    void resetVelocity();

protected:
    virtual void updateCurrent(sf::Time dt);
    sf::Vector2f getVelocity();
    sf::Vector2f getPreviousVelocity();

public:
    MovableNode(float baseSpeed);
    void accelerateTo(Direction direction);
    void accelerateTo(const sf::Vector2f& direction);

};

#endif //TEST_GAME_MOVABLENODE_HPP
