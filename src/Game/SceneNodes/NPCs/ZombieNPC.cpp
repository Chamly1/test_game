#include "Game/SceneNodes/NPCs/ZombieNPC.hpp"

void ZombieNPC::updateCurrent(sf::Time dt) {
    ZombieAI::update(dt, this);
    Unit::updateCurrent(dt);
}

ZombieNPC::ZombieNPC(const TextureHolder& textures)
: Unit(UnitType::Zombie, textures) {

}
