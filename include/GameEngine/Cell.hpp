#ifndef TEST_GAME_CELL_HPP
#define TEST_GAME_CELL_HPP

#include "SFML/Graphics/Transformable.hpp"

#ifndef NDEBUG
#include "SFML/Graphics/RectangleShape.hpp"
#endif

class Cell : public sf::Transformable {
private:
    sf::FloatRect mCellRect;
    bool mState;

#ifndef NDEBUG
    sf::RectangleShape mCellShape;

    void draw(sf::RenderTarget& target, sf::RenderStates states);
#endif

public:
    Cell(sf::FloatRect cellRect, bool state);
    Cell();
    bool getState() const;
    void setState(bool state);

};

#endif //TEST_GAME_CELL_HPP
