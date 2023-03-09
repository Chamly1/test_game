#include "Game.h"

void Game::updateMousePos() {
    mousePosOnWindow = sf::Mouse::getPosition(*window);
}

void Game::processEvents() {
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

void Game::update(){
    updateMousePos();
}

void Game::render(){
    window->clear();
    window->display();
}

Game::Game() {
    //    window = new sf::RenderWindow(sf::VideoMode(800, 600), "test_game", sf::Style::Default);
    window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "test_game", sf::Style::Fullscreen);
    window->setFramerateLimit(60);
}

Game::~Game(){
    delete window;
}

void Game::run() {
    while (window->isOpen()) {
        processEvents();
        update();
        render();
    }
}
