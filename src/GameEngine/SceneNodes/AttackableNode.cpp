#include "GameEngine/SceneNodes/AttackableNode.hpp"
#include "GameEngine/Utils/UtilsFunctions.hpp"

#ifndef NDEBUG
#include "SFML/Graphics/RenderTarget.hpp"

static const float SHAPE_OUTLINE_THICKNESS = 1.f;
static const sf::Color SHAPE_OUTLINE_COLOR = sf::Color(255, 0, 0, 150);
static const sf::Color SHAPE_FILL_COLOR = sf::Color(255, 0, 0, 50);
#endif

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
#ifndef NDEBUG
    mAttackCollisionBoxShape.setOutlineThickness(SHAPE_OUTLINE_THICKNESS);
    mAttackCollisionBoxShape.setOutlineColor(SHAPE_OUTLINE_COLOR);
    mAttackCollisionBoxShape.setFillColor(SHAPE_FILL_COLOR);
#endif
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

#ifndef NDEBUG
    mAttackCollisionBoxShape.setSize(sf::Vector2f(mAttackCollisionBox.width, mAttackCollisionBox.height));
    mAttackCollisionBoxShape.setPosition(sf::Vector2f(mAttackCollisionBox.left, mAttackCollisionBox.top));
#endif
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

#ifndef NDEBUG
void AttackableNode::drawAttackCollisionRec(sf::RenderTarget& target, sf::RenderStates states) const {
    if (mIsAttacking) {
        target.draw(mAttackCollisionBoxShape);
    }
}
#endif
