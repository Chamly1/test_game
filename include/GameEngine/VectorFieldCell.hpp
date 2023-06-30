#ifndef TEST_GAME_VECTORFIELDCELL_HPP
#define TEST_GAME_VECTORFIELDCELL_HPP

#include "SFML/Graphics/Rect.hpp"

#ifndef NDEBUG
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Text.hpp"
#endif

/**
 * Class which represent one single cell in a grid of goal-based vector field (pathfinding algorithm).
 */
class VectorFieldCell {
private:
    sf::FloatRect mCellRect;
    bool mContainObstacle;
    int mHeatmapFactor;
    sf::Vector2f mFieldVector;
    sf::Vector2f mNextCellCenter;

#ifndef NDEBUG
    sf::RectangleShape mCellShape;
    sf::Text mHeatmapFactorText;
    sf::VertexArray mFieldVectorShape;
#endif

public:
#ifndef NDEBUG
    void draw(sf::RenderTarget& target, sf::RenderStates states);
#endif

    VectorFieldCell();
    VectorFieldCell(const sf::FloatRect& cellRect, bool containObstacle);
    void init(const sf::FloatRect& cellRect, bool containObstacle);
    bool doesContainObstacle() const;
    void setContainObstacleFlag(bool containObstacleFlag);
    /**
     * Set flag to true if obstacle intersect cell.
     *
     * @param obstacle obstacle to check intersection.
     */
    void setContainObstacleFlag(const sf::FloatRect& obstacle);
    void setHeatmapFactor(int heatmapFactor);
    int getHeatmapFactor() const;
    void setFieldVector(const sf::Vector2f& fieldVector);
    sf::Vector2f getFieldVector() const;
    sf::Vector2f getCellCenter() const;
    void setNextCellCenter(const sf::Vector2f& nextCellCenter);
    sf::Vector2f getNextCellCenter() const;

};

#endif //TEST_GAME_VECTORFIELDCELL_HPP
