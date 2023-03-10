#ifndef TEST_GAME_GAME_H
#define TEST_GAME_GAME_H

#include "iostream"

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Mouse.h"

class Game {
private:
    sf::RenderWindow *window = nullptr;
    sf::Event ev;
    Mouse mouse;
    // as microseconds. 6944 for 144 Hz
    sf::Int64 deltaTime = 6944;

    void processEvents();
    void update();
    void render();

public:
    Game();
    ~Game();

    void run();
};


#endif //TEST_GAME_GAME_H
