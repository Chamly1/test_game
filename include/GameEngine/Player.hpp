#ifndef TEST_GAME_PLAYER_HPP
#define TEST_GAME_PLAYER_HPP

#include "GameEngine/Commands/CommandQueue.hpp"

#include "SFML/Window/Event.hpp"

#include <map>

class Player {
private:
    // map<key, player action id>
    std::map<sf::Keyboard::Key, unsigned int> mKeyBinding;
    // map<player action id, command>
    std::map<unsigned int, Command> mPlayerActionBinding;
    std::map<unsigned int, bool> mIsRealtimePlayerAction;

    void initialKeyBinding();
    void initialPlayerActionBinding();

public:
    Player();
    void addPlayerActionBinding(sf::Keyboard::Key key, unsigned int playerActionId,
                                Command command, bool isRealtimePlayerAction);
    void handleEvent(const sf::Event& event, CommandQueue& commands);
    void handleRealtimeInput(CommandQueue& commands);
};

#endif //TEST_GAME_PLAYER_HPP
