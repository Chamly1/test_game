#ifndef TEST_GAME_NPC_HPP
#define TEST_GAME_NPC_HPP

#include "GameEngine/SceneNodes/SceneNode.hpp"
#include "GameEngine/AI.hpp"

class NPC {
private:
    std::unique_ptr<AI> mAi;

    virtual void update(sf::Time dt, SceneNode& npcSceneNode) = 0;
public:

};

#endif //TEST_GAME_NPC_HPP
