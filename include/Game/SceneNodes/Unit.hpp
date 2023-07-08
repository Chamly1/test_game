#ifndef TEST_GAME_UNIT_HPP
#define TEST_GAME_UNIT_HPP

#include "GameEngine/SceneNodes/MovableNode.hpp"
#include "GameEngine/ResourceHolders/TextureHolder.hpp"
#include "Game/AnimationManager.hpp"
#include "GameEngine/SceneNodes/CollidableNode.hpp"

enum class UnitAction {
    Attack
};

/**
 * Class to control the Unit through the Command class.
 */
class UnitController {
private:
    UnitAction mUnitAction;

public:
    UnitController(UnitAction unitAction);
    void operator() (SceneNode& node, sf::Time dt) const;
};

class Unit : public MovableNode, public CollidableNode {
private:
    UnitType mUnitType;
    AnimationManager mAnimationManager;

    void moveUnitWithCollisionResolving(sf::Time dt);

protected:
    virtual void updateCurrent(sf::Time dt);
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    explicit Unit(UnitType unitType, const TextureHolder& textures);
    virtual void onCollision(CollidableNode& collisionWith);
};

#endif //TEST_GAME_UNIT_HPP
