#ifndef TEST_GAME_TEXTUREHOLDER_HPP
#define TEST_GAME_TEXTUREHOLDER_HPP

#include "SFML/Graphics/Texture.hpp"

#include <map>
#include <memory>

class TextureHolder {
private:
    std::map<unsigned int, std::unique_ptr<sf::Texture>> textureMap;

public:
    void load(unsigned int id, const std::string& filePath, const sf::IntRect& area = sf::IntRect());
    const sf::Texture& get(unsigned int id) const;
};

#endif //TEST_GAME_TEXTUREHOLDER_HPP
