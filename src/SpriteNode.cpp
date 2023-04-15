#include "SpriteNode.h"

#include "SFML/Graphics/RenderTarget.hpp"

void SpriteNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

SpriteNode::SpriteNode(const sf::Texture& texture) : sprite(texture) {

}
