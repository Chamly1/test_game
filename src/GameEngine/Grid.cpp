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
: mCellsMatrix(nullptr)
, mWidth(getCellsNum(start.x, end.x, cellSize))
, mHeight(getCellsNum(start.y, end.y, cellSize)) {

    mCellsMatrix = new Cell*[mHeight];
    for (int i = 0; i <= mHeight; ++i) {
        mCellsMatrix[i] = new Cell[mWidth];
    }

    sf::FloatRect tmpFloatRect(0.f, 0.f, cellSize, cellSize);
    for (int i = 0; i <= mHeight; ++i) {
        for (int j = 0; j <= mWidth; ++j) {
            tmpFloatRect.left = cellSize * mWidth;
            tmpFloatRect.top = cellSize * mHeight;
            mCellsMatrix[i][j].init(tmpFloatRect, false);
        }
    }
}

Grid::~Grid() {
    for (int i = 0; i <= mHeight; ++i) {
        delete[] mCellsMatrix[i];
    }
    delete[] mCellsMatrix;
}
