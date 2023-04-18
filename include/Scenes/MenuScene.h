#ifndef TEST_GAME_MENUSCENE_H
#define TEST_GAME_MENUSCENE_H

#include "Scenes/Scene.h"

#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/Sprite.hpp"

class MenuScene : public Scene {
private:
    enum OptionNames {
        Play,
        Settings,
        Exit
    };

    sf::Text title;
    std::vector<sf::Text> options;
    sf::Sprite selector;
    int selectedOption;

    void setTitle(const std::string& titleName);
    void addMenuOption(const std::string& optionName);
    void updateSelector();

public:
    MenuScene(SceneContext ctx, SceneList& sceneList);
    virtual void draw();
    virtual bool update(sf::Time dt);
    virtual bool handleEvent(const sf::Event& event);

};

#endif //TEST_GAME_MENUSCENE_H
