#ifndef TEST_GAME_DAMAGEABLENODE_HPP
#define TEST_GAME_DAMAGEABLENODE_HPP

#include "GameEngine/SceneNodes/SceneNode.hpp"

class DamageableNode : virtual public SceneNode {
private:
    const int mMaxHP;
    const sf::Time mAfterDamageInvulnerabilityTime;
    const sf::Time mAfterDamageUncontrolTime;
    int mHP;
    sf::Time mTimePastAfterLastDamage;

protected:
    virtual void updateCurrent(sf::Time dt);

public:
    DamageableNode(int maxHP, sf::Time afterDamageInvulnerabilityTime, sf::Time afterDamageUncontrolTime);
    void takeDamage(int damage);
    bool isAfterDamageUncontroled() const;

};

#endif //TEST_GAME_DAMAGEABLENODE_HPP
