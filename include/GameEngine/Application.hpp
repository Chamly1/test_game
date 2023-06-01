#ifndef TEST_GAME_APPLICATION_HPP
#define TEST_GAME_APPLICATION_HPP

#include "GameEngine/Player.hpp"
#include "GameEngine/ResourceHolders/TextureHolder.hpp"
#include "GameEngine/ResourceHolders/FontHolder.hpp"
#include "GameEngine/Scenes/SceneList.hpp"

#include "SFML/Graphics/RenderWindow.hpp"

class Application {
private:
    static const sf::Time deltaTime;

    sf::RenderWindow window;
    TextureHolder textures;
    FontHolder fonts;

    SceneList sceneList;

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
    sceneList.registerScene<T>(sceneId);
}

#endif //TEST_GAME_APPLICATION_HPP
