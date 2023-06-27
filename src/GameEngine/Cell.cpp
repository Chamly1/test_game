#include "GameEngine/Cell.hpp"

#ifndef NDEBUG
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Font.hpp"

#include <iostream>

static const float SHAPE_OUTLINE_THICKNESS = 1.f;
static const sf::Color SHAPE_OUTLINE_COLOR = sf::Color(255, 255, 255, 175);
static const sf::Color SHAPE_CONTAIN_OBSTACLE_COLOR = sf::Color(255, 0, 0, 50);
static const sf::Color SHAPE_DOES_NOT_CONTAIN_OBSTACLE_COLOR = sf::Color(0, 255, 0, 50);

static sf::Font cellFont;
static bool isCellFontLoaded;

static const unsigned int CHARACTER_SIZE = 10;
static const sf::Color TEXT_FILL_COLOR = sf::Color(255, 255, 255);
static const sf::Vector2f HEATMAP_FACTOR_TEXT_SHIFT = sf::Vector2f(5.f, 5.f);

void Cell::draw(sf::RenderTarget& target, sf::RenderStates states) {
//    mCellShape.setFillColor(mState ? SHAPE_ACTIVE_COLOR : SHAPE_INACTIVE_COLOR);
    if (mContainObstacle) {
        mCellShape.setFillColor(SHAPE_CONTAIN_OBSTACLE_COLOR);
    } else {
        mCellShape.setFillColor(SHAPE_DOES_NOT_CONTAIN_OBSTACLE_COLOR + sf::Color(0, 0, 0, mHeatmapFactor * 5));
    }

    mHeatmapFactorText.setString(std::to_string(mHeatmapFactor));

    target.draw(mCellShape, states);
    target.draw(mHeatmapFactorText, states);
}
#endif

Cell::Cell() : Cell(sf::FloatRect(), false) {

}

Cell::Cell(sf::FloatRect cellRect, bool state) {
    init(cellRect, state);
}

void Cell::init(sf::FloatRect cellRect, bool containObstacle) {
    mCellRect = cellRect;
    mContainObstacle = containObstacle;
    mHeatmapFactor = -1;

#ifndef NDEBUG
    mCellShape = sf::RectangleShape(sf::Vector2f(cellRect.width, cellRect.height));
    mCellShape.setPosition(sf::Vector2f(cellRect.left, cellRect.top));
    mCellShape.setOutlineThickness(SHAPE_OUTLINE_THICKNESS);
    mCellShape.setOutlineColor(SHAPE_OUTLINE_COLOR);

    if (isCellFontLoaded == false) {
        if (!cellFont.loadFromFile("resources/fonts/CONSOLA.TTF"))
        {
            std::cout << __FILE__ << ":" << __LINE__ << " font loading error!\n";
        }
    }

    mHeatmapFactorText.setFont(cellFont);
    mHeatmapFactorText.setCharacterSize(CHARACTER_SIZE);
    mHeatmapFactorText.setFillColor(TEXT_FILL_COLOR);
    mHeatmapFactorText.setPosition(mCellShape.getPosition() + HEATMAP_FACTOR_TEXT_SHIFT);

#endif
}

bool Cell::doesContainObstacle() const {
    return mContainObstacle;
}

void Cell::setContainObstacleFlag(bool containObstacleFlag) {
    mContainObstacle = containObstacleFlag;
}

void Cell::setContainObstacleFlag(sf::FloatRect obstacle) {
    if (mCellRect.intersects(obstacle)) {
        mContainObstacle = true;
    }
}

void Cell::setHeatmapFactor(int heatmapFactor) {
    mHeatmapFactor = heatmapFactor;
}

int Cell::getHeatmapFactor() const {
    return mHeatmapFactor;
}
