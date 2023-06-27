#include "GameEngine/Grid.hpp"

#include <cassert>
#include <queue>

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
: mPosition(position)
, mCellSize(cellSize)
, mCellsMatrix(nullptr)
, mWidth(getCellsNum(position.x, position.x + size.x, cellSize))
, mHeight(getCellsNum(position.y, position.y + size.y, cellSize)) {

    assert(size.x > 0.f && size.y > 0.f);

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

void Grid::updateHeatmapFactor(int x, int y, int newHeatmapFactor, std::queue<sf::Vector2i>& lastUpdatedCells) {
    if (x >= 0 && y >= 0 &&
        x < mWidth && y < mHeight) {

        if (mCellsMatrix[y][x].getHeatmapFactor() == -1 &&
            mCellsMatrix[y][x].getState() == false) {
            mCellsMatrix[y][x].setHeatmapFactor(newHeatmapFactor);
            lastUpdatedCells.push(sf::Vector2i(x, y));
        }

    }
}

void Grid::updateHeatmap(const sf::Vector2f& goal) {

    assert(goal.x > 0.f && goal.y > 0.f);
    assert(goal.x < mWidth * mCellSize && goal.y < mHeight * mCellSize);

    // reset heatmap factors
    for (int i = 0; i < mHeight; ++i) {
        for (int j = 0; j < mWidth; ++j) {
            mCellsMatrix[i][j].setHeatmapFactor(-1);
        }
    }

    int goalCellX = getCellsNum(mPosition.x, goal.x, mCellSize) - 1;
    int goalCellY = getCellsNum(mPosition.y, goal.y, mCellSize) - 1;

    std::queue<sf::Vector2i> lastUpdatedCells;
    lastUpdatedCells.push(sf::Vector2i(goalCellX, goalCellY));
    mCellsMatrix[goalCellY][goalCellX].setHeatmapFactor(0);

    int tmpHeatmapFactor;
    int tmpX, tmpY;
    while (!lastUpdatedCells.empty()) {
        tmpX = lastUpdatedCells.front().x;
        tmpY = lastUpdatedCells.front().y;
        tmpHeatmapFactor = mCellsMatrix[tmpY][tmpX].getHeatmapFactor() + 1;

        updateHeatmapFactor(tmpX + 1, tmpY, tmpHeatmapFactor, lastUpdatedCells);
        updateHeatmapFactor(tmpX - 1, tmpY, tmpHeatmapFactor, lastUpdatedCells);
        updateHeatmapFactor(tmpX, tmpY + 1, tmpHeatmapFactor, lastUpdatedCells);
        updateHeatmapFactor(tmpX, tmpY - 1, tmpHeatmapFactor, lastUpdatedCells);

        lastUpdatedCells.pop();
    }
}
