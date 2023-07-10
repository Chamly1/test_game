#include "GameEngine/SceneNodes/DamageableNode.hpp"

void DamageableNode::updateCurrent(sf::Time dt) {
    mTimePastAfterLastDamage += dt;
}

DamageableNode::DamageableNode(int maxHP, sf::Time afterDamageInvulnerabilityTime, sf::Time afterDamageUncontrolTime)
: mMaxHP(maxHP)
, mAfterDamageInvulnerabilityTime(afterDamageInvulnerabilityTime)
, mAfterDamageUncontrolTime(afterDamageUncontrolTime)
, mHP(maxHP) {
    mTimePastAfterLastDamage = mAfterDamageInvulnerabilityTime + mAfterDamageUncontrolTime;
}

void DamageableNode::takeDamage(int damage) {
    if (mTimePastAfterLastDamage > mAfterDamageInvulnerabilityTime) {
        mHP -= damage;
        mTimePastAfterLastDamage = sf::Time::Zero;
    }
}

bool DamageableNode::isAfterDamageUncontroled() const {
    if (mTimePastAfterLastDamage <= mAfterDamageUncontrolTime) {
        return true;
    }
    return false;
}
