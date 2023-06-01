#ifndef TEST_GAME_COMMANDQUEUE_HPP
#define TEST_GAME_COMMANDQUEUE_HPP

#include "GameEngine/Commands/Command.hpp"

#include <queue>

class CommandQueue {
private:
    std::queue<Command> mQueue;

public:
    void push(const Command& command);
    /**
     * Return the first element. Does NOT check whether is empty, you MUST do it by yourself.
     *
     * @return the first element.
     */
    Command pop();
    bool isEmpty() const;
};

#endif //TEST_GAME_COMMANDQUEUE_HPP
