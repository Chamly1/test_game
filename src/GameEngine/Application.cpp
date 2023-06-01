#include "GameEngine/Application.hpp"
#include "GameEngine/Utils/DebugLog.hpp"

// as microseconds. 6944 for 144 Hz
const sf::Time Application::mDeltaTime = sf::microseconds(6944);

void Application::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        mSceneList.handleEvent(event);

        if (event.type == sf::Event::Closed) {
            mWindow.close();
        }
    }
}

void Application::update(sf::Time dt) {
    mSceneList.update(dt);
}

void Application::render(){
    mWindow.clear();

    mSceneList.draw();
    DEBUG_DRAW()

    mWindow.display();
}

Application::Application()
        : mWindow(sf::VideoMode::getDesktopMode(), "test_game", sf::Style::Fullscreen)
        , mTextures()
        , mFonts()
        , mSceneList(SceneContext(mWindow, mTextures, mFonts)){
//    window->setFramerateLimit(60);
//    window.setVerticalSyncEnabled(true);
    DEBUG_INIT(&mWindow)
}

void Application::setStartScene(unsigned int sceneId) {
    mSceneList.clear();
    mSceneList.pushBack(sceneId);
}

void Application::run() {
    sf::Clock clock;
    sf::Time accumulator;

    while (mWindow.isOpen()) {
        accumulator += clock.restart();

        while (accumulator >= mDeltaTime) {
            processEvents();
            update(mDeltaTime);

            if (mSceneList.isEmpty()) {
                mWindow.close();
            }

            accumulator -= mDeltaTime;
        }

        render();
    }
}
