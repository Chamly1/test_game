#ifndef TEST_GAME_SCENECONTEXT_H
#define TEST_GAME_SCENECONTEXT_H

#include "ResourceHolders/TextureHolder.h"
#include "ResourceHolders/FontHolder.h"
#include "Player.h"

#include "SFML/Graphics/RenderWindow.hpp"

struct SceneContext {
    sf::RenderWindow* window;
    TextureHolder* textures;
    FontHolder* fonts;
    Player* player;

    SceneContext(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, Player& player);
};

#endif //TEST_GAME_SCENECONTEXT_H
