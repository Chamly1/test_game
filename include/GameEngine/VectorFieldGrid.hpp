#ifndef TEST_GAME_VECTORFIELDGRID_HPP
#define TEST_GAME_VECTORFIELDGRID_HPP

#include "GameEngine/VectorFieldCell.hpp"

#include <queue>

class VectorFieldGrid {
private:
    sf::Vector2f mPosition;
    float mCellSize;
    VectorFieldCell** mCellsMatrix;
    int mWidth;
    int mHeight;

    void updateHeatmapFactor(int x, int y, int newHeatmapFactor, std::queue<sf::Vector2i>& lastUpdatedCells);
    /**
     * Return -1 if there is no cell by (x, y) indexes.
     *
     * @param x
     * @param y
     * @return
     */
    int getHeatmapFactor(int x, int y);
    void getMinHeatmapFactorNeighbor(int x, int y, int& neighborX, int& neighborY);
    bool isPointLiesOnGrid(const sf::Vector2f& point) const;

public:
#ifndef NDEBUG
void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default);
#endif

    VectorFieldGrid(const sf::Vector2f& position, const sf::Vector2f& size, float cellSize);
    ~VectorFieldGrid();

    /**
     * Activate cells witch intersects with rectangle.
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
