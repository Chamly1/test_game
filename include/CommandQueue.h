#ifndef TEST_GAME_COMMANDQUEUE_H
#define TEST_GAME_COMMANDQUEUE_H

#include <queue>

#include "Command.h"

class CommandQueue {
private:
    std::queue<Command> queue;

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

#endif //TEST_GAME_COMMANDQUEUE_H
