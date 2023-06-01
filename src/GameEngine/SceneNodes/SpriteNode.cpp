#include "GameEngine/SceneNodes/SpriteNode.hpp"

#include "SFML/Graphics/RenderTarget.hpp"

void SpriteNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(mSprite, states);
}

SpriteNode::SpriteNode(const sf::Texture& texture) : mSprite(texture) {

}
