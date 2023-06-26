#ifndef TEST_GAME_GRID_HPP
#define TEST_GAME_GRID_HPP

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Transformable.hpp"

class Grid : public sf::Drawable, public sf::Transformable {
private:
    bool** mGridMatrix;
    int mWidth;
    int mHeight;

public:
    Grid(const sf::Vector2f& start, const sf::Vector2f& end, float cellSize);
    ~Grid();

};

#endif //TEST_GAME_GRID_HPP
