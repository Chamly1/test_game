#include "GameEngine/Scenes/SceneContext.hpp"

SceneContext::SceneContext(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts)
: window(&window)
, textures(&textures)
, fonts(&fonts) {

}
