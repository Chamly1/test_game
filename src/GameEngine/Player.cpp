#include "GameEngine/Player.hpp"
#include "GameEngine/SceneNodes/SceneNode.hpp"

Player::Player()
: keyBinding()
, playerActionBinding()
, isRealtimePlayerAction() {

}

void Player::addPlayerActionBinding(sf::Keyboard::Key key, unsigned int playerActionId,
                                    Command command, bool isRealtimePlayerAction) {
    this->keyBinding[key] = playerActionId;
    this->playerActionBinding[playerActionId] = command;
    this->isRealtimePlayerAction[playerActionId] = isRealtimePlayerAction;
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
