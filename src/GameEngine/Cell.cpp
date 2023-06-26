#include "GameEngine/Cell.hpp"

Cell::Cell(sf::FloatRect cellRect, bool state)
: mCellRect(cellRect)
, mState(state) {

}

bool Cell::getState() const {
    return mState;
}

void Cell::setState(bool state) {
    mState = state;
}
