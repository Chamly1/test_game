#ifndef TEST_GAME_PAUSESCENE_H
#define TEST_GAME_PAUSESCENE_H

#include "Scenes/Scene.h"

#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

class PauseScene : public Scene {
private:
    sf::Text title;
    sf::RectangleShape backgroundShape;

public:
    PauseScene(SceneContext ctx, SceneList& sceneList);
    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event& event);
};

#endif //TEST_GAME_PAUSESCENE_H
