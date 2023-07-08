#include "GameEngine/Player.hpp"
#include "GameEngine/SceneNodes/SceneNode.hpp"

Player::Player()
: mKeyBinding()
, mPlayerActionBinding()
, mIsRealtimePlayerAction() {

}

void Player::addPlayerActionBinding(sf::Keyboard::Key key, unsigned int playerActionId,
                                    Command command, bool isRealtimePlayerAction) {
    this->mKeyBinding[key] = playerActionId;
    this->mPlayerActionBinding[playerActionId] = command;
    this->mIsRealtimePlayerAction[playerActionId] = isRealtimePlayerAction;
}

void Player::handleEvent(const sf::Event& event, CommandQueue& commands) {
    if (event.type == sf::Event::KeyPressed) {
        for (auto pair : mKeyBinding) {
            if (event.key.code == pair.first && !mIsRealtimePlayerAction[pair.second]) {
                commands.push(mPlayerActionBinding[pair.second]);
            }
        }
    }
}

void Player::handleRealtimeInput(CommandQueue& commands) {
    for (auto pair : mKeyBinding) {
        if (sf::Keyboard::isKeyPressed(pair.first) && mIsRealtimePlayerAction[pair.second]) {
            commands.push(mPlayerActionBinding[pair.second]);
        }
    }
}
