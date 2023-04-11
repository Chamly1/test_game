#include "Entities/Unit.h"

TextureIdentifier toTextureID (UnitType type) {
    switch (type) {
        case UnitType::zombie:
            return TextureIdentifier::zombie;
    }
}

Unit::Unit(UnitType type, const TextureHolder& textures) :
type(type), sprite(textures.get(toTextureID(type))) {
    sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Unit::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}
