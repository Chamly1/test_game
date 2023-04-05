#ifndef TEST_GAME_TEXTUREHOLDER_H
#define TEST_GAME_TEXTUREHOLDER_H

#include <map>
#include <memory>
#include <cassert>

#include "SFML/Graphics.hpp"

enum class TextureIdentifier {

};

class TextureHolder {
private:
    std::map<TextureIdentifier, std::unique_ptr<sf::Texture>> textureMap;

public:
    void load(TextureIdentifier id, const std::string& filePath);
    sf::Texture& get(TextureIdentifier id);
};

#endif //TEST_GAME_TEXTUREHOLDER_H
