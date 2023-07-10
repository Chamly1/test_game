#ifndef TEST_GAME_ATTACKABLENODE_HPP
#define TEST_GAME_ATTACKABLENODE_HPP

#include "GameEngine/SceneNodes/SceneNode.hpp"
#include "GameEngine/DirectionType.hpp"

#ifndef NDEBUG
#include "SFML/Graphics/RectangleShape.hpp"
#endif

class AttackableNode : virtual public SceneNode {
private:
    DirectionType mLookingDirection;
    unsigned int mEnemySceneNodeCategories;

    const sf::Time mAttackDuration;
    const float mAttackCollisionBoxShift;
    const sf::Vector2f mAttackCollisionBoxSize;
    sf::FloatRect mAttackCollisionBox;
    sf::Time mTimePastAfterAttack;
    bool mIsAttacking;

#ifndef NDEBUG
    sf::RectangleShape mAttackCollisionBoxShape;
#endif

protected:
    virtual void updateCurrent(sf::Time dt);

public:
    AttackableNode(sf::Time attackDuration, float attackCollisionBoxShift, const sf::Vector2f& attackCollisionBoxSize);
    void attack();
    bool isAttacking() const;
    void setLookingDirection(DirectionType lookingDirection);
    DirectionType getLookingDirection() const;
    void endAttack();
    void addEnemy(unsigned int enemySceneNodeCategory);

#ifndef NDEBUG
    void drawAttackCollisionRec(sf::RenderTarget& target, sf::RenderStates states) const;
#endif
};

#endif //TEST_GAME_ATTACKABLENODE_HPP
