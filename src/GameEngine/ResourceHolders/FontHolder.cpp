#include "GameEngine/ResourceHolders/FontHolder.hpp"

#include <stdexcept>
#include <cassert>

void FontHolder::load(unsigned int id, const std::string& filePath) {
    std::unique_ptr<sf::Font> font(new sf::Font());
    if (!font->loadFromFile(filePath)) {
        throw std::runtime_error("FontHolder::load - Failed to load " + filePath);
    }

    auto inserted = fontMap.insert(std::make_pair(id, std::move(font)));
    assert(inserted.second);
}

sf::Font& FontHolder::get(unsigned int id) {
    auto found = fontMap.find(id);
    assert(found != fontMap.end());

    return *found->second;
}
