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

/**
 * Calculate vector's magnitude.
 *
 * @param vector vector to calculate magnitude.
 *
 * @return vector's magnitude.
 */
float vectorMagnitude(const sf::Vector2f& vector);

/**
 * Normalize a vector.
 *
 * @param vector vector to be normalized.
 *
 * @return normalized vector.
 */
sf::Vector2f normalizeVector(const sf::Vector2f& vector);

#endif //TEST_GAME_UTILS_HPP
