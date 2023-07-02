#include "Game/SceneNodes/Unit.hpp"
#include "Game/SceneNodes/SceneNodeCategory.hpp"
#include "Game/Utils/Utils.hpp"
#include "Game/DataTables.hpp"
#include "GameEngine/Utils/DebugLog.hpp"
#include "GameEngine/Utils/UtilsFunctions.hpp"

#include "SFML/Graphics/RenderTarget.hpp"

#include <cmath>

std::unordered_map<UnitType, UnitData> unitData = initUnitData();

void Unit::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(mAnimationManager, states);
    CollidableNode::drawCurrent(target, states);
}

void Unit::updateCurrent(sf::Time dt) {
    sf::Vector2f velocity = Entity::getVelocity();

    AnimationType newAnimationType;
    if (velocity.x != 0 || velocity.y != 0) {
        newAnimationType = AnimationType::Walk;
    } else {
        newAnimationType = AnimationType::Idle;
    }

    DirectionType newDirectionType;
    newDirectionType = moveVelocityToAnimationDirection(velocity, mAnimationManager.getCurrentDirectionType());
    Entity::updateCurrent(dt);

    if (mAnimationManager.getCurrentAnimationType() != newAnimationType ||
        mAnimationManager.getCurrentDirectionType() != newDirectionType) {
        mAnimationManager.setAnimation(newAnimationType, newDirectionType);
//        setOriginToCenter(animation);
    }

    mAnimationManager.update(dt);
}

Unit::Unit(UnitType unitType, const TextureHolder& textures)
: Entity(unitData[unitType].baseSpeed)
, CollidableNode(unitData[unitType].collisionBoxSize)
, mUnitType(unitType)
, mAnimationManager(textures, unitData[unitType]) {
    setCollisionBoxOrigin(unitData[unitType].collisionBoxOrigin);
//    mAnimationManager.setAnimation(AnimationType::Idle, DirectionType::BottomRight);
//    setOriginToCenter(animation);
}

bool Unit::isCollidable() const {
    return true;
}

void Unit::onCollision(CollidableNode& collisionWith) {
    if (collisionWith.getSceneNodeCategory() & SceneNodeCategory::ImpassableZone) {
        sf::FloatRect collisionBox = getCollisionBoxRect();
        sf::FloatRect collisionWithBox = collisionWith.getCollisionBoxRect();

        sf::Vector2f collisionBoxCenter = sf::Vector2f(collisionBox.left + collisionBox.width / 2.f, collisionBox.top + collisionBox.height / 2.f);
        // rectangle of the closest points without collision (center if collisionBox must lies on this rectangle side)
        sf::FloatRect extendedCollisionWithBox = sf::FloatRect(collisionWithBox.left - collisionBox.width / 2.f,
                                                               collisionWithBox.top - collisionBox.height / 2.f,
                                                               collisionWithBox.width + collisionBox.width,
                                                               collisionWithBox.height + collisionBox.height);

        if (extendedCollisionWithBox.contains(collisionBoxCenter)) {
            sf::Vector2f rectPos = getRectPosition(extendedCollisionWithBox);
            sf::Vector2f rectSize = getRectSize(extendedCollisionWithBox);

            sf::Vector2f a = rectPos;
            sf::Vector2f b = rectPos; b.x += rectSize.x;
            sf::Vector2f c = rectPos + rectSize;
            sf::Vector2f d = rectPos; d.y += rectSize.y;

            sf::Vector2f reverseMoveDirection = getPreviousVelocity() * -1.f;
            sf::Vector2f intersectAt;
            sf::Vector2f intersectNormal;
            if (isRayIntersectSegment(collisionBoxCenter, reverseMoveDirection, a, b, intersectAt)) {
                intersectNormal = unitNormalVector(a, b);
            } else if (isRayIntersectSegment(collisionBoxCenter, reverseMoveDirection, b, c, intersectAt)) {
                intersectNormal = unitNormalVector(b, c);
            } else if (isRayIntersectSegment(collisionBoxCenter, reverseMoveDirection, c, d, intersectAt)) {
                intersectNormal = unitNormalVector(c, d);
            } else if (isRayIntersectSegment(collisionBoxCenter, reverseMoveDirection, d, a, intersectAt)) {
                intersectNormal = unitNormalVector(d, a);
            }

            sf::Vector2f moveVector = intersectAt - collisionBoxCenter;

            // leave only axis which move out from collided object
            moveVector.x *= fabsf(intersectNormal.x);
            moveVector.y *= fabsf(intersectNormal.y);

            move(moveVector);
        }
    }
}
