#include "Game/World.hpp"
#include "Game/SceneNodes/SceneNodeCategory.hpp"
#include "GameEngine/SceneNodes/SpriteNode.hpp"
#include "Game/SceneNodes/Unit.hpp"
#include "GameEngine/SceneNodes/CollidableNode.hpp"
#include "Game/ResourceHolders/TextureIdentifier.hpp"
#include "Game/Utils/MapGenerateUtils.hpp"
#include "Game/SceneNodes/NPCs/ZombieNPC.hpp"

const int TILE_SIZE = 8;
const int UNIT_SIZE = 32;
static const sf::Vector2f mapScaleFactor(5.f, 5.f);

void World::loadTextures() {
    mTextures.load(TextureIdentifier::TileBlack, "resources/textures/BlackTile.png");

    std::string tilesFlorDungeonStr = "resources/textures/Minifantasy_Dungeon_Assets/Tileset/Minifantasy_DungeonFloorTiles.png";
    // load a 8x8 rectangle that starts at (0, 0)
    mTextures.load(TextureIdentifier::TileFlorDungeon, tilesFlorDungeonStr,
                   sf::IntRect(0, 0, TILE_SIZE, TILE_SIZE));

    std::string tilesWallDungeonStr = "resources/textures/Minifantasy_Dungeon_Assets/Tileset/Minifantasy_DungeonWallTiles.png";
    mTextures.load(TextureIdentifier::TileWallDungeonTopLeftCornerTopPart, tilesWallDungeonStr,
                   sf::IntRect(TILE_SIZE * 1, TILE_SIZE * 1, TILE_SIZE, TILE_SIZE));
    mTextures.load(TextureIdentifier::TileWallDungeonTopRightCornerTopPart, tilesWallDungeonStr,
                   sf::IntRect(TILE_SIZE * 3, TILE_SIZE * 1, TILE_SIZE, TILE_SIZE));

    mTextures.load(TextureIdentifier::TileWallDungeonBottomLeftCornerTopPart, tilesWallDungeonStr,
                   sf::IntRect(TILE_SIZE * 1, TILE_SIZE * 3, TILE_SIZE, TILE_SIZE));
    mTextures.load(TextureIdentifier::TileWallDungeonBottomLeftCornerBottomPart, tilesWallDungeonStr,
                   sf::IntRect(TILE_SIZE * 1, TILE_SIZE * 4, TILE_SIZE, TILE_SIZE));
    mTextures.load(TextureIdentifier::TileWallDungeonBottomRightCornerTopPart, tilesWallDungeonStr,
                   sf::IntRect(TILE_SIZE * 3, TILE_SIZE * 3, TILE_SIZE, TILE_SIZE));
    mTextures.load(TextureIdentifier::TileWallDungeonBottomRightCornerBottomPart, tilesWallDungeonStr,
                   sf::IntRect(TILE_SIZE * 3, TILE_SIZE * 4, TILE_SIZE, TILE_SIZE));

    mTextures.load(TextureIdentifier::TileWallDungeonMiddleTopPart, tilesWallDungeonStr,
                   sf::IntRect(TILE_SIZE * 2, TILE_SIZE * 1, TILE_SIZE, TILE_SIZE));
    mTextures.load(TextureIdentifier::TileWallDungeonMiddleBottomPart, tilesWallDungeonStr,
                   sf::IntRect(TILE_SIZE * 2, TILE_SIZE * 2, TILE_SIZE, TILE_SIZE));
    mTextures.load(TextureIdentifier::TileWallDungeonSidePart, tilesWallDungeonStr,
                   sf::IntRect(TILE_SIZE * 1, TILE_SIZE * 2, TILE_SIZE, TILE_SIZE));

    mTextures.load(TextureIdentifier::HumanBaseIdleAnimation,
                   "resources/textures/Minifantasy_Dungeon_Assets/Animations/Human/Minifantasy_CreaturesHumanBaseIdle.png");
    mTextures.load(TextureIdentifier::HumanBaseWalkAnimation,
                   "resources/textures/Minifantasy_Dungeon_Assets/Animations/Human/Minifantasy_CreaturesHumanBaseWalk.png");

    mTextures.load(TextureIdentifier::ZombieIdleAnimation,
                   "resources/textures/Minifantasy_Creatures_v3.0/Minifantasy_Creatures_Assets/Monsters/Zombie/Minifantasy_CreaturesZombieIdle_modified.png");
    mTextures.load(TextureIdentifier::ZombieWalkAnimation,
                   "resources/textures/Minifantasy_Creatures_v3.0/Minifantasy_Creatures_Assets/Monsters/Zombie/Minifantasy_CreaturesZombieWalk.png");

    mTextures.load(TextureIdentifier::MapEmptyRoom,
                   "resources/textures/maps/empty_room/empty_room.png");
    mTextures.load(TextureIdentifier::MapImpassableZonesEmptyRoom,
                   "resources/textures/maps/empty_room/empty_room_impassable_zones.png");
    mTextures.load(TextureIdentifier::MapNotEmptyRoom,
                   "resources/textures/maps/not_empty_room/not_empty_room.png");
    mTextures.load(TextureIdentifier::MapImpassableZonesNotEmptyRoom,
                   "resources/textures/maps/not_empty_room/not_empty_room_impassable_zones.png");
}

