#ifndef TEST_GAME_ENTITY_H
#define TEST_GAME_ENTITY_H

#include "SFML/Graphics.hpp"

#include "SceneNode.h"

class Entity : SceneNode {
private:
    sf::Vector2f velocity;

public:
    void setVelocity(sf::Vector2f velocity);
    void setVelocity(float vx, float vy);

};

#endif //TEST_GAME_ENTITY_H
