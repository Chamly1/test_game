#ifndef TEST_GAME_MENUSCENE_H
#define TEST_GAME_MENUSCENE_H

#include "Scenes/Scene.h"
#include "GUI/Container.h"
#include "GUI/Label.h"
#include "GUI/Button.h"

class MenuScene : public Scene {
private:
    GUI::Container guiContainer;
    int buttonsCount;

    std::shared_ptr<GUI::Label> createTitle(const std::string& titleName, const sf::Font& font);
    std::shared_ptr<GUI::Button> createButton(const std::string& text, const sf::Font& font,
                                              const sf::Texture& selectorTexture);

public:
    MenuScene(SceneContext ctx, SceneList& sceneList);
    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event& event);

};

#endif //TEST_GAME_MENUSCENE_H
