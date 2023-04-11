#ifndef TEST_GAME_SPRITENODE_H
#define TEST_GAME_SPRITENODE_H

#include "SFML/Graphics.hpp"

#include "SceneNode.h"

class SpriteNode : public SceneNode {
private:
    sf::Sprite sprite;

    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    explicit SpriteNode(const sf::Texture& texture);

};

#endif //TEST_GAME_SPRITENODE_H
