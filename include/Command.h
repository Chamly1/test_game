#ifndef TEST_GAME_COMMAND_H
#define TEST_GAME_COMMAND_H

#include <functional>

#include "SFML/Graphics.hpp"

class SceneNode;

class Command {
public:
    std::function<void(SceneNode&, sf::Time)> action;
    unsigned int sceneNodeCategory;
};

#endif //TEST_GAME_COMMAND_H
