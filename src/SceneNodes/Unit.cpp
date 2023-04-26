#include "SceneNodes/Unit.h"
#include "Utils/Utils.h"
#include "DataTables.h"
#include "Utils/DebugLog.h"

#include "SFML/Graphics/RenderTarget.hpp"

std::unordered_map<UnitType, UnitData> unitData = initUnitData();

void Unit::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(animationManager, states);
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
    newDirectionType = moveVelocityToAnimationDirection(velocity, animationManager.getCurrentDirectionType());
    Entity::updateCurrent(dt);

    if (animationManager.getCurrentAnimationType() != newAnimationType ||
        animationManager.getCurrentDirectionType() != newDirectionType) {
        animationManager.setAnimation(newAnimationType, newDirectionType);
//        setOriginToCenter(animation);
    }

    animationManager.update(dt);
}

Unit::Unit(UnitType unitType, const TextureHolder& textures)
: Entity(75.f)
, unitType(unitType)
, animationManager(textures, unitData[unitType]) {
    setCollisionBoxSize(unitData[unitType].collisionBoxSize);
//    animationManager.setAnimation(AnimationType::Idle, DirectionType::BottomRight);
//    setOriginToCenter(animation);
}

bool Unit::isCollidable() const {
    return true;
}

void Unit::onCollision(SceneNode& collisionWith) {
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
