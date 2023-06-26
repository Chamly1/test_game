#include "GameEngine/Cell.hpp"

#ifndef NDEBUG
#include "SFML/Graphics/RenderTarget.hpp"

static const float SHAPE_OUTLINE_THICKNESS = 1.f;
static const sf::Color SHAPE_OUTLINE_COLOR = sf::Color(255, 255, 255);
static const sf::Color SHAPE_ACTIVE_COLOR = sf::Color(255, 0, 0, 50);
static const sf::Color SHAPE_INACTIVE_COLOR = sf::Color(0, 255, 0, 50);

void Cell::draw(sf::RenderTarget& target, sf::RenderStates states) {
    mCellShape.setFillColor(mState ? SHAPE_ACTIVE_COLOR : SHAPE_INACTIVE_COLOR);

    states.transform *= getTransform();
    target.draw(mCellShape, states);
}
#endif

Cell::Cell(sf::FloatRect cellRect, bool state)
: mCellRect(cellRect)
, mState(state) {

#ifndef NDEBUG
    mCellShape = sf::RectangleShape(sf::Vector2f(cellRect.width, cellRect.height));
    mCellShape.setPosition(sf::Vector2f(cellRect.left, cellRect.top));
    mCellShape.setOutlineThickness(SHAPE_OUTLINE_THICKNESS);
    mCellShape.setOutlineColor(SHAPE_OUTLINE_COLOR);
#endif
}

Cell::Cell() : Cell(sf::FloatRect(), false) {

}

bool Cell::getState() const {
    return mState;
}

void Cell::setState(bool state) {
    mState = state;
}
