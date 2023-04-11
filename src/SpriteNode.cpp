#include "SpriteNode.h"

void SpriteNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

SpriteNode::SpriteNode(const sf::Texture& texture) : sprite(texture) {

}
