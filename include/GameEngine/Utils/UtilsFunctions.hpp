#ifndef TEST_GAME_UTILSFUNCTIONS_HPP
#define TEST_GAME_UTILSFUNCTIONS_HPP

#include "GameEngine/DirectionType.hpp"

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

/**
 * Calculate whether is an intersection between a-b segment and the rectangle. In case of intersection, calculate its
 * point and return nearest, calculate normal to nearest collided side.
 *
 * @param a start point of the segment.
 * @param b end point of the segment.
 * @param rect rectangle.
 * @param firstIntersectionAt in case of intersection, write its point here.
 * @param intersectionNormal normal to nearest collided side(normalized value).
 *
 * @return true if intersection occur.
 */
bool isSegmentIntersectRectangle(const sf::Vector2f& a, const sf::Vector2f& b, const sf::FloatRect& rect, sf::Vector2f& firstIntersectionAt, sf::Vector2f& intersectionNormal);

sf::Vector2f getRectPosition(const sf::FloatRect& rect);
sf::Vector2f getRectSize(const sf::FloatRect& rect);

/**
 * Calculate vector's magnitude.
 *
 * @param vector vector to calculate magnitude.
 *
 * @return vector's magnitude.
 */
float vectorMagnitude(const sf::Vector2f& vector);

/**
 * Calculate length of the segment.
 *
 * @param a start point of the segment.
 * @param b end point of the segment.
 *
 * @return segment's length.
 */
float segmentLength(const sf::Vector2f& a, const sf::Vector2f& b);

/**
 * Normalize a vector.
 *
 * @param vector vector to be normalized.
 *
 * @return normalized vector.
 */
sf::Vector2f normalizeVector(const sf::Vector2f& vector);

/**
 * Convert the segment to the vector.
 *
 * @param a start point of the segment.
 * @param b end point of the segment.
 *
 * @return result vector;
 */
sf::Vector2f segmentToVector(const sf::Vector2f& a, const sf::Vector2f& b);

/**
 * Calculate clockwise unit normal vector to the segments a-b.
 *
 * @param a start point of the segment.
 * @param b end point of the segment.
 *
 * @return unit normal vector.
 */
sf::Vector2f unitNormalVector(const sf::Vector2f& a, const sf::Vector2f& b);

/**
 * Calculate the dot product of two vectors.
 *
 * @param vector1 first vector.
 * @param vector2 second vector.
 *
 * @return dot product.
 */
float dotProduct(const sf::Vector2f& vector1, const sf::Vector2f& vector2);

/**
 * Calculate reflection of vectorV across vectorN.
 *
 * @param vectorV vector being reflected.
 * @param vectorN vector in the line across which the reflection is performed (MUST be normalized).
 *
 * @return reflection.
 */
sf::Vector2f reflectionVector(const sf::Vector2f& vectorV, const sf::Vector2f& vectorN);

sf::Vector2f directionTypeToVector(DirectionType directionType);

#endif //TEST_GAME_UTILSFUNCTIONS_HPP
