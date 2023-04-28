#ifndef TEST_GAME_UNIT_H
#define TEST_GAME_UNIT_H

#include "Entity.h"
#include "GameEngine/ResourceHolders/TextureHolder.h"
#include "Game/AnimationManager.h"

class Unit : public Entity {
private:
    UnitType unitType;
    AnimationManager animationManager;

    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void updateCurrent(sf::Time dt);

public:
    explicit Unit(UnitType unitType, const TextureHolder& textures);
    virtual bool isCollidable() const;
    virtual void onCollision(SceneNode& collisionWith);
};

#endif //TEST_GAME_UNIT_H
