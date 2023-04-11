#ifndef TEST_GAME_UNIT_H
#define TEST_GAME_UNIT_H

#include "Entity.h"
#include "ResourceHolders/TextureHolder.h"

enum class UnitType {
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
