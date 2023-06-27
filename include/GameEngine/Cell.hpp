#ifndef TEST_GAME_CELL_HPP
#define TEST_GAME_CELL_HPP

#include "SFML/Graphics/Rect.hpp"

#ifndef NDEBUG
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Text.hpp"
#endif

class Cell {
private:
    sf::FloatRect mCellRect;
    bool mContainObstacle;
    int mHeatmapFactor;

#ifndef NDEBUG
    sf::RectangleShape mCellShape;
    sf::Text mHeatmapFactorText;
#endif

public:
#ifndef NDEBUG
    void draw(sf::RenderTarget& target, sf::RenderStates states);
#endif

    Cell();
    Cell(sf::FloatRect cellRect, bool state);
    void init(sf::FloatRect cellRect, bool containObstacle);
    bool doesContainObstacle() const;
    void setContainObstacleFlag(bool containObstacleFlag);
    void setContainObstacleFlag(sf::FloatRect obstacle);
    void setHeatmapFactor(int heatmapFactor);
    int getHeatmapFactor() const;

};

#endif //TEST_GAME_CELL_HPP
