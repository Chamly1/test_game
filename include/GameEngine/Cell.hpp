#ifndef TEST_GAME_CELL_HPP
#define TEST_GAME_CELL_HPP

#include "SFML/Graphics/Rect.hpp"

#ifndef NDEBUG
#include "SFML/Graphics/RectangleShape.hpp"
#endif

class Cell {
private:
    sf::FloatRect mCellRect;
    bool mState;

#ifndef NDEBUG
    sf::RectangleShape mCellShape;
#endif

public:
#ifndef NDEBUG
    void draw(sf::RenderTarget& target, sf::RenderStates states);
#endif

    Cell(sf::FloatRect cellRect, bool state);
    Cell();
    void init(sf::FloatRect cellRect, bool state);
    bool getState() const;
    void setState(bool state);

};

#endif //TEST_GAME_CELL_HPP
