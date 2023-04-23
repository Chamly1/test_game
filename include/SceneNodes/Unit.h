#ifndef TEST_GAME_UNIT_H
#define TEST_GAME_UNIT_H

#include "SceneNodes/Entity.h"
#include "ResourceHolders/TextureHolder.h"
#include "AnimationManager.h"

class Unit : public Entity {
private:
    const TextureHolder& textures;
    UnitType unitType;
    Animation animation;
    AnimationType animationType;
    DirectionType directionType;

    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time dt);

public:
    explicit Unit(UnitType unitType, const TextureHolder& textures);

};

#endif //TEST_GAME_UNIT_H
