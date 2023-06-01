#ifndef TEST_GAME_SPRITENODE_HPP
#define TEST_GAME_SPRITENODE_HPP

#include "GameEngine/SceneNodes/SceneNode.hpp"

#include "SFML/Graphics/Sprite.hpp"

class SpriteNode : public SceneNode {
private:
    sf::Sprite mSprite;

    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    explicit SpriteNode(const sf::Texture& texture);

};

#endif //TEST_GAME_SPRITENODE_HPP
