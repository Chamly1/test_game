#include "Scenes/SceneContext.h"

SceneContext::SceneContext(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, Player& player)
: window(&window)
, textures(&textures)
, fonts(&fonts)
, player(&player) {

}
