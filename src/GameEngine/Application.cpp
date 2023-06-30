#include "GameEngine/Application.hpp"
#include "GameEngine/Utils/DebugLog.hpp"

static const float LOGIC_UPDATES_PER_SECOND = 144.f;
const sf::Time Application::mDeltaTime = sf::seconds(1.f / LOGIC_UPDATES_PER_SECOND);

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
    mWindow.draw(mStatisticManager);
    DEBUG_DRAW()

    mWindow.display();
}

Application::Application()
: mWindow(sf::VideoMode::getDesktopMode(), "test_game", sf::Style::Fullscreen)
, mTextures()
, mFonts()
, mSceneList(SceneContext(mWindow, mTextures, mFonts))
, mStatisticManager(LOGIC_UPDATES_PER_SECOND) {
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
    sf::Clock performanceClock;
    sf::Time realWorldDt;
    sf::Time accumulator;

    while (mWindow.isOpen()) {
        realWorldDt = clock.restart();
        mStatisticManager.update(realWorldDt.asSeconds());
        accumulator += realWorldDt;

        while (accumulator >= mDeltaTime) {
            processEvents();

            performanceClock.restart();
            update(mDeltaTime);
            mStatisticManager.accumulateUpdateTime(performanceClock.restart().asSeconds());
            mStatisticManager.incrementLogicUpdatesCounter();

            if (mSceneList.isEmpty()) {
                mWindow.close();
            }

            accumulator -= mDeltaTime;
        }

        performanceClock.restart();
        render();
        mStatisticManager.accumulateRenderTime(performanceClock.restart().asSeconds());
        mStatisticManager.incrementFramesCounter();
    }
}
