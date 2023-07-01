#ifndef TEST_GAME_VECTORFIELDGRID_HPP
#define TEST_GAME_VECTORFIELDGRID_HPP

#include "GameEngine/VectorFieldCell.hpp"

#include <queue>

/**
 * Class which realize goal-based vector field pathfinding algorithm.
 */
class VectorFieldGrid {
private:
    sf::Vector2f mPosition;
    float mCellSize;
    VectorFieldCell** mCellsMatrix;
    int mWidth;
    int mHeight;

    /**
     * Update heatmap factor of the cell by it's indexes. If there is no cell by thees indexes - does nothing.
     * If heatmap factor has been updated - add cell's indexes to lastUpdatedCells queue.
     *
     * @param x column's number of cell(numeration begins from zero).
     * @param y row's number of cell(numeration begins from zero).
     * @param newHeatmapFactor new heatmap factor.
     * @param lastUpdatedCells queue where to can be added cell's indexes.
     */
    void updateHeatmapFactor(int x, int y, int newHeatmapFactor, std::queue<sf::Vector2i>& lastUpdatedCells);
    /**
     * Return heatmap factor of the cell by it's indexes.
     * -1 if there is no cell by (x, y) indexes or at this coordinate is obstacle.
     *
     * @param x column's number of cell(numeration begins from zero).
     * @param y row's number of cell(numeration begins from zero).
     *
     * @return heatmap factor.
     */
    int getHeatmapFactor(int x, int y);
    /**
     * Calculate indexes of the neighbor(3x3 region near the cell and including it) cell with the smallest heatmap
     * factor. If there are several such cells - return first appeared.
     *
     * @param x column's number of cell for which looking for neighbor(numeration begins from zero).
     * @param y row's number of cell for which looking for neighbor(numeration begins from zero).
     * @param neighborX return column's number of looked for neighbor cell(numeration begins from zero).
     * @param neighborY return row's number of looked for neighbor cell(numeration begins from zero).
     */
    void getMinHeatmapFactorNeighbor(int x, int y, int& neighborX, int& neighborY);
    bool isPointLiesOnGrid(const sf::Vector2f& point) const;

public:
#ifndef NDEBUG
void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default);
#endif

    /**
     * Construct vector field grid. If the grid size is not a multiple of the cell size, the grid size is padded to
     * the desired size.
     *
     * @param position grid position.
     * @param size grid size.
     * @param cellSize single cell size.
     */
    VectorFieldGrid(const sf::Vector2f& position, const sf::Vector2f& size, float cellSize);
    ~VectorFieldGrid();

    /**
     * Mark cells witch intersects with rectangle.
     *
     * @param intersectsWith rectangle for intersection.
     */
    void setContainObstacleFlags(sf::FloatRect intersectsWith);
    void updateHeatmap(const sf::Vector2f& goal);
    void updateVectorField();
    sf::Vector2f getFieldVectorInPoint(const sf::Vector2f& point) const;
    sf::Vector2f getNextCellCenterInPoint(const sf::Vector2f& point) const;

};

#endif //TEST_GAME_VECTORFIELDGRID_HPP
