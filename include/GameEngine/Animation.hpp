#ifndef TEST_GAME_ANIMATION_HPP
#define TEST_GAME_ANIMATION_HPP

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Transformable.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/System/Time.hpp"

class Animation : public sf::Drawable, public sf::Transformable {
private:
    sf::Sprite mSprite;
    sf::IntRect mFirstFrame;
    int mNumFrames;
    int mCurrentFrame;
    sf::Time mFrameDuration;
    sf::Time mElapsedTime;
    bool mRepeat;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    Animation();
    explicit Animation(const sf::Texture& texture, sf::IntRect firstFrame, int numFrames, sf::Time frameDuration, bool repeat);
    void init(const sf::Texture& texture, sf::IntRect firstFrame, int numFrames, sf::Time frameDuration, bool repeat);
    void update(sf::Time dt);
    bool isFinished() const;
    sf::FloatRect getLocalBounds() const;

};

#endif //TEST_GAME_ANIMATION_HPP
