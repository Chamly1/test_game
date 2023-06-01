#include "GameEngine/Application.hpp"
#include "GameEngine/Utils/DebugLog.hpp"

// as microseconds. 6944 for 144 Hz
const sf::Time Application::deltaTime = sf::microseconds(6944);

void Application::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        sceneList.handleEvent(event);

        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Application::update(sf::Time dt) {
    sceneList.update(dt);
}

void Application::render(){
    window.clear();

    sceneList.draw();
    DEBUG_DRAW()

    window.display();
}

Application::Application()
        : window(sf::VideoMode::getDesktopMode(), "test_game", sf::Style::Fullscreen)
        , textures()
        , fonts()
        , sceneList(SceneContext(window, textures, fonts)){
//    window->setFramerateLimit(60);
//    window.setVerticalSyncEnabled(true);
    DEBUG_INIT(&window)
}

void Application::setStartScene(unsigned int sceneId) {
    sceneList.clear();
    sceneList.pushBack(sceneId);
}

void Application::run() {
    sf::Clock clock;
    sf::Time accumulator;

    while (window.isOpen()) {
        accumulator += clock.restart();

        while (accumulator >= deltaTime) {
            processEvents();
            update(deltaTime);

            if (sceneList.isEmpty()) {
                window.close();
            }

            accumulator -= deltaTime;
        }

        render();
    }
}
