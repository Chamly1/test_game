#ifndef TEST_GAME_PLAYER_H
#define TEST_GAME_PLAYER_H

#include "GameEngine/Commands/CommandQueue.h"

#include "SFML/Window/Event.hpp"

#include <map>

namespace PlayerActionIdentifier {

enum PlayerAction {
    MoveUp,
    MoveDown,
    MoveLeft,
    MoveRight
};

}

class Player {
private:
    // map<key, player action id>
    std::map<sf::Keyboard::Key, unsigned int> keyBinding;
    // map<player action id, command>
    std::map<unsigned int, Command> playerActionBinding;
    std::map<unsigned int, bool> isRealtimePlayerAction;

    void initialKeyBinding();
    void initialPlayerActionBinding();

public:
    Player();
    void handleEvent(const sf::Event& event, CommandQueue& commands);
    void handleRealtimeInput(CommandQueue& commands);
};

#endif //TEST_GAME_PLAYER_H
