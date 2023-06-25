#ifndef TEST_GAME_ENTITY_HPP
#define TEST_GAME_ENTITY_HPP

#include "GameEngine/SceneNodes/SceneNode.hpp"

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

class Entity : virtual public SceneNode {
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

#endif //TEST_GAME_ENTITY_HPP
