#ifndef TEST_GAME_MENUSCENE_HPP
#define TEST_GAME_MENUSCENE_HPP

#include "GameEngine/Scenes/Scene.hpp"
#include "GameEngine/GUI/Container.hpp"
#include "Game/GUI/Label.hpp"
#include "Game/GUI/ButtonList.hpp"

class MenuScene : public Scene {
private:
    GUI::Container mGuiContainer;

    std::shared_ptr<GUI::Label> createTitle(const sf::Font& font);
    std::shared_ptr<GUI::ButtonList> createButtons(const sf::Font& font, const sf::Texture& selectorTexture);

public:
    MenuScene(SceneContext ctx, SceneList& sceneList);
    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event& event);

};

#endif //TEST_GAME_MENUSCENE_HPP
