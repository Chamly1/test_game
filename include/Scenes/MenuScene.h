#ifndef TEST_GAME_MENUSCENE_H
#define TEST_GAME_MENUSCENE_H

#include "GameEngine/Scenes/Scene.h"
#include "GameEngine/GUI/Container.h"
#include "GUI/Label.h"
#include "GUI/ButtonList.h"

class MenuScene : public Scene {
private:
    GUI::Container guiContainer;

    std::shared_ptr<GUI::Label> createTitle(const sf::Font& font);
    std::shared_ptr<GUI::ButtonList> createButtons(const sf::Font& font, const sf::Texture& selectorTexture);

public:
    MenuScene(SceneContext ctx, SceneList& sceneList);
    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event& event);

};

#endif //TEST_GAME_MENUSCENE_H
