#include "GameEngine/SceneNodes/AttackableNode.hpp"
#include "GameEngine/Utils/UtilsFunctions.hpp"

void AttackableNode::updateCurrent(sf::Time dt) {
    if (mIsAttacking) {
        mTimePastAfterAttack += dt;
        if (mTimePastAfterAttack >= mAttackDuration) {
            mIsAttacking = false;
//            dt = mTimePastAfterAttack - mAttackDuration;
            mTimePastAfterAttack = sf::Time::Zero;
        }
    }
}

AttackableNode::AttackableNode(sf::Time attackDuration, float attackCollisionBoxShift, const sf::Vector2f& attackCollisionBoxSize)
: mLookingDirection(DirectionType::BottomRight)
, mAttackDuration(attackDuration)
, mAttackCollisionBoxShift(attackCollisionBoxShift)
, mAttackCollisionBoxSize(attackCollisionBoxSize)
, mAttackCollisionBox()
, mTimePastAfterAttack(sf::Time::Zero)
, mIsAttacking(false) {

}

void AttackableNode::attack() {
    mIsAttacking = true;

    sf::Vector2f attackDirectionVector = directionTypeToVector(mLookingDirection);
    sf::Vector2f attackCollisionBoxPosition = attackDirectionVector * mAttackCollisionBoxShift + getPosition();
    sf::Vector2f attackCollisionBoxSize;
    attackCollisionBoxSize.x = mAttackCollisionBoxSize.x * attackDirectionVector.x;
    attackCollisionBoxSize.y = mAttackCollisionBoxSize.y * attackDirectionVector.y;

    mAttackCollisionBox.left = attackCollisionBoxPosition.x;
    mAttackCollisionBox.top = attackCollisionBoxPosition.y;
    mAttackCollisionBox.width = attackCollisionBoxSize.x;
    mAttackCollisionBox.height = attackCollisionBoxSize.y;
}

bool AttackableNode::isAttacking() const {
    return mIsAttacking;
}

void AttackableNode::setLookingDirection(DirectionType lookingDirection) {
    mLookingDirection = lookingDirection;
}

DirectionType AttackableNode::getLookingDirection() const {
    return mLookingDirection;
}
