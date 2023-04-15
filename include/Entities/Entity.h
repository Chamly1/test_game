#ifndef TEST_GAME_ENTITY_H
#define TEST_GAME_ENTITY_H

#include "SceneNode.h"

enum class Direction {
    Up, Down, Left, Right
};

/**
 * Class to move the Entity through the Command class.
 */
class EntityMover {
private:
    Direction direction;

public:
    EntityMover(Direction direction);
    void operator() (SceneNode& node, sf::Time dt) const;
};

class Entity : public SceneNode {
private:
    sf::Vector2f velocity;
    const float baseSpeed = 75.f;

    void resetVelocity();
    virtual void updateCurrent(sf::Time dt);

public:
    void accelerateTo(Direction direction);

};

#endif //TEST_GAME_ENTITY_H
