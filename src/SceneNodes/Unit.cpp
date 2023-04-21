#include "SceneNodes/Unit.h"
#include "Utils/Utils.h"

#include "SFML/Graphics/RenderTarget.hpp"

TextureIdentifier toTextureID (UnitType type) {
    switch (type) {
        case UnitType::Human:
            return TextureIdentifier::HumanBaseIdleAnimation;
        case UnitType::zombie:
            return TextureIdentifier::zombie;
    }
    return TextureIdentifier::zombie;
}

void Unit::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(animation, states);
}

void Unit::updateCurrent(sf::Time dt) {
    Entity::updateCurrent(dt);
    animation.update(dt);
}

Unit::Unit(UnitType type, const TextureHolder& textures)
        : type(type)
//, sprite(textures.get(toTextureID(type))) {
        , animation() {
    animation.init(textures.get(TextureIdentifier::HumanBaseIdleAnimation), sf::Vector2i(32, 32), 16, sf::milliseconds(400), true);
    setOriginToCenter(animation);
}
