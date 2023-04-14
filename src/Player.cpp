#include "Player.h"
#include "SceneNode.h"
#include "Entities/Unit.h"

void Player::handleEvent(const sf::Event& event, CommandQueue& commands) {

}

void Player::handleRealtimeInput(CommandQueue& commands) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        Command moveUp;
        moveUp.sceneNodeCategory = SceneNodeCategory::Player;
        moveUp.action = EntityMover(Direction::Up);
        commands.push(moveUp);
    }
}
