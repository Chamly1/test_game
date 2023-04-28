#ifndef TEST_GAME_SPRITENODE_H
#define TEST_GAME_SPRITENODE_H

#include "GameEngine/SceneNodes/SceneNode.h"

#include "SFML/Graphics/Sprite.hpp"

class SpriteNode : public SceneNode {
private:
    sf::Sprite sprite;

    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    explicit SpriteNode(const sf::Texture& texture);

};

#endif //TEST_GAME_SPRITENODE_H
