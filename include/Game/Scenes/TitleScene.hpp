#ifndef TEST_GAME_TITLESCENE_HPP
#define TEST_GAME_TITLESCENE_HPP

#include "GameEngine/Scenes/Scene.hpp"

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

#endif //TEST_GAME_TITLESCENE_HPP
