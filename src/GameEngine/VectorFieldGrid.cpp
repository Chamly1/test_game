#include "GameEngine/VectorFieldGrid.hpp"

#include <cassert>
#include <queue>

#ifndef NDEBUG
void VectorFieldGrid::draw(sf::RenderTarget& target, sf::RenderStates states) {
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

VectorFieldGrid::VectorFieldGrid(const sf::Vector2f& position, const sf::Vector2f& size, float cellSize)
: mPosition(position)
, mCellSize(cellSize)
, mCellsMatrix(nullptr)
, mWidth(getCellsNum(position.x, position.x + size.x, cellSize))
, mHeight(getCellsNum(position.y, position.y + size.y, cellSize)) {

    assert(size.x > 0.f && size.y > 0.f);

    mCellsMatrix = new VectorFieldCell*[mHeight];
    for (int i = 0; i < mHeight; ++i) {
        mCellsMatrix[i] = new VectorFieldCell[mWidth];
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

VectorFieldGrid::~VectorFieldGrid() {
    for (int i = 0; i < mHeight; ++i) {
        delete[] mCellsMatrix[i];
    }
    delete[] mCellsMatrix;
}

void VectorFieldGrid::setContainObstacleFlags(sf::FloatRect intersectsWith) {
    for (int i = 0; i < mHeight; ++i) {
        for (int j = 0; j < mWidth; ++j) {
            mCellsMatrix[i][j].setContainObstacleFlag(intersectsWith);
        }
    }
}

void VectorFieldGrid::updateHeatmapFactor(int x, int y, int newHeatmapFactor, std::queue<sf::Vector2i>& lastUpdatedCells) {
    if (x >= 0 && y >= 0 &&
        x < mWidth && y < mHeight) {

        if (mCellsMatrix[y][x].getHeatmapFactor() == -1 &&
            mCellsMatrix[y][x].doesContainObstacle() == false) {
            mCellsMatrix[y][x].setHeatmapFactor(newHeatmapFactor);
            lastUpdatedCells.push(sf::Vector2i(x, y));
        }

    }
}

bool VectorFieldGrid::isPointLiesOnGrid(const sf::Vector2f& point) const {
    return point.x > 0.f && point.y > 0.f &&
           point.x < mWidth * mCellSize && point.y < mHeight * mCellSize;
}

void VectorFieldGrid::updateHeatmap(const sf::Vector2f& goal) {

    assert(isPointLiesOnGrid(goal));

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

int VectorFieldGrid::getHeatmapFactor(int x, int y) {
    if (x >= 0 && y >= 0 &&
        x < mWidth && y < mHeight) {
        return mCellsMatrix[y][x].getHeatmapFactor();
    } else {
        return -1;
    };
}

void VectorFieldGrid::getMinHeatmapFactorNeighbor(int x, int y, int& neighborX, int& neighborY) {
    int minHeatmapFactor = getHeatmapFactor(x, y);
    neighborX = x;
    neighborY = y;

    int currentHeatmapFactor;

    for (int i = x - 1; i <= x + 1; ++i) {
        for (int j = y - 1; j <= y + 1; ++j) {
            currentHeatmapFactor = getHeatmapFactor(i, j);
            if (currentHeatmapFactor == -1) {
                continue;
            }

            if (currentHeatmapFactor <= minHeatmapFactor) {
                minHeatmapFactor = currentHeatmapFactor;
                neighborX = i;
                neighborY = j;
            }
        }
    }
}

void VectorFieldGrid::updateVectorField() {
    int neighborX, neighborY;

    sf::Vector2f tmpFieldVector;
    for (int i = 0; i < mHeight; ++i) {
        for (int j = 0; j < mWidth; ++j) {
            if (mCellsMatrix[i][j].doesContainObstacle()) {
                continue;
            }

            getMinHeatmapFactorNeighbor(j, i, neighborX, neighborY);
            mCellsMatrix[i][j].setNextCellCenter(mCellsMatrix[neighborY][neighborX].getCellCenter());

            tmpFieldVector.x = static_cast<float>(neighborX - j);
            tmpFieldVector.y = static_cast<float>(neighborY - i);
            mCellsMatrix[i][j].setFieldVector(tmpFieldVector);
        }
    }
}

sf::Vector2f VectorFieldGrid::getFieldVectorInPoint(const sf::Vector2f& point) const {
    assert(isPointLiesOnGrid(point));

    int pointCellX = getCellsNum(mPosition.x, point.x, mCellSize) - 1;
    int pointCellY = getCellsNum(mPosition.y, point.y, mCellSize) - 1;

    return mCellsMatrix[pointCellY][pointCellX].getFieldVector();
}

sf::Vector2f VectorFieldGrid::getNextCellCenterInPoint(const sf::Vector2f& point) const {
    assert(isPointLiesOnGrid(point));

    int pointCellX = getCellsNum(mPosition.x, point.x, mCellSize) - 1;
    int pointCellY = getCellsNum(mPosition.y, point.y, mCellSize) - 1;

    return mCellsMatrix[pointCellY][pointCellX].getNextCellCenter();
}
