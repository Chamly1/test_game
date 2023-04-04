#ifndef TEST_GAME_FONTHOLDER_H
#define TEST_GAME_FONTHOLDER_H

#include <map>
#include <memory>
#include <cassert>

#include "SFML/Graphics.hpp"

enum class FontIdentifier{

};

class FontHolder {
private:
    std::map<FontIdentifier, std::unique_ptr<sf::Font>> fontMap;

public:
    void load(FontIdentifier id, const std::string& filePath);
    sf::Font& get(FontIdentifier id);
};

#endif //TEST_GAME_FONTHOLDER_H
