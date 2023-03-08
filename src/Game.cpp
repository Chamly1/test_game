#include "Game.h"

void Game::initWindow(){
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "test_game", sf::Style::Default);
}

void Game::pollEvents() {
    while (window->pollEvent(ev)) {
        switch (ev.type) {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyPressed:
//                std::cout << "key pressed" << std::endl;
//                std::cout << ev.key.code << std::endl;
                break;
        }
    }
}

Game::Game() {
    initWindow();
}

Game::~Game(){
    delete window;
}

const bool Game::isWindowOpen() const {
    return window->isOpen();
}

void Game::update(){
    pollEvents();
}

void Game::render(){
    window->clear();
    window->display();
}
