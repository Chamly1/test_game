#ifndef TEST_GAME_APPLICATION_HPP
#define TEST_GAME_APPLICATION_HPP

#include "GameEngine/Player.hpp"
#include "GameEngine/ResourceHolders/TextureHolder.hpp"
#include "GameEngine/ResourceHolders/FontHolder.hpp"
#include "GameEngine/Scenes/SceneList.hpp"
#include "GameEngine/Utils/PerformanceStatisticManager.hpp"

#include "SFML/Graphics/RenderWindow.hpp"

class Application {
private:
    static const sf::Time mDeltaTime;

    sf::RenderWindow mWindow;
    TextureHolder mTextures;
    FontHolder mFonts;

    SceneList mSceneList;

    PerformanceStatisticManager mStatisticManager;

    void processEvents();
    void update(sf::Time dt);
    void render();

public:
    Application();
    template <typename T>
    void registerScene(unsigned int sceneId);
    void setStartScene(unsigned int sceneId);
    void run();

};

template <typename T>
void Application::registerScene(unsigned int sceneId) {
    mSceneList.registerScene<T>(sceneId);
}

#endif //TEST_GAME_APPLICATION_HPP
