#include "Game/Scenes/GameScene.hpp"
#include "Game/SceneNodes/SceneNodeCategory.hpp"
#include "GameEngine/SceneNodes/MovableNode.hpp"
#include "Game/PlayerActionIdentifiers.hpp"
#include "Game/Scenes/SceneIdentifiers.hpp"
#include "Game/SceneNodes/Unit.hpp"

void GameScene::bindPlayerActions() {
    Command command;

    command.action = EntityMover(Direction::Up);
    command.sceneNodeCategory = SceneNodeCategory::Player;
    mPlayer.addPlayerActionBinding(sf::Keyboard::Key::Up, PlayerActionIdentifier::MoveUp, command, true);

    command.action = EntityMover(Direction::Down);
    command.sceneNodeCategory = SceneNodeCategory::Player;
    mPlayer.addPlayerActionBinding(sf::Keyboard::Key::Down, PlayerActionIdentifier::MoveDown, command, true);

    command.action = EntityMover(Direction::Left);
    command.sceneNodeCategory = SceneNodeCategory::Player;
    mPlayer.addPlayerActionBinding(sf::Keyboard::Key::Left, PlayerActionIdentifier::MoveLeft, command, true);

    command.action = EntityMover(Direction::Right);
    command.sceneNodeCategory = SceneNodeCategory::Player;
    mPlayer.addPlayerActionBinding(sf::Keyboard::Key::Right, PlayerActionIdentifier::MoveRight, command, true);

    command.action = UnitController(UnitAction::Attack);
    command.sceneNodeCategory = SceneNodeCategory::Player;
    mPlayer.addPlayerActionBinding(sf::Keyboard::Key::A, PlayerActionIdentifier::Attack, command, false);
}

GameScene::GameScene(SceneContext ctx, SceneList& sceneList)
: Scene(ctx, sceneList)
, mWorld(*ctx.window)
, mPlayer() {
    bindPlayerActions();
}

void GameScene::draw() {
    mWorld.draw();
}

bool GameScene::update(sf::Time dt){
    CommandQueue& commands = mWorld.getCommandQueue();
    mPlayer.handleRealtimeInput(commands);

    mWorld.update(dt);

    return true;
}

bool GameScene::handleEvent(const sf::Event& event) {
    CommandQueue& commands = mWorld.getCommandQueue();
    mPlayer.handleEvent(event, commands);

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        requestListPushBack(SceneIdentifier::Pause);
    }

    return true;
}
