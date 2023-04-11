#include "Entities/Entity.h"

void Entity::setVelocity(sf::Vector2f velocity) {
    this->velocity = velocity;
}

void Entity::setVelocity(float vx, float vy) {
    this->velocity.x = vx;
    this->velocity.y = vy;
}
