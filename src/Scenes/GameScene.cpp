#include "Scenes/GameScene.h"

GameScene::GameScene(SceneContext ctx, SceneList& sceneList)
: Scene(ctx, sceneList)
, world(*ctx.window)
, player() {

}

void GameScene::draw() {
    world.draw();
}

bool GameScene::update(sf::Time dt){
    world.update(dt);

    CommandQueue& commands = world.getCommandQueue();
    player.handleRealtimeInput(commands);

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
