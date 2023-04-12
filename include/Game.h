#ifndef TEST_GAME_GAME_H
#define TEST_GAME_GAME_H

#include "iostream"

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "World.h"
#include "Mouse.h"

class Game {
private:
    static const sf::Time deltaTime;

    sf::RenderWindow window;
    sf::Event ev;
    World world;
    Mouse mouse;

    void processEvents();
    void update(sf::Time elapsedTime);
    void render();

public:
    Game();
    ~Game();

    void run();
};


#endif //TEST_GAME_GAME_H
