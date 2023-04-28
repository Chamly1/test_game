#ifndef TEST_GAME_ANIMATIONMANAGER_H
#define TEST_GAME_ANIMATIONMANAGER_H

#include "GameEngine/Animation.h"
#include "DataTables.h"

#include <memory>

/**
 * A class to store all animations for a certain entity.
 */
class AnimationManager : public sf::Drawable {
private:
    std::shared_ptr<Animation> currentAnimation;
    AnimationType currentAnimationType;
    DirectionType currentDirectionType;
    std::unordered_map<AnimationType, std::unordered_map<DirectionType, std::shared_ptr<Animation>>> animations;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    /**
     * Constructor which load all animations from the unitData. unitData MUST contain at least one animation.
     * Set first animation.
     *
     * @param textures TextureHolder which MUST contain all necessary textures for all animations from the unitData.
     * @param unitData contain all animations for a certain entity
     */
    AnimationManager(const TextureHolder& textures, UnitData& unitData);
    /**
     * Add certain animation.
     *
     * @param textures TextureHolder which MUST contain a necessary texture for a animation.
     * @param unitData UnitData which MUST contain a necessary data about requested animation.
     * @param animationType requested animation type.
     * @param directionType requested animation direction tag.
     */
    void addAnimation(const TextureHolder& textures, UnitData& unitData, AnimationType animationType,
                      DirectionType directionType);
    /**
     * Set the animation to be drawn when sf::RenderTarget.draw() called.
     *
     * @param animationType requested animation type.
     * @param directionType requested animation direction tag.
     */
    void setAnimation(AnimationType animationType, DirectionType directionType);
    /**
     * Update the currently selected animation.
     *
     * @param dt delta time.
     */
    void update(sf::Time dt);
    /**
     * Return the animation type of the currently selected animation.
     *
     * @return the animation type of the currently selected animation.
     */
    AnimationType getCurrentAnimationType() const;
    /**
     * Return the animation direction tag of the currently selected animation.
     *
     * @return the animation direction tag of the currently selected animation.
     */
    DirectionType getCurrentDirectionType() const;

};

#endif //TEST_GAME_ANIMATIONMANAGER_H
