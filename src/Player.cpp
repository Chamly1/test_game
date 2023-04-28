#include "Player.h"
#include "SceneNodes/SceneNodeCategory.h"
#include "GameEngine/SceneNodes/SceneNode.h"
#include "SceneNodes/Entity.h"

bool Player::isRealtimePlayerAction(PlayerAction action) {
    switch (action) {
        case PlayerAction::MoveUp:
        case PlayerAction::MoveDown:
        case PlayerAction::MoveLeft:
        case PlayerAction::MoveRight:
            return true;

        default:
            return false;
    }
}

void Player::initialKeyBinding() {
    keyBinding[sf::Keyboard::Key::Up] = PlayerAction::MoveUp;
    keyBinding[sf::Keyboard::Key::Down] = PlayerAction::MoveDown;
    keyBinding[sf::Keyboard::Key::Left] = PlayerAction::MoveLeft;
    keyBinding[sf::Keyboard::Key::Right] = PlayerAction::MoveRight;
}

void Player::initialPlayerActionBinding() {
    playerActionBinding[PlayerAction::MoveUp].action = EntityMover(Direction::Up);
    playerActionBinding[PlayerAction::MoveDown].action = EntityMover(Direction::Down);
    playerActionBinding[PlayerAction::MoveLeft].action = EntityMover(Direction::Left);
    playerActionBinding[PlayerAction::MoveRight].action = EntityMover(Direction::Right);

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
        if (sf::Keyboard::isKeyPressed(pair.first) && isRealtimePlayerAction(pair.second)) {
            commands.push(playerActionBinding[pair.second]);
        }
    }
}
