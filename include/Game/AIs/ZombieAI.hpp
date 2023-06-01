#ifndef TEST_GAME_ZOMBIEAI_HPP
#define TEST_GAME_ZOMBIEAI_HPP

#include "GameEngine/AI.hpp"

class ZombieAI : public AI {
private:

public:
    virtual bool checkCompatibilities(SceneNode& sceneNode);
    virtual void update(sf::Time dt, SceneNode& sceneNode);

};

#endif //TEST_GAME_ZOMBIEAI_HPP
