#include "SceneNodes/Unit.h"
#include "Utils/Utils.h"
#include "DataTables.h"

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
