#ifndef TEST_GAME_UTILS_HPP
#define TEST_GAME_UTILS_HPP

#include "GameEngine/Animation.hpp"
#include "Game/DataTables.hpp"

#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Sprite.hpp"

void setOriginToCenter(sf::Text& text);
void setOriginToCenter(sf::Sprite& sprite);
void setOriginToCenter(Animation& sprite);
DirectionType moveVelocityToAnimationDirection(const sf::Vector2f& velocity, DirectionType oldDirection);

#endif //TEST_GAME_UTILS_HPP
