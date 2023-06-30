#ifndef TEST_GAME_WORLD_HPP
#define TEST_GAME_WORLD_HPP

#include "GameEngine/SceneNodes/SceneNode.hpp"
#include "GameEngine/ResourceHolders/TextureHolder.hpp"
#include "GameEngine/Commands/CommandQueue.hpp"
#include "PlayerCamera.hpp"
#include "GameEngine/Grid.hpp"

#include "SFML/Graphics/RenderWindow.hpp"

class World : private sf::NonCopyable {
private:
    enum Layer {
        Background,
        ImpassableZones,
        Units,
        LayerCount
    };

    sf::RenderWindow& mWindow;
    PlayerCamera mPlayerCamera;
    TextureHolder mTextures;

    SceneNode mSceneGraph;
    std::array<SceneNode*, LayerCount> mSceneLayers;
    CommandQueue mCommandQueue;

    std::shared_ptr<Grid> mGrid;

    void loadTextures();
    void buildScene();

public:
    explicit World(sf::RenderWindow& window);
    void update(sf::Time dt);
    void draw();

    CommandQueue& getCommandQueue();
};

#endif //TEST_GAME_WORLD_HPP
