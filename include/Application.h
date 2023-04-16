#ifndef TEST_GAME_APPLICATION_H
#define TEST_GAME_APPLICATION_H

#include "Player.h"
#include "ResourceHolders/TextureHolder.h"
#include "ResourceHolders/FontHolder.h"
#include "Scenes/SceneList.h"

#include "SFML/Graphics/RenderWindow.hpp"

class Application {
private:
    static const sf::Time deltaTime;

    sf::RenderWindow window;
    TextureHolder textures;
    FontHolder fonts;
    Player player;

    SceneList sceneList;

    void registerScenes();

    void processEvents();
    void update(sf::Time dt);
    void render();

public:
    Application();
    void run();

};

#endif //TEST_GAME_APPLICATION_H