#ifndef TEST_GAME_PLAYER_H
#define TEST_GAME_PLAYER_H

#include "SFML/Window/Event.hpp"

#include "CommandQueue.h"

class Player {
private:

public:
    void handleEvent(const sf::Event& event, CommandQueue& commands);
    void handleRealtimeInput(CommandQueue& commands);
};

#endif //TEST_GAME_PLAYER_H
