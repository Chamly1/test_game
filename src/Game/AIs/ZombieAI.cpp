#include "Game/AIs/ZombieAI.hpp"
#include "Game/SceneNodes/Entity.hpp"

bool ZombieAI::checkCompatibilities(SceneNode& sceneNode) {
    bool isCompatible = true;

    isCompatible = isCompatible && (dynamic_cast<Entity*>(&sceneNode) != nullptr);

    return isCompatible;
}

void ZombieAI::update(sf::Time dt, SceneNode& sceneNode) {
    Entity& entity = static_cast<Entity&>(sceneNode);
    entity.accelerateTo(Direction::Right);
}
