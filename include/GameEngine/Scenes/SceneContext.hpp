#ifndef TEST_GAME_SCENECONTEXT_HPP
#define TEST_GAME_SCENECONTEXT_HPP

#include "GameEngine/ResourceHolders/TextureHolder.hpp"
#include "GameEngine/ResourceHolders/FontHolder.hpp"

#include "SFML/Graphics/RenderWindow.hpp"

struct SceneContext {
    sf::RenderWindow* window;
    TextureHolder* textures;
    FontHolder* fonts;

    SceneContext(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts);
};

#endif //TEST_GAME_SCENECONTEXT_HPP
