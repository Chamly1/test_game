#ifndef TEST_GAME_UNIT_HPP
#define TEST_GAME_UNIT_HPP

#include "Entity.hpp"
#include "GameEngine/ResourceHolders/TextureHolder.hpp"
#include "Game/AnimationManager.hpp"

class Unit : public Entity {
private:
    UnitType mUnitType;
    AnimationManager mAnimationManager;

protected:
    virtual void updateCurrent(sf::Time dt);
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    explicit Unit(UnitType unitType, const TextureHolder& textures);
    virtual bool isCollidable() const;
    virtual void onCollision(SceneNode& collisionWith);
};

#endif //TEST_GAME_UNIT_HPP
