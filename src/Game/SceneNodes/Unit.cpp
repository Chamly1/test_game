#include "Game/SceneNodes/Unit.hpp"
#include "Game/SceneNodes/SceneNodeCategory.hpp"
#include "Game/Utils/Utils.hpp"
#include "Game/DataTables.hpp"
#include "GameEngine/Utils/DebugLog.hpp"
#include "GameEngine/Utils/UtilsFunctions.hpp"

#include "SFML/Graphics/RenderTarget.hpp"

#include <cmath>

std::unordered_map<UnitType, UnitData> unitData = initUnitData();
static const int MAX_COLLISION_CHECKS = 4;

UnitController::UnitController(UnitAction unitAction)
: mUnitAction(unitAction) {

}

void UnitController::operator() (SceneNode& node, sf::Time dt) const {
    Unit& unit = dynamic_cast<Unit&>(node);
    if (mUnitAction == UnitAction::Attack) {
        unit.attack();
    }
}

void Unit::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(mAnimationManager, states);
    CollidableNode::drawCurrent(target, states);
#ifndef NDEBUG
    AttackableNode::drawAttackCollisionRec(target, states);
#endif
}

void Unit::updateAnimations(sf::Time dt) {
    sf::Vector2f velocity = MovableNode::getVelocity();

    AnimationType newAnimationType;
    if (isAttacking()) {
        newAnimationType = AnimationType::Attack;
    }else if (velocity.x != 0 || velocity.y != 0) {
        newAnimationType = AnimationType::Walk;
    } else {
        newAnimationType = AnimationType::Idle;
    }

    if (mAnimationManager.getCurrentAnimationType() != newAnimationType ||
        mAnimationManager.getCurrentDirectionType() != getLookingDirection()) {
        mAnimationManager.setAnimation(newAnimationType, getLookingDirection());
//        setOriginToCenter(animation);
    }

    mAnimationManager.update(dt);
}

void Unit::moveUnitWithCollisionResolving(sf::Time dt) {
    sf::Vector2f velocity = MovableNode::getVelocity();

    // skip move segment if node doesn't move or is attacking
    if ((velocity.x == 0.f && velocity.y == 0.f) || isAttacking()) {
        return;
    }

//    MovableNode::updateCurrent(dt);
    const SceneNode* sceneGraph = getRootPtr();
    std::vector<const SceneNode*> impassableNodes;
    sceneGraph->getAllNodeOfCategoryPtrs(SceneNodeCategory::ImpassableZone, impassableNodes);

    if (getSceneNodeCategory() & SceneNodeCategory::EnemyUnit) {
        sceneGraph->getAllNodeOfCategoryPtrs(SceneNodeCategory::ImpassableUnit, impassableNodes);
    }

    const CollidableNode* collidableNode;
    sf::FloatRect collisionRect = getCollisionBoxRect();
    sf::FloatRect collisionWithRect;
    sf::Vector2f collisionRectCenter = sf::Vector2f(collisionRect.left + collisionRect.width / 2.f, collisionRect.top + collisionRect.height / 2.f);
    sf::Vector2f movementVector = velocity * dt.asSeconds();
    sf::Vector2f movementEnd;
    sf::Vector2f collisionAt;
    sf::Vector2f collisionNormal;

    bool isCollisionAppear;
    int collisionChecks = 0;
    do {

        isCollisionAppear = false;
        ++collisionChecks;
        if (collisionChecks >= MAX_COLLISION_CHECKS) {
            movementVector = sf::Vector2f(0.f, 0.f);
            break;
        }

        for (const SceneNode* node : impassableNodes) {
            collidableNode = dynamic_cast<const CollidableNode*>(node);
            if (collidableNode != nullptr) {
                collisionWithRect = collidableNode->getCollisionBoxRect();

                // expand target rectangle by source dimensions
                collisionWithRect.left -= collisionRect.width / 2.f;
                collisionWithRect.top -= collisionRect.height / 2.f;
                collisionWithRect.width += collisionRect.width;
                collisionWithRect.height += collisionRect.height;

                movementEnd = collisionRectCenter + movementVector;
                if (isSegmentIntersectRectangle(collisionRectCenter, movementEnd, collisionWithRect, collisionAt, collisionNormal)) {
                    isCollisionAppear = true;
                    sf::Vector2f penetratedPart = movementEnd - collisionAt;
                    sf::Vector2f vectorToDiscardPenetration;
                    // + 0.1f to fix situation when after move, node end at collision point(not in front of).
                    vectorToDiscardPenetration.x = (fabsf(penetratedPart.x) + 0.1f) * collisionNormal.x;
                    vectorToDiscardPenetration.y = (fabsf(penetratedPart.y) + 0.1f) * collisionNormal.y;
                    // discard portion that penetrate obstacle
                    movementVector += vectorToDiscardPenetration;
                }
            }
        }
    } while (isCollisionAppear);
    move(movementVector);
    resetVelocity();
}

void Unit::updateCurrent(sf::Time dt) {
    setLookingDirection(moveVelocityToAnimationDirection(getVelocity(), getLookingDirection()));

    AttackableNode::updateCurrent(dt);
    updateAnimations(dt);
    moveUnitWithCollisionResolving(dt);
}

Unit::Unit(UnitType unitType, const TextureHolder& textures)
: MovableNode(unitData[unitType].baseSpeed)
, CollidableNode(unitData[unitType].collisionBoxSize)
, AttackableNode(unitData[unitType].attackDuration, unitData[unitType].attackCollisionBoxShift, unitData[unitType].attackCollisionBoxSize)
, mUnitType(unitType)
, mAnimationManager(textures, unitData[unitType]) {
    setCollisionBoxOrigin(unitData[unitType].collisionBoxOrigin);
//    mAnimationManager.setAnimation(AnimationType::Idle, DirectionType::BottomRight);
//    setOriginToCenter(animation);
}

void Unit::onCollision(CollidableNode& collisionWith) {
    
}
