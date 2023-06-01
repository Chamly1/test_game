#ifndef TEST_GAME_WORLD_HPP
#define TEST_GAME_WORLD_HPP

#include "GameEngine/SceneNodes/SceneNode.hpp"
#include "GameEngine/ResourceHolders/TextureHolder.hpp"
#include "GameEngine/Commands/CommandQueue.hpp"
#include "PlayerCamera.hpp"

#include "SFML/Graphics/RenderWindow.hpp"

class World : private sf::NonCopyable {
private:
    enum Layer {
        Background,
        ImpassableZones,
        Units,
        LayerCount
    };

    sf::RenderWindow& window;
    PlayerCamera playerCamera;
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

    CommandQueue& getCommandQueue();
};

#endif //TEST_GAME_WORLD_HPP
