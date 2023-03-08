#ifndef TEST_GAME_GAME_H
#define TEST_GAME_GAME_H

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

class Game {
private:
    sf::RenderWindow *window = nullptr;
    sf::Event ev;

    void initWindow();
    void pollEvents();

public:
    Game();
    ~Game();

    const bool isWindowOpen() const;
    void update();
    void render();
};


#endif //TEST_GAME_GAME_H
