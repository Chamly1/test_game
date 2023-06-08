#include "Game/AIs/ZombieAI.hpp"
#include "Game/SceneNodes/Entity.hpp"
#include "Game/SceneNodes/SceneNodeCategory.hpp"

#include "SFML/Graphics/RenderTarget.hpp"

void ZombieAI::drawVisionRay(sf::RenderTarget& target, const SceneNode* zombieSceneNode) const {
    sf::VertexArray visionRay(sf::PrimitiveType::Lines, 2);
    visionRay[0].position = zombieSceneNode->getPosition();
    visionRay[1].position = mPlayerNodePtr->getPosition();

    visionRay[0].color = sf::Color(255, 255, 255);
    visionRay[1].color = sf::Color(255, 255, 255);

    target.draw(visionRay);
}

bool ZombieAI::checkCompatibilities(SceneNode& sceneNode) {
    bool isCompatible = true;

    isCompatible = isCompatible && (dynamic_cast<Entity*>(&sceneNode) != nullptr);

    return isCompatible;
}

void ZombieAI::update(sf::Time dt, SceneNode* sceneNode) {
    Entity* entity = static_cast<Entity*>(sceneNode);
    entity->accelerateTo(Direction::Right);

    const SceneNode* sceneRoot = sceneNode->getRootPtr();
    mPlayerNodePtr = sceneRoot->getFirstNodePtrOfCategory(SceneNodeCategory::Player);
}