void World::buildScene() {
    for (std::size_t i = 0; i < Layer::LayerCount; ++i) {
        std::unique_ptr<SceneNode> layer(new SceneNode);
        mSceneLayers[i] = layer.get();

        mSceneGraph.attachChild(std::move(layer));
    }

//    std::unique_ptr<SpriteNode> mapBackground(new SpriteNode(mTextures.get(TextureIdentifier::MapEmptyRoom)));
    std::unique_ptr<SpriteNode> mapBackground(new SpriteNode(mTextures.get(TextureIdentifier::MapNotEmptyRoom)));
    mapBackground->scale(mapScaleFactor);
    mSceneLayers[Layer::Background]->attachChild(std::move(mapBackground));

    std::unique_ptr<Unit> player(new Unit(UnitType::Human, mTextures));
    mPlayerCamera.setPlayer(player.get());
    player->addSceneNodeCategory(SceneNodeCategory::Player);
    player->setPosition(100.f, 100.f);
    mSceneLayers[Layer::Units]->attachChild(std::move(player));

    std::unique_ptr<ZombieNPC> enemy(new ZombieNPC(mTextures));
    enemy->addSceneNodeCategory(SceneNodeCategory::EnemyUnit);
    enemy->setPosition(200.f, 100.f);
    mSceneLayers[Layer::Units]->attachChild(std::move(enemy));

//    mSceneLayers[ImpassableZones]->attachChild(generateImpassableZonesMap(mTextures.get(TextureIdentifier::MapImpassableZonesEmptyRoom),
//                                                                         sf::Color(255, 0, 0),
//                                                                         mapScaleFactor));
    mSceneLayers[ImpassableZones]->attachChild(generateImpassableZonesMap(mTextures.get(TextureIdentifier::MapImpassableZonesNotEmptyRoom),
                                                                          sf::Color(255, 0, 0),
                                                                          mapScaleFactor));
}

World::World(sf::RenderWindow& window)
: mWindow(window)
, mPlayerCamera(window.getDefaultView())
, mSceneGraph() {
    loadTextures();
    buildScene();

    mPlayerCamera.resetCenterToPlayer();
}

void World::update(sf::Time dt) {
    while (!mCommandQueue.isEmpty()) {
        mSceneGraph.onCommand(mCommandQueue.pop(), dt);
    }

    mSceneGraph.update(dt);

    std::set<std::pair<SceneNode*, SceneNode*>> collisionPairs;
    mSceneGraph.checkAllCollisions(collisionPairs);
    for (std::pair<SceneNode*, SceneNode*> pair : collisionPairs) {
        pair.first->onCollision(*pair.second);
        pair.second->onCollision(*pair.first);
    }

    mPlayerCamera.update(dt);
}

void World::draw() {
    mWindow.setView(mPlayerCamera.getView());
    mWindow.draw(mSceneGraph);
}

CommandQueue& World::getCommandQueue() {
    return mCommandQueue;
}
