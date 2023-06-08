#ifndef TEST_GAME_ZOMBIENPC_HPP
#define TEST_GAME_ZOMBIENPC_HPP

#include "Game/SceneNodes/Unit.hpp"
#include "Game/AIs/ZombieAI.hpp"

class ZombieNPC : public Unit, public ZombieAI {
private:
    virtual void updateCurrent(sf::Time dt);

public:
    ZombieNPC(const TextureHolder& textures);

};

#endif //TEST_GAME_ZOMBIENPC_HPP
