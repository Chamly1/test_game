#ifndef TEST_GAME_UTILS_H
#define TEST_GAME_UTILS_H

#include "GameEngine/Animation.h"
#include "Game/DataTables.h"

#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Sprite.hpp"

void setOriginToCenter(sf::Text& text);
void setOriginToCenter(sf::Sprite& sprite);
void setOriginToCenter(Animation& sprite);
DirectionType moveVelocityToAnimationDirection(const sf::Vector2f& velocity, DirectionType oldDirection);

#endif //TEST_GAME_UTILS_H
