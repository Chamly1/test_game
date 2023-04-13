#ifndef TEST_GAME_WORLD_H
#define TEST_GAME_WORLD_H

#include <array>

#include "SFML/Graphics.hpp"

#include "ResourceHolders/TextureHolder.h"
#include "SceneNode.h"
#include "CommandQueue.h"

class World : private sf::NonCopyable {
private:
    enum Layer {
        Background,
        LayerCount
    };

    sf::RenderWindow& window;
    sf::View worldView;
    TextureHolder textures;

    SceneNode sceneGraph;
    std::array<SceneNode*, LayerCount> sceneLayers;
    CommandQueue commandQueue;

    void loadTextures();
    void buildScene();

public:
    explicit World(sf::RenderWindow& window);
    void update(sf::Time dt);
    void draw();
};

#endif //TEST_GAME_WORLD_H
