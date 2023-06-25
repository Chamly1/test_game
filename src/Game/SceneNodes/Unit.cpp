#include "Game/SceneNodes/Unit.hpp"
#include "Game/SceneNodes/SceneNodeCategory.hpp"
#include "Game/Utils/Utils.hpp"
#include "Game/DataTables.hpp"
#include "GameEngine/Utils/DebugLog.hpp"

#include "SFML/Graphics/RenderTarget.hpp"

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
        sf::FloatRect intersection;
        sf::FloatRect collisionBox = getCollisionBoxRect();
        collisionBox.intersects(collisionWith.getCollisionBoxRect(), intersection);

        sf::Vector2f moveOffset;

        if (collisionBox.top == intersection.top &&
            collisionBox.left == intersection.left) {
            if (intersection.width > intersection.height) {
                moveOffset.x = 0.f;
                moveOffset.y = intersection.height;
            } else {
                moveOffset.x = intersection.width;
                moveOffset.y = 0.f;
            }

        } else if (collisionBox.top == intersection.top) {
            if (intersection.width > intersection.height) {
                moveOffset.x = 0.f;
                moveOffset.y = intersection.height;
            } else {
                moveOffset.x = 0.f - intersection.width;
                moveOffset.y = 0.f;
            }

        } else if (collisionBox.left == intersection.left) {
            if (intersection.width > intersection.height) {
                moveOffset.x = 0.f;
                moveOffset.y = 0.f - intersection.height;
            } else {
                moveOffset.x = intersection.width;
                moveOffset.y = 0.f;
            }

        } else {
            // to fix leap on the top left edge
            if (intersection.width > intersection.height) {
                moveOffset.x = 0.f;
                moveOffset.y = 0.f - intersection.height;
            } else {
                moveOffset.x = 0.f - intersection.width;
                moveOffset.y = 0.f;
            }
        }

        move( moveOffset);
    }
}
