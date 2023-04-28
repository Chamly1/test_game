#include "Application.h"
#include "Scenes/TitleScene.h"
#include "Scenes/MenuScene.h"
#include "Scenes/GameScene.h"
#include "Scenes/PauseScene.h"
#include "Utils/DebugLog.h"

// as microseconds. 6944 for 144 Hz
const sf::Time Application::deltaTime = sf::microseconds(6944);

void Application::registerScenes() {
    sceneList.registerScene<TitleScene>(SceneIdentifier::Title);
    sceneList.registerScene<MenuScene>(SceneIdentifier::Menu);
    sceneList.registerScene<GameScene>(SceneIdentifier::Game);
    sceneList.registerScene<PauseScene>(SceneIdentifier::Pause);
}

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
    DebugLog::draw();

    window.display();
}

Application::Application()
        : window(sf::VideoMode::getDesktopMode(), "test_game", sf::Style::Fullscreen)
        , textures()
        , fonts()
        , sceneList(SceneContext(window, textures, fonts)){
//    window->setFramerateLimit(60);
//    window.setVerticalSyncEnabled(true);


    registerScenes();

    DebugLog::init(&window);
    fonts.load(FontIdentifier::Main, "resources/fonts/game_over.ttf");
    textures.load(TextureIdentifier::MenuSelector,
                  "resources/textures/Minifantasy_Userinterface_Assets/Menus/Selectors/Minifantasy_GuiSelectors.png",
                  sf::IntRect(0, 16 * 20, 16, 16));

    sceneList.pushBack(SceneIdentifier::Title);
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
