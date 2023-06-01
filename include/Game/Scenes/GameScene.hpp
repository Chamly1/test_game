#ifndef TEST_GAME_GAMESCENE_HPP
#define TEST_GAME_GAMESCENE_HPP

#include "GameEngine/Scenes/Scene.hpp"
#include "Game/World.hpp"
#include "GameEngine/Player.hpp"

class GameScene : public Scene {
private:
    World mWorld;
    Player mPlayer;

    void bindPlayerActions();

public:
    GameScene(SceneContext ctx, SceneList& sceneList);
    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event& event);
};

#endif //TEST_GAME_GAMESCENE_HPP
