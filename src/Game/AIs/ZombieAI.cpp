#include "Game/AIs/ZombieAI.hpp"
#include "Game/SceneNodes/Entity.hpp"
#include "Game/SceneNodes/SceneNodeCategory.hpp"

#include "SFML/Graphics/RenderTarget.hpp"

void ZombieAI::drawVisionRay(sf::RenderTarget& target, const SceneNode* zombieSceneNode) const {
    sf::VertexArray visionRay(sf::PrimitiveType::Lines, 2);
    visionRay[0].position = zombieSceneNode->getPosition();
    visionRay[1].position = mPlayerPosition;

    visionRay[0].color = sf::Color(255, 255, 255);
    visionRay[1].color = sf::Color(255, 255, 255);

    target.draw(visionRay);
}

ZombieAI::ZombieAI(std::shared_ptr<const Grid> grid)
: mGrid(grid) {

}

bool ZombieAI::checkCompatibilities(SceneNode& sceneNode) {
    bool isCompatible = true;

    isCompatible = isCompatible && (dynamic_cast<Entity*>(&sceneNode) != nullptr);

    return isCompatible;
}

void ZombieAI::update(sf::Time dt, SceneNode* sceneNode) {
    const SceneNode* sceneRoot = sceneNode->getRootPtr();
    mPlayerPosition = sceneRoot->getFirstNodeOfCategoryPtr(SceneNodeCategory::Player)->getPosition();

    Entity* entity = dynamic_cast<Entity*>(sceneNode);
//    entity->accelerateTo(mGrid.getFieldVectorInPoint(entity->getPosition()));
    entity->accelerateTo(mGrid->getNextCellCenterInPoint(entity->getPosition()) - entity->getPosition());
}
