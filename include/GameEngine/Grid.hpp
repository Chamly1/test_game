#ifndef TEST_GAME_GRID_HPP
#define TEST_GAME_GRID_HPP

#include "GameEngine/Cell.hpp"

class Grid {
private:
    Cell** mCellsMatrix;
    int mWidth;
    int mHeight;

public:
#ifndef NDEBUG
void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default);
#endif

    Grid(const sf::Vector2f& position, const sf::Vector2f& size, float cellSize);
    ~Grid();

    /**
     * Activate cells witch intersects with rectangle.
     *
     * @param intersectsWith rectangle for intersection.
     */
    void activateCells(sf::FloatRect intersectsWith);

};

#endif //TEST_GAME_GRID_HPP
