#ifndef TEST_GAME_GAME_H
#define TEST_GAME_GAME_H

#include "World.h"
#include "Player.h"

class Game {
private:
    static const sf::Time deltaTime;

    sf::RenderWindow window;
    sf::Event ev;
    World world;
    Player player;

    void processEvents();
    void update(sf::Time elapsedTime);
    void render();

public:
    Game();
    ~Game();

    void run();
};


#endif //TEST_GAME_GAME_H
