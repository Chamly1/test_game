#include "Mouse.h"

Mouse::Mouse() {
    selectionRec.setOutlineThickness(1.f);
    selectionRec.setOutlineColor(sf::Color(255, 255, 255));
    selectionRec.setFillColor(sf::Color(255, 255, 255, 50));
}

void Mouse::setWindow(sf::RenderWindow *window) {
    this->window = window;
}

void Mouse::processMouseButtonPressed(sf::Event *ev) {
    mousePosOnWindow = sf::Mouse::getPosition(*window);

    switch (ev->mouseButton.button) {
        case sf::Mouse::Left:
            selectionRec.setPosition(sf::Vector2f(mousePosOnWindow));
            isSelectionRecVisible = true;
            selectionRec.setSize(sf::Vector2f(0.f, 0.f));
            break;
    }
}

void Mouse::processMouseButtonReleased(sf::Event *ev) {
    switch (ev->mouseButton.button) {
        case sf::Mouse::Left:
            isSelectionRecVisible = false;
            break;
    }
}

void Mouse::processMouseMoved(sf::Event *ev) {
    mousePosOnWindow = sf::Mouse::getPosition(*window);

    if (isSelectionRecVisible) {
        selectionRec.setSize(sf::Vector2f(mousePosOnWindow) - selectionRec.getPosition());
    }
}

void Mouse::draw() {
    if (isSelectionRecVisible) {
        window->draw(selectionRec);
    }
}
