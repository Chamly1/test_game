#ifndef TEST_GAME_PLAYER_H
#define TEST_GAME_PLAYER_H

#include <map>

#include "SFML/Window/Event.hpp"

#include "CommandQueue.h"

enum class PlayerAction {
    MoveUp,
    MoveDown,
    MoveLeft,
    MoveRight
};

class Player {
private:
    std::map<sf::Keyboard::Key, PlayerAction> keyBinding;
    std::map<PlayerAction, Command> playerActionBinding;

    bool isRealtimePlayerAction(PlayerAction action);

    void initialKeyBinding();
    void initialPlayerActionBinding();

public:
    Player();
    void handleEvent(const sf::Event& event, CommandQueue& commands);
    void handleRealtimeInput(CommandQueue& commands);

    void assignKey(PlayerAction action, sf::Keyboard::Key key);
};

#endif //TEST_GAME_PLAYER_H
