#include "ResourceHolders/TextureHolder.h"

void TextureHolder::load(TextureIdentifier id, const std::string& filePath) {
    std::unique_ptr<sf::Texture> texture(new sf::Texture);
    if (!texture->loadFromFile(filePath)) {
        throw std::runtime_error("TextureHolder::load - Failed to load " + filePath);
    }

    auto inserted = textureMap.insert(std::make_pair(id, std::move(texture)));
    assert(inserted.second);
}

const sf::Texture& TextureHolder::get(TextureIdentifier id) const {
    auto found = textureMap.find(id);
    assert(found != textureMap.end());

    return *found->second;
}
