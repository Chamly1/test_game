#ifndef TEST_GAME_UTILS_HPP
#define TEST_GAME_UTILS_HPP

#include "SFML/Graphics/Rect.hpp"

/**
 * Calculate whether is an intersection between two segments a-b and c-d. In case of intersection, calculate its point.
 *
 * @param a start point of the first segment.
 * @param b end point of the first segment.
 * @param c start point of the second segment.
 * @param d end point of the second segment.
 * @param intersectAt in case of intersection, write its point here.
 *
 * @return true if intersection occur.
 */
bool isTwoSegmentsIntersect(const sf::Vector2f& a, const sf::Vector2f& b, const sf::Vector2f& c, const sf::Vector2f& d, sf::Vector2f& intersectAt);
/**
 * Calculate whether is an intersection between ray and a-b segment. In case of intersection, calculate its point.
 *
 * @param rayOrigin the point of ray's origin.
 * @param rayDirection ray direction.
 * @param a start point of the segment.
 * @param b end point of the segment.
 * @param intersectAt in case of intersection, write its point here.
 *
 * @return true if intersection occur.
 */
bool isRayIntersectSegment(const sf::Vector2f& rayOrigin, const sf::Vector2f& rayDirection, const sf::Vector2f& a, const sf::Vector2f& b, sf::Vector2f& intersectAt);

#endif //TEST_GAME_UTILS_HPP
