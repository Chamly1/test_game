#include "Game/World.hpp"
#include "Game/SceneNodes/SceneNodeCategory.hpp"
#include "GameEngine/SceneNodes/SpriteNode.hpp"
#include "Game/SceneNodes/Unit.hpp"
#include "GameEngine/SceneNodes/CollidableNode.hpp"
#include "Game/ResourceHolders/TextureIdentifier.hpp"
#include "Game/Utils/MapGenerateUtils.hpp"
#include "Game/SceneNodes/NPCs/ZombieNPC.hpp"
#include "GameEngine/Utils/SceneNodeUtils.hpp"

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
    mTextures.load(TextureIdentifier::HumanBaseAttackAnimation,
                   "resources/textures/Minifantasy_Dungeon_Assets/Animations/Human/Minifantasy_CreaturesHumanBaseAttack.png");

    mTextures.load(TextureIdentifier::ZombieIdleAnimation,
                   "resources/textures/Minifantasy_Creatures_v3.0/Minifantasy_Creatures_Assets/Monsters/Zombie/Minifantasy_CreaturesZombieIdle_modified.png");
    mTextures.load(TextureIdentifier::ZombieWalkAnimation,
                   "resources/textures/Minifantasy_Creatures_v3.0/Minifantasy_Creatures_Assets/Monsters/Zombie/Minifantasy_CreaturesZombieWalk.png");
    mTextures.load(TextureIdentifier::ZombieDamageAnimation,
                   "resources/textures/Minifantasy_Creatures_v3.0/Minifantasy_Creatures_Assets/Monsters/Zombie/Minifantasy_CreaturesZombieDmg.png");

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
    player->addEnemy(SceneNodeCategory::EnemyUnit);
    mSceneLayers[Layer::Units]->attachChild(std::move(player));

    std::unique_ptr<ZombieNPC> enemy(new ZombieNPC(mGrid, mTextures));
    enemy->addSceneNodeCategory(SceneNodeCategory::EnemyUnit);
    enemy->addSceneNodeCategory(SceneNodeCategory::ImpassableUnit);
    enemy->setPosition(200.f, 100.f);
    mSceneLayers[Layer::Units]->attachChild(std::move(enemy));

//    mSceneLayers[ImpassableZones]->attachChild(generateImpassableZonesMap(mTextures.get(TextureIdentifier::MapImpassableZonesEmptyRoom),
//                                                                         sf::Color(255, 0, 0),
//                                                                         mapScaleFactor));
    mSceneLayers[ImpassableZones]->attachChild(generateImpassableZonesMap(mTextures.get(TextureIdentifier::MapImpassableZonesNotEmptyRoom),
                                                                          sf::Color(255, 0, 0),
                                                                          mapScaleFactor));

    std::vector<SceneNode*> impassableNodes;
    mSceneLayers[ImpassableZones]->getAllNodeOfCategoryPtrs(SceneNodeCategory::ImpassableZone, impassableNodes);
    for (const SceneNode* impassableNode : impassableNodes) {
        mGrid->setContainObstacleFlags(dynamic_cast<const CollidableNode*>(impassableNode)->getCollisionBoxRect());
    }
}

World::World(sf::RenderWindow& window)
: mWindow(window)
, mPlayerCamera(window.getDefaultView())
, mSceneGraph()
, mGrid(new VectorFieldGrid(sf::Vector2f(0.f, 0.f), sf::Vector2f(1360.f, 1120.f), 40.f)) {
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
    checkAllCollisions(mSceneGraph, collisionPairs);
    CollidableNode* firstCollidableNode = nullptr;
    CollidableNode* secondCollidableNode = nullptr;
    for (std::pair<SceneNode*, SceneNode*> pair : collisionPairs) {
        firstCollidableNode = dynamic_cast<CollidableNode*>(pair.first);
        secondCollidableNode = dynamic_cast<CollidableNode*>(pair.second);
        firstCollidableNode->onCollision(*secondCollidableNode);
        secondCollidableNode->onCollision(*firstCollidableNode);
    }

    mGrid->updateHeatmap(mSceneGraph.getFirstNodeOfCategoryPtr(SceneNodeCategory::Player)->getPosition());
    mGrid->updateVectorField();

    mPlayerCamera.update(dt);
}

void World::draw() {
    mWindow.setView(mPlayerCamera.getView());
    mWindow.draw(mSceneGraph);

#ifndef NDEBUG
    mGrid->draw(mWindow);
#endif
}

CommandQueue& World::getCommandQueue() {
    return mCommandQueue;
}
