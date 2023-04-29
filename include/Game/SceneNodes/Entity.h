#ifndef TEST_GAME_ENTITY_H
#define TEST_GAME_ENTITY_H

#include "GameEngine/SceneNodes/SceneNode.h"

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
    float baseSpeed;

    void resetVelocity();

protected:
    virtual void updateCurrent(sf::Time dt);
    sf::Vector2f getVelocity();

public:
    Entity(float baseSpeed);
    void accelerateTo(Direction direction);

};

#endif //TEST_GAME_ENTITY_H