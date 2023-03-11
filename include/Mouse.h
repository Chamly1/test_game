#ifndef TEST_GAME_MOUSE_H
#define TEST_GAME_MOUSE_H

#include "SFML/Graphics.hpp"

class Mouse {
private:
    sf::RenderWindow *window = nullptr;
    sf::Vector2i mousePosOnWindow;

    sf::RectangleShape selectionRec;
    bool isSelectionRecVisible = false;

public:
    Mouse();
    void setRenderWindow(sf::RenderWindow *window);
    void processMouseButtonPressed(sf::Event *ev);
    void processMouseButtonReleased(sf::Event *ev);
    void processMouseMoved(sf::Event *ev);
    void draw();
};


#endif //TEST_GAME_MOUSE_H
