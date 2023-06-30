#ifndef TEST_GAME_ZOMBIEAI_HPP
#define TEST_GAME_ZOMBIEAI_HPP

#include "GameEngine/AI.hpp"
#include "GameEngine/Grid.hpp"

#include "SFML/Graphics/VertexArray.hpp"

class ZombieAI : public AI {
private:
    sf::Vector2f mPlayerPosition;
    std::shared_ptr<const Grid> mGrid;

protected:
    void drawVisionRay(sf::RenderTarget& target, const SceneNode* zombieSceneNode) const;

public:
    ZombieAI(std::shared_ptr<const Grid> grid);
    virtual bool checkCompatibilities(SceneNode& sceneNode);
    virtual void update(sf::Time dt, SceneNode* sceneNode);

};

#endif //TEST_GAME_ZOMBIEAI_HPP
