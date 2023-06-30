#ifndef TEST_GAME_ZOMBIEAI_HPP
#define TEST_GAME_ZOMBIEAI_HPP

#include "GameEngine/AI.hpp"
#include "GameEngine/VectorFieldGrid.hpp"

#include "SFML/Graphics/VertexArray.hpp"

class ZombieAI : public AI {
private:
    std::shared_ptr<const VectorFieldGrid> mGrid;

public:
    ZombieAI(std::shared_ptr<const VectorFieldGrid> grid);
    virtual bool checkCompatibilities(SceneNode& sceneNode);
    virtual void update(sf::Time dt, SceneNode* sceneNode);

};

#endif //TEST_GAME_ZOMBIEAI_HPP
