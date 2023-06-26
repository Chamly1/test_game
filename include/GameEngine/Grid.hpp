#ifndef TEST_GAME_GRID_HPP
#define TEST_GAME_GRID_HPP

#include "GameEngine/Cell.hpp"

#include "SFML/Graphics/Transformable.hpp"

class Grid : public sf::Transformable {
private:
    Cell** mCellsMatrix;
    int mWidth;
    int mHeight;

public:
#ifndef NDEBUG
    void draw(sf::RenderTarget& target, sf::RenderStates states);
#endif

    Grid(const sf::Vector2f& start, const sf::Vector2f& end, float cellSize);
    ~Grid();

};

#endif //TEST_GAME_GRID_HPP
