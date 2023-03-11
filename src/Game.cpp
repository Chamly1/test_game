#include "Game.h"

void Game::processEvents() {
    while (window->pollEvent(ev)) {
        switch (ev.type) {
            case sf::Event::MouseButtonPressed:
                mouse.processMouseButtonPressed(&ev);
                break;

            case sf::Event::MouseButtonReleased:
                mouse.processMouseButtonReleased(&ev);
                break;

            case sf::Event::MouseMoved:
                mouse.processMouseMoved(&ev);
                break;

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

}

void Game::render(){
    window->clear();
    mouse.draw();
    window->display();
}

Game::Game() {
    //    window = new sf::RenderWindow(sf::VideoMode(800, 600), "test_game", sf::Style::Default);
    window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "test_game", sf::Style::Fullscreen);
//    window->setFramerateLimit(60);
//    window->setVerticalSyncEnabled(true);

    mouse.setRenderWindow(window);
}

Game::~Game(){
    delete window;
}

void Game::run() {
    sf::Clock clock;
    sf::Int64 accumulator = 0;

    while (window->isOpen()) {
        accumulator += clock.restart().asMicroseconds();

        while (accumulator >= deltaTime) {
            processEvents();
            update();
            accumulator -= deltaTime;
        }

        render();
    }
}
