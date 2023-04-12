#include "Game.h"
#include "DebugLog.h"

// as microseconds. 6944 for 144 Hz
const sf::Time Game::deltaTime = sf::microseconds(6944);

Game::Game() : window(sf::VideoMode::getDesktopMode(), "test_game", sf::Style::Fullscreen), mouse(window) {
    //    window = new sf::RenderWindow(sf::VideoMode(800, 600), "test_game", sf::Style::Default);
//    window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "test_game", sf::Style::Fullscreen);
//    window->setFramerateLimit(60);
//    window->setVerticalSyncEnabled(true);

    DebugLog::init(&window);
}

void Game::processEvents() {
    while (window.pollEvent(ev)) {
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
                window.close();
                break;
            case sf::Event::KeyPressed:
//                std::cout << "key pressed" << std::endl;
//                std::cout << ev.key.code << std::endl;
                break;
        }
    }
}

void Game::update(sf::Time elapsedTime){

}

void Game::render(){
    window.clear();

    mouse.draw();

    DebugLog::draw();
    window.display();
}

void Game::run() {
    sf::Clock clock;
    sf::Time accumulator;

    while (window.isOpen()) {
        accumulator += clock.restart();

        while (accumulator >= deltaTime) {
            processEvents();
            update(deltaTime);
            accumulator -= deltaTime;
        }

        render();
    }
}

Game::~Game(){

}
