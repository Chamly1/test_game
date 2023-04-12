#ifndef TEST_GAME_TEXTUREHOLDER_H
#define TEST_GAME_TEXTUREHOLDER_H

#include <map>
#include <memory>
#include <cassert>

#include "SFML/Graphics.hpp"

enum class TextureIdentifier {
    TileBlack,
    TileFlorDungeon,
    zombie
};

class TextureHolder {
private:
    std::map<TextureIdentifier, std::unique_ptr<sf::Texture>> textureMap;

public:
    void load(TextureIdentifier id, const std::string& filePath, const sf::IntRect& area = sf::IntRect());
    const sf::Texture& get(TextureIdentifier id) const;
};

#endif //TEST_GAME_TEXTUREHOLDER_H
