#ifndef TEST_GAME_COMMAND_H
#define TEST_GAME_COMMAND_H

#include "SFML/System/Time.hpp"

#include <functional>

class SceneNode;

class Command {
public:
    std::function<void(SceneNode&, sf::Time)> action;
    unsigned int sceneNodeCategory;
};

#endif //TEST_GAME_COMMAND_H
