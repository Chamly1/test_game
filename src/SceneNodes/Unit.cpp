#include "SceneNodes/Unit.h"

#include "SFML/Graphics/RenderTarget.hpp"

TextureIdentifier toTextureID (UnitType type) {
    switch (type) {
        case UnitType::Human:
            return TextureIdentifier::HumanBaseIdle;
        case UnitType::zombie:
            return TextureIdentifier::zombie;
    }
    return TextureIdentifier::zombie;
}

Unit::Unit(UnitType type, const TextureHolder& textures)
: type(type)
, sprite(textures.get(toTextureID(type))) {
    sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Unit::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}
