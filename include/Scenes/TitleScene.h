#ifndef TEST_GAME_TITLESCENE_H
#define TEST_GAME_TITLESCENE_H

#include "Scenes/Scene.h"

#include "SFML/Graphics/Text.hpp"

class TitleScene : public Scene {
private:
    sf::Text text;
    bool showText;
    sf::Time textEffectTime;

public:
    TitleScene(SceneContext ctx, SceneList& sceneList);
    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event& event);
};

#endif //TEST_GAME_TITLESCENE_H
