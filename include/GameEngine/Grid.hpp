#ifndef TEST_GAME_GRID_HPP
#define TEST_GAME_GRID_HPP

#include "GameEngine/Cell.hpp"

#include <queue>

class Grid {
private:
    sf::Vector2f mPosition;
    float mCellSize;
    Cell** mCellsMatrix;
    int mWidth;
    int mHeight;

    void updateHeatmapFactor(int x, int y, int newHeatmapFactor, std::queue<sf::Vector2i>& lastUpdatedCells);

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
    void setContainObstacleFlags(sf::FloatRect intersectsWith);
    void updateHeatmap(const sf::Vector2f& goal);

};

#endif //TEST_GAME_GRID_HPP
