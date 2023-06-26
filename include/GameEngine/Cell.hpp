#ifndef TEST_GAME_CELL_HPP
#define TEST_GAME_CELL_HPP

#include "SFML/Graphics/Transformable.hpp"

class Cell : public sf::Transformable {
private:
    sf::FloatRect mCellRect;
    bool mState;

public:
    Cell(sf::FloatRect cellRect, bool state);
    bool getState() const;
    void setState(bool state);

};

#endif //TEST_GAME_CELL_HPP
