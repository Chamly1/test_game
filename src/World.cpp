#include "World.h"

void World::loadTextures() {

}

void World::buildScene() {

}

World::World(sf::RenderWindow& window) : window(window), worldView(window.getDefaultView()) {
    loadTextures();
    buildScene();
}
