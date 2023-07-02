#include "Game/AIs/ZombieAI.hpp"
#include "Game/SceneNodes/MovableNode.hpp"

#include "SFML/Graphics/RenderTarget.hpp"

ZombieAI::ZombieAI(std::shared_ptr<const VectorFieldGrid> grid)
: mGrid(grid) {

}

bool ZombieAI::checkCompatibilities(SceneNode& sceneNode) {
    bool isCompatible = true;

    isCompatible = isCompatible && (dynamic_cast<MovableNode*>(&sceneNode) != nullptr);

    return isCompatible;
}

void ZombieAI::update(sf::Time dt, SceneNode* sceneNode) {
    MovableNode* entity = dynamic_cast<MovableNode*>(sceneNode);
//    entity->accelerateTo(mGrid.getFieldVectorInPoint(entity->getPosition()));
    entity->accelerateTo(mGrid->getNextCellCenterInPoint(entity->getPosition()) - entity->getPosition());
}
