#ifndef TEST_GAME_UNIT_H
#define TEST_GAME_UNIT_H

#include "SceneNodes/Entity.h"
#include "ResourceHolders/TextureHolder.h"
#include "AnimationManager.h"

class Unit : public Entity {
private:
    UnitType unitType;
    AnimationManager animationManager;

    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time dt);

public:
    explicit Unit(UnitType unitType, const TextureHolder& textures);

};

#endif //TEST_GAME_UNIT_H
