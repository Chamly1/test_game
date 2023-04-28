#ifndef TEST_GAME_GAMESCENE_H
#define TEST_GAME_GAMESCENE_H

#include "GameEngine/Scenes/Scene.h"
#include "World.h"
#include "Player.h"

class GameScene : public Scene {
private:
    World world;
    Player player;

    void bindPlayerActions();

public:
    GameScene(SceneContext ctx, SceneList& sceneList);
    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event& event);
};

#endif //TEST_GAME_GAMESCENE_H
