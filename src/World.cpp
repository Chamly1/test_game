#include "World.h"
#include "SpriteNode.h"

void World::loadTextures() {
    textures.load(TextureIdentifier::TileFlorDungeon, "resources/textures/Minifantasy_Dungeon_Assets/Tileset/Minifantasy_DungeonFloorTiles.png");
}

void World::buildScene() {
    for (std::size_t i = 0; i < LayerCount; ++i) {
        std::unique_ptr<SceneNode> layer(new SceneNode);
        sceneLayers[i] = layer.get();

        sceneGraph.attachChild(std::move(layer));
    }

    std::unique_ptr<SpriteNode> florSprite(new SpriteNode(textures.get(TextureIdentifier::TileFlorDungeon)));
    sceneLayers[Background]->attachChild(std::move(florSprite));
}

World::World(sf::RenderWindow& window) : window(window), worldView(window.getDefaultView()), sceneGraph() {
    loadTextures();
    buildScene();
}

void World::update(sf::Time dt) {

}

void World::draw() {
    window.setView(worldView);
    window.draw(sceneGraph);
}
