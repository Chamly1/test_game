#include "Player.h"
#include "SceneNodes/SceneNodeCategory.h"
#include "GameEngine/SceneNodes/SceneNode.h"
#include "SceneNodes/Entity.h"

void Player::initialKeyBinding() {
    keyBinding[sf::Keyboard::Key::Up] = PlayerActionIdentifier::MoveUp;
    keyBinding[sf::Keyboard::Key::Down] = PlayerActionIdentifier::MoveDown;
    keyBinding[sf::Keyboard::Key::Left] = PlayerActionIdentifier::MoveLeft;
    keyBinding[sf::Keyboard::Key::Right] = PlayerActionIdentifier::MoveRight;
}

void Player::initialPlayerActionBinding() {
    playerActionBinding[PlayerActionIdentifier::MoveUp].action = EntityMover(Direction::Up);
    isRealtimePlayerAction[PlayerActionIdentifier::MoveUp] = true;

    playerActionBinding[PlayerActionIdentifier::MoveDown].action = EntityMover(Direction::Down);
    isRealtimePlayerAction[PlayerActionIdentifier::MoveDown] = true;

    playerActionBinding[PlayerActionIdentifier::MoveLeft].action = EntityMover(Direction::Left);
    isRealtimePlayerAction[PlayerActionIdentifier::MoveLeft] = true;

    playerActionBinding[PlayerActionIdentifier::MoveRight].action = EntityMover(Direction::Right);
    isRealtimePlayerAction[PlayerActionIdentifier::MoveRight] = true;

    for (auto& pair : playerActionBinding) {
        pair.second.sceneNodeCategory = SceneNodeCategory::Player;
    }
}

Player::Player() {
    initialKeyBinding();
    initialPlayerActionBinding();
}

void Player::handleEvent(const sf::Event& event, CommandQueue& commands) {

}

void Player::handleRealtimeInput(CommandQueue& commands) {
    for (auto pair : keyBinding) {
        if (sf::Keyboard::isKeyPressed(pair.first) && isRealtimePlayerAction[pair.second]) {
            commands.push(playerActionBinding[pair.second]);
        }
    }
}
