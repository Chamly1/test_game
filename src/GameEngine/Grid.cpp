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

/**
 * Return number of cells required to cover the segment's length.
 *
 * @param start segment's start.
 * @param end segment's end.
 * @param cellSize cell's size
 *
 * @return number of cells.
 */
int getCellsNum(float start, float end, float cellSize) {
    float delta = end - start;
    int cellsNum = static_cast<int>(delta / cellSize);
    if ((delta - cellsNum * cellSize) > 0) {
        ++cellsNum;
    }
    return cellsNum;
}

Grid::Grid(const sf::Vector2f& position, const sf::Vector2f& size, float cellSize)
: mCellsMatrix(nullptr)
, mWidth(getCellsNum(position.x, position.x + size.x, cellSize))
, mHeight(getCellsNum(position.y, position.y + size.y, cellSize)) {

    mCellsMatrix = new Cell*[mHeight];
    for (int i = 0; i < mHeight; ++i) {
        mCellsMatrix[i] = new Cell[mWidth];
    }

    sf::FloatRect tmpFloatRect(0.f, 0.f, cellSize, cellSize);
    for (int i = 0; i < mHeight; ++i) {
        for (int j = 0; j < mWidth; ++j) {
            tmpFloatRect.top = cellSize * static_cast<float>(i) + position.y;
            tmpFloatRect.left = cellSize * static_cast<float>(j) + position.x;
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
