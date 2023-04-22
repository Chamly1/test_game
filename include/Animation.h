#ifndef TEST_GAME_ANIMATION_H
#define TEST_GAME_ANIMATION_H

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Transformable.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/System/Time.hpp"

enum class DirectionType {
    BottomRight,
    BottomLeft,
    TopRight,
    TopLeft,
};

enum class AnimationType {
    Idle,
    Walk
};

class Animation : public sf::Drawable, public sf::Transformable {
private:
    sf::Sprite sprite;
    sf::IntRect firstFrame;
    int numFrames;
    int currentFrame;
    sf::Time frameDuration;
    sf::Time elapsedTime;
    bool repeat;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    Animation();
    explicit Animation(const sf::Texture& texture, sf::IntRect firstFrame, int numFrames, sf::Time frameDuration, bool repeat);
    void init(const sf::Texture& texture, sf::IntRect firstFrame, int numFrames, sf::Time frameDuration, bool repeat);
    void update(sf::Time dt);
    bool isFinished() const;
    sf::FloatRect getLocalBounds() const;

};

#endif //TEST_GAME_ANIMATION_H
