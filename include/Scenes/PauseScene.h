#ifndef TEST_GAME_PAUSESCENE_H
#define TEST_GAME_PAUSESCENE_H

#include "GameEngine/Scenes/Scene.h"
#include "GameEngine/GUI/Container.h"
#include "GUI/Label.h"
#include "GUI/ButtonList.h"

#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

class PauseScene : public Scene {
private:
    GUI::Container guiContainer;
    sf::RectangleShape backgroundShape;

    std::shared_ptr<GUI::Label> createTitle(const sf::Font& font);
    std::shared_ptr<GUI::ButtonList> createButtons(const sf::Font& font, const sf::Texture& selectorTexture);

public:
    PauseScene(SceneContext ctx, SceneList& sceneList);
    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event& event);
};

#endif //TEST_GAME_PAUSESCENE_H
