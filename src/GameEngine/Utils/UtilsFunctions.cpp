#include "GameEngine/Utils/UtilsFunctions.hpp"

bool isTwoSegmentsIntersect(const sf::Vector2f& a, const sf::Vector2f& b, const sf::Vector2f& c, const sf::Vector2f& d, sf::Vector2f& intersectAt) {
    sf::Vector2f r = b - a;
    sf::Vector2f s = d - c;

    // cross product r and s (r x s)
    float rs = r.x * s.y - r.y * s.x;

    // u = (c - a) x r / r x s
    float u = ((c.x - a.x) * r.y - (c.y - a.y) * r.x) / rs;
    // t = (c - a) x s / r x s
    float t = ((c.x - a.x) * s.y - (c.y - a.y) * s.x) / rs;

    bool isIntersect = u >= 0 && u <= 1 && t >= 0 && t <= 1;
    if (isIntersect) {
        intersectAt = a + r * t;
    }

    return isIntersect;
}

bool isRayIntersectSegment(const sf::Vector2f& rayOrigin, const sf::Vector2f& rayDirection, const sf::Vector2f& a, const sf::Vector2f& b, sf::Vector2f& intersectAt) {
    sf::Vector2f r = b - a;
    sf::Vector2f s = rayDirection;

    // cross product r and s (r x s)
    float rs = r.x * s.y - r.y * s.x;

    // u = (c - a) x r / r x s
    float u = ((rayOrigin.x - a.x) * r.y - (rayOrigin.y - a.y) * r.x) / rs;
    // t = (c - a) x s / r x s
    float t = ((rayOrigin.x - a.x) * s.y - (rayOrigin.y - a.y) * s.x) / rs;

    bool isIntersect = u >= 0 && t >= 0 && t <= 1;
    if (isIntersect) {
        intersectAt = a + r * t;
    }

    return isIntersect;
}

sf::Vector2f getRectPosition(const sf::FloatRect& rect) {
    return sf::Vector2f(rect.left, rect.top);
}

sf::Vector2f getRectSize(const sf::FloatRect& rect) {
    return sf::Vector2f(rect.width, rect.height);
}
