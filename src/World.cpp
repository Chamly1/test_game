#include "World.h"
#include "SpriteNode.h"
#include "MapGenerateUtils.h"

const float viewZoomFactor = 0.25f;

void World::loadTextures() {
    textures.load(TextureIdentifier::TileBlack, "resources/textures/BlackTile.png");
    // load a 8x8 rectangle that starts at (0, 0)
    textures.load(TextureIdentifier::TileFlorDungeon,
                  "resources/textures/Minifantasy_Dungeon_Assets/Tileset/Minifantasy_DungeonFloorTiles.png",
                  sf::IntRect(0, 0, 8, 8));
}

void World::buildScene() {
    for (std::size_t i = 0; i < LayerCount; ++i) {
        std::unique_ptr<SceneNode> layer(new SceneNode);
        sceneLayers[i] = layer.get();

        sceneGraph.attachChild(std::move(layer));
    }

    sceneLayers[Background]->attachChild(std::move(generateMapFromString(testMapStr1, textures)));

}

World::World(sf::RenderWindow& window)
: window(window)
, worldView(window.getDefaultView())
, sceneGraph() {
    loadTextures();
    buildScene();

    worldView.zoom(viewZoomFactor);
    worldView.setCenter(0.f, 0.f);
}

void World::update(sf::Time dt) {

}

void World::draw() {
    window.setView(worldView);
    window.draw(sceneGraph);
}
