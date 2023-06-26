#include "GameEngine/Grid.hpp"

int getCellsNum(float start, float end, float cellSize) {
    float delta = end - start;
    int cellsNum = static_cast<int>(delta / cellSize);
    if ((delta - cellsNum * cellSize) > 0) {
        ++cellsNum;
    }
    return cellsNum;
}

Grid::Grid(const sf::Vector2f& start, const sf::Vector2f& end, float cellSize)
: mWidth(getCellsNum(start.x, end.x, cellSize))
, mHeight(getCellsNum(start.y, end.y, cellSize)) {

    mGridMatrix = new bool*[mHeight];
    for (int i = 0; i <= mHeight; ++i) {
        mGridMatrix[i] = new bool[mWidth]{};
    }

}

Grid::~Grid() {
    for (int i = 0; i <= mHeight; ++i) {
        delete[] mGridMatrix[i];
    }
    delete[] mGridMatrix;
}
