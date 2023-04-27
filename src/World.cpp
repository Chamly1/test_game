#include "World.h"
#include "SceneNodes/SpriteNode.h"
#include "SceneNodes/Unit.h"
#include "SceneNodes/CollidableNode.h"

const int TILE_SIZE = 8;
const int UNIT_SIZE = 32;
static const sf::Vector2f mapScaleFactor(4.f, 4.f);

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

    textures.load(TextureIdentifier::HumanBaseIdleAnimation,
                  "resources/textures/Minifantasy_Dungeon_Assets/Animations/Human/Minifantasy_CreaturesHumanBaseIdle.png");
    textures.load(TextureIdentifier::HumanBaseWalkAnimation,
                  "resources/textures/Minifantasy_Dungeon_Assets/Animations/Human/Minifantasy_CreaturesHumanBaseWalk.png");

    textures.load(TextureIdentifier::MapEmptyRoom,
                  "resources/textures/maps/empty_room/empty_room.png");
    textures.load(TextureIdentifier::MapImpassableZonesEmptyRoom,
                  "resources/textures/maps/empty_room/empty_room_impassable_zones.png");
}

void World::buildScene() {
    for (std::size_t i = 0; i < LayerCount; ++i) {
        std::unique_ptr<SceneNode> layer(new SceneNode);
        sceneLayers[i] = layer.get();

        sceneGraph.attachChild(std::move(layer));
    }

    std::unique_ptr<SpriteNode> mapBackground(new SpriteNode(textures.get(TextureIdentifier::MapEmptyRoom)));
    mapBackground->scale(mapScaleFactor);
    sceneLayers[Units]->attachChild(std::move(mapBackground));
//    sceneLayers[Background]->attachChild(std::move(generateMapFromString(testMapStr1, textures)));

    std::unique_ptr<Unit> player(new Unit(UnitType::Human, textures));
    player->addSceneNodeCategory(SceneNodeCategory::Player);
    sceneLayers[Units]->attachChild(std::move(player));

    std::unique_ptr<SceneNode> obstacle(new CollidableNode(sf::Vector2f(200.f, 200.f)));
    obstacle->setPosition(400.f, -400.f);
    obstacle->addSceneNodeCategory(SceneNodeCategory::ImpassableZone);
    sceneLayers[ImpassableZones]->attachChild(std::move(obstacle));

    obstacle = std::make_unique<CollidableNode>(sf::Vector2f(400.f, 100.f));
    obstacle->setPosition(400.f, -400.f);
    obstacle->addSceneNodeCategory(SceneNodeCategory::ImpassableZone);
    sceneLayers[ImpassableZones]->attachChild(std::move(obstacle));
}

World::World(sf::RenderWindow& window)
: window(window)
, worldView(window.getDefaultView())
, sceneGraph() {
    loadTextures();
    buildScene();

    worldView.setCenter(0.f, 0.f);
}

void World::update(sf::Time dt) {
    while (!commandQueue.isEmpty()) {
        sceneGraph.onCommand(commandQueue.pop(), dt);
    }

    sceneGraph.update(dt);

    std::set<std::pair<SceneNode*, SceneNode*>> collisionPairs;
    sceneGraph.checkAllCollisions(collisionPairs);
    for (std::pair<SceneNode*, SceneNode*> pair : collisionPairs) {
        pair.first->onCollision(*pair.second);
        pair.second->onCollision(*pair.first);
    }
}

void World::draw() {
    window.setView(worldView);
    window.draw(sceneGraph);
}

CommandQueue& World::getCommandQueue() {
    return commandQueue;
}
