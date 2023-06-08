#ifndef TEST_GAME_ZOMBIEAI_HPP
#define TEST_GAME_ZOMBIEAI_HPP

#include "GameEngine/AI.hpp"

#include "SFML/Graphics/VertexArray.hpp"

class ZombieAI : public AI {
private:
    const SceneNode* mPlayerNodePtr;

protected:
    void drawVisionRay(sf::RenderTarget& target, const SceneNode* zombieSceneNode) const;

public:
    virtual bool checkCompatibilities(SceneNode& sceneNode);
    virtual void update(sf::Time dt, SceneNode* sceneNode);

};

#endif //TEST_GAME_ZOMBIEAI_HPP
