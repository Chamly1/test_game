#include "GameEngine/Grid.hpp"

#ifndef NDEBUG
void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) {
    for (int i = 0; i < mHeight; ++i) {
        for (int j = 0; j < mWidth; ++j) {
            mCellsMatrix[i][j].draw(target, states);
        }
    }
}
#endif

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
    for (int i = 0; i < mHeight; ++i) {
        mCellsMatrix[i] = new Cell[mWidth];
    }

    sf::FloatRect tmpFloatRect(0.f, 0.f, cellSize, cellSize);
    for (int i = 0; i < mHeight; ++i) {
        for (int j = 0; j < mWidth; ++j) {
            tmpFloatRect.top = cellSize * static_cast<float>(i);
            tmpFloatRect.left = cellSize * static_cast<float>(j);
            mCellsMatrix[i][j].init(tmpFloatRect, false);
        }
    }
}

Grid::~Grid() {
    for (int i = 0; i < mHeight; ++i) {
        delete[] mCellsMatrix[i];
    }
    delete[] mCellsMatrix;
}

void Grid::activateCells(sf::FloatRect intersectsWith) {
    for (int i = 0; i < mHeight; ++i) {
        for (int j = 0; j < mWidth; ++j) {
            mCellsMatrix[i][j].activateIfIntersect(intersectsWith);
        }
    }
}
