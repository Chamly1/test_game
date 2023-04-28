#include "GameEngine/ResourceHolders/TextureHolder.h"

#include <stdexcept>
#include <cassert>

void TextureHolder::load(unsigned int id, const std::string& filePath, const sf::IntRect& area) {
    std::unique_ptr<sf::Texture> texture(new sf::Texture);
    if (!texture->loadFromFile(filePath, area)) {
        throw std::runtime_error("TextureHolder::load - Failed to load " + filePath);
    }

    auto inserted = textureMap.insert(std::make_pair(id, std::move(texture)));
    assert(inserted.second);
}

const sf::Texture& TextureHolder::get(unsigned int id) const {
    auto found = textureMap.find(id);
    assert(found != textureMap.end());

    return *found->second;
}
