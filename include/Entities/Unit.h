#ifndef TEST_GAME_UNIT_H
#define TEST_GAME_UNIT_H

#include "Entities/Entity.h"
#include "ResourceHolders/TextureHolder.h"

#include "SFML/Graphics/Sprite.hpp"

enum class UnitType {
    Human,
    zombie
};

class Unit : public Entity {
private:
    UnitType type;
    sf::Sprite sprite;

public:
    explicit Unit(UnitType type, const TextureHolder& textures);
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

};

#endif //TEST_GAME_UNIT_H
