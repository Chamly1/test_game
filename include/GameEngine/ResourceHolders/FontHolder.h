#ifndef TEST_GAME_FONTHOLDER_H
#define TEST_GAME_FONTHOLDER_H

#include "SFML/Graphics/Font.hpp"

#include <map>
#include <memory>

class FontHolder {
private:
    std::map<unsigned int, std::unique_ptr<sf::Font>> fontMap;

public:
    void load(unsigned int id, const std::string& filePath);
    sf::Font& get(unsigned int id);
};

#endif //TEST_GAME_FONTHOLDER_H
