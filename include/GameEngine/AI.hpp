#ifndef TEST_GAME_AI_HPP
#define TEST_GAME_AI_HPP

#include "GameEngine/SceneNodes/SceneNode.hpp"

#include "SFML/System/Time.hpp"

class AI {
private:

public:
    virtual void update(sf::Time dt, SceneNode& sceneNode) = 0;
};

#endif //TEST_GAME_AI_HPP
