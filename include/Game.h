#ifndef TEST_GAME_GAME_H
#define TEST_GAME_GAME_H

#include "iostream"

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

class Game {
private:
    sf::RenderWindow *window = nullptr;
    sf::Event ev;

    sf::Vector2i mousePosOnWindow;

    void updateMousePos();
    void processEvents();
    void update();
    void render();

public:
    Game();
    ~Game();

    void run();
};


#endif //TEST_GAME_GAME_H
