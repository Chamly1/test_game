#include "Game/SceneNodes/NPCs/ZombieNPC.hpp"

void ZombieNPC::updateCurrent(sf::Time dt) {
    ZombieAI::update(dt, this);
    Unit::updateCurrent(dt);
}

void ZombieNPC::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
    Unit::drawCurrent(target, states);
#ifndef NDEBUG
    ZombieAI::drawVisionRay(target, this);
#endif
}

ZombieNPC::ZombieNPC(const TextureHolder& textures)
: Unit(UnitType::Zombie, textures) {

}
