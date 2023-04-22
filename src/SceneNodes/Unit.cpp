#include "SceneNodes/Unit.h"
#include "Utils/Utils.h"
#include "DataTables.h"

#include "SFML/Graphics/RenderTarget.hpp"

std::unordered_map<UnitType, UnitData> unitData = initUnitData();

void Unit::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(animation, states);
}

void Unit::updateCurrent(sf::Time dt) {
    sf::Vector2f velocity = Entity::getVelocity();

    AnimationType oldAnimationType = animationType;

    DirectionType oldDirectionType = directionType;
    directionType = moveVelocityToAnimationDirection(velocity, directionType);
    Entity::updateCurrent(dt);

    if (oldAnimationType != animationType || oldDirectionType != directionType) {
        animation = createAnimation(textures, unitData[unitType], animationType, directionType);
        setOriginToCenter(animation);
    }

    animation.update(dt);
}

Unit::Unit(UnitType unitType, const TextureHolder& textures)
: Entity(75.f)
, textures(textures)
, unitType(unitType)
//, sprite(textures.get(toTextureID(type))) {
, animation()
, animationType(AnimationType::Idle)
, directionType(DirectionType::BottomRight) {
    animation = createAnimation(textures, unitData[unitType], animationType, directionType);
    setOriginToCenter(animation);
}
