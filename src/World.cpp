#include "World.h"
#include "SpriteNode.h"
#include "MapGenerateUtils.h"

const float viewZoomFactor = 0.25f;
const int TILE_SIZE = 8;

void World::loadTextures() {
    textures.load(TextureIdentifier::TileBlack, "resources/textures/BlackTile.png");

    std::string tilesFlorDungeonStr = "resources/textures/Minifantasy_Dungeon_Assets/Tileset/Minifantasy_DungeonFloorTiles.png";
    // load a 8x8 rectangle that starts at (0, 0)
    textures.load(TextureIdentifier::TileFlorDungeon, tilesFlorDungeonStr,
                  sf::IntRect(0, 0, TILE_SIZE, TILE_SIZE));

    std::string tilesWallDungeonStr = "resources/textures/Minifantasy_Dungeon_Assets/Tileset/Minifantasy_DungeonWallTiles.png";
    textures.load(TextureIdentifier::TileWallDungeonTopLeftCornerTopPart, tilesWallDungeonStr,
                  sf::IntRect(TILE_SIZE * 1, TILE_SIZE * 1, TILE_SIZE, TILE_SIZE));
    textures.load(TextureIdentifier::TileWallDungeonTopRightCornerTopPart, tilesWallDungeonStr,
                  sf::IntRect(TILE_SIZE * 3, TILE_SIZE * 1, TILE_SIZE, TILE_SIZE));

    textures.load(TextureIdentifier::TileWallDungeonBottomLeftCornerTopPart, tilesWallDungeonStr,
                  sf::IntRect(TILE_SIZE * 1, TILE_SIZE * 3, TILE_SIZE, TILE_SIZE));
    textures.load(TextureIdentifier::TileWallDungeonBottomLeftCornerBottomPart, tilesWallDungeonStr,
                  sf::IntRect(TILE_SIZE * 1, TILE_SIZE * 4, TILE_SIZE, TILE_SIZE));
    textures.load(TextureIdentifier::TileWallDungeonBottomRightCornerTopPart, tilesWallDungeonStr,
                  sf::IntRect(TILE_SIZE * 3, TILE_SIZE * 3, TILE_SIZE, TILE_SIZE));
    textures.load(TextureIdentifier::TileWallDungeonBottomRightCornerBottomPart, tilesWallDungeonStr,
                  sf::IntRect(TILE_SIZE * 3, TILE_SIZE * 4, TILE_SIZE, TILE_SIZE));

    textures.load(TextureIdentifier::TileWallDungeonMiddleTopPart, tilesWallDungeonStr,
                  sf::IntRect(TILE_SIZE * 2, TILE_SIZE * 1, TILE_SIZE, TILE_SIZE));
    textures.load(TextureIdentifier::TileWallDungeonMiddleBottomPart, tilesWallDungeonStr,
                  sf::IntRect(TILE_SIZE * 2, TILE_SIZE * 2, TILE_SIZE, TILE_SIZE));
    textures.load(TextureIdentifier::TileWallDungeonSidePart, tilesWallDungeonStr,
                  sf::IntRect(TILE_SIZE * 1, TILE_SIZE * 2, TILE_SIZE, TILE_SIZE));
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
    while (!commandQueue.isEmpty()) {
        sceneGraph.onCommand(commandQueue.pop(), dt);
    }

    sceneGraph.update(dt);
}

void World::draw() {
    window.setView(worldView);
    window.draw(sceneGraph);
}

CommandQueue& World::getCommandQueue() {
    return commandQueue;
}
