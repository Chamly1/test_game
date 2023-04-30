#include "Game/World.h"
#include "Game/SceneNodes/SceneNodeCategory.h"
#include "GameEngine/SceneNodes/SpriteNode.h"
#include "Game/SceneNodes/Unit.h"
#include "GameEngine/SceneNodes/CollidableNode.h"
#include "Game/ResourceHolders/TextureIdentifier.h"
#include "Game/Utils/MapGenerateUtils.h"

const int TILE_SIZE = 8;
const int UNIT_SIZE = 32;
static const sf::Vector2f mapScaleFactor(5.f, 5.f);

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

    textures.load(TextureIdentifier::ZombieIdleAnimation,
                  "resources/textures/Minifantasy_Creatures_v3.0/Minifantasy_Creatures_Assets/Monsters/Zombie/Minifantasy_CreaturesZombieIdle_modified.png");
    textures.load(TextureIdentifier::ZombieWalkAnimation,
                  "resources/textures/Minifantasy_Creatures_v3.0/Minifantasy_Creatures_Assets/Monsters/Zombie/Minifantasy_CreaturesZombieWalk.png");

    textures.load(TextureIdentifier::MapEmptyRoom,
                  "resources/textures/maps/empty_room/empty_room.png");
    textures.load(TextureIdentifier::MapImpassableZonesEmptyRoom,
                  "resources/textures/maps/empty_room/empty_room_impassable_zones.png");
    textures.load(TextureIdentifier::MapNotEmptyRoom,
                  "resources/textures/maps/not_empty_room/not_empty_room.png");
    textures.load(TextureIdentifier::MapImpassableZonesNotEmptyRoom,
                  "resources/textures/maps/not_empty_room/not_empty_room_impassable_zones.png");
}

void World::buildScene() {
    for (std::size_t i = 0; i < LayerCount; ++i) {
        std::unique_ptr<SceneNode> layer(new SceneNode);
        sceneLayers[i] = layer.get();

        sceneGraph.attachChild(std::move(layer));
    }

//    std::unique_ptr<SpriteNode> mapBackground(new SpriteNode(textures.get(TextureIdentifier::MapEmptyRoom)));
    std::unique_ptr<SpriteNode> mapBackground(new SpriteNode(textures.get(TextureIdentifier::MapNotEmptyRoom)));
    mapBackground->scale(mapScaleFactor);
    sceneLayers[Background]->attachChild(std::move(mapBackground));

    std::unique_ptr<Unit> player(new Unit(UnitType::Human, textures));
    playerCamera.setPlayer(player.get());
    player->addSceneNodeCategory(SceneNodeCategory::Player);
    player->setPosition(100.f, 100.f);
    sceneLayers[Units]->attachChild(std::move(player));

//    sceneLayers[ImpassableZones]->attachChild(generateImpassableZonesMap(textures.get(TextureIdentifier::MapImpassableZonesEmptyRoom),
//                                                                         sf::Color(255, 0, 0),
//                                                                         mapScaleFactor));
    sceneLayers[ImpassableZones]->attachChild(generateImpassableZonesMap(textures.get(TextureIdentifier::MapImpassableZonesNotEmptyRoom),
                                                                         sf::Color(255, 0, 0),
                                                                         mapScaleFactor));
}

World::World(sf::RenderWindow& window)
: window(window)
, playerCamera(window.getDefaultView())
, sceneGraph() {
    loadTextures();
    buildScene();

    playerCamera.resetCenterToPlayer();
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

    playerCamera.update(dt);
}

void World::draw() {
    window.setView(playerCamera.getView());
    window.draw(sceneGraph);
}

CommandQueue& World::getCommandQueue() {
    return commandQueue;
}
