#include "GameEngine/SceneNodes/DamageableNode.hpp"

void DamageableNode::updateCurrent(sf::Time dt) {
    mTimePastAfterLastDamage += dt;
}

DamageableNode::DamageableNode(int maxHP, const sf::Vector2f& hitBoxSize, sf::Time afterDamageInvulnerabilityTime, sf::Time afterDamageUncontrolTime)
: mMaxHP(maxHP)
, mHitBoxSize(hitBoxSize)
, mAfterDamageInvulnerabilityTime(afterDamageInvulnerabilityTime)
, mAfterDamageUncontrolTime(afterDamageUncontrolTime)
, mHP(maxHP) {
    mTimePastAfterLastDamage = mAfterDamageInvulnerabilityTime + mAfterDamageUncontrolTime;
}

void DamageableNode::takeDamage(int damage) {
    if (mTimePastAfterLastDamage > mAfterDamageInvulnerabilityTime) {
        mHP -= damage;
        if (mHP < 0) {
            mHP = 0;
        }
        mTimePastAfterLastDamage = sf::Time::Zero;
    }
}

bool DamageableNode::isAfterDamageUncontroled() const {
    if (mTimePastAfterLastDamage <= mAfterDamageUncontrolTime) {
        return true;
    }
    return false;
}

sf::FloatRect DamageableNode::getHitBox() const {
    return sf::FloatRect(getPosition() - mHitBoxSize / 2.f, mHitBoxSize);
}
