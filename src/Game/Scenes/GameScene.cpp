#include "Game/Scenes/GameScene.h"
#include "Game/SceneNodes/SceneNodeCategory.h"
#include "Game/SceneNodes/Entity.h"
#include "Game/PlayerActionIdentifiers.h"
#include "Game/Scenes/SceneIdentifiers.h"

void GameScene::bindPlayerActions() {
    Command command;

    command.action = EntityMover(Direction::Up);
    command.sceneNodeCategory = SceneNodeCategory::Player;
    player.addPlayerActionBinding(sf::Keyboard::Key::Up, PlayerActionIdentifier::MoveUp, command, true);

    command.action = EntityMover(Direction::Down);
    command.sceneNodeCategory = SceneNodeCategory::Player;
    player.addPlayerActionBinding(sf::Keyboard::Key::Down, PlayerActionIdentifier::MoveDown, command, true);

    command.action = EntityMover(Direction::Left);
    command.sceneNodeCategory = SceneNodeCategory::Player;
    player.addPlayerActionBinding(sf::Keyboard::Key::Left, PlayerActionIdentifier::MoveLeft, command, true);

    command.action = EntityMover(Direction::Right);
    command.sceneNodeCategory = SceneNodeCategory::Player;
    player.addPlayerActionBinding(sf::Keyboard::Key::Right, PlayerActionIdentifier::MoveRight, command, true);
}

GameScene::GameScene(SceneContext ctx, SceneList& sceneList)
: Scene(ctx, sceneList)
, world(*ctx.window)
, player() {
    bindPlayerActions();
}

void GameScene::draw() {
    world.draw();
}

bool GameScene::update(sf::Time dt){
    CommandQueue& commands = world.getCommandQueue();
    player.handleRealtimeInput(commands);

    world.update(dt);

    return true;
}

bool GameScene::handleEvent(const sf::Event& event) {
    CommandQueue& commands = world.getCommandQueue();
    player.handleEvent(event, commands);

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        requestListPushBack(SceneIdentifier::Pause);
    }

    return true;
}
