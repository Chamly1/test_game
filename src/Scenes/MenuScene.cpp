#include "Scenes/MenuScene.h"
#include "Utils/Utils.h"

const unsigned int titleCharacterSize = 128;
const unsigned int optionsCharacterSize = 64;
const unsigned int pixelsBetweenOptions = 32;

void MenuScene::setTitle(const std::string& titleName) {
    title.setFont(getSceneContext().fonts->get(FontIdentifier::Main));
    title.setString(titleName);
    title.setCharacterSize(titleCharacterSize);

    setOriginToCenter(title);
    title.setPosition(getSceneContext().window->getView().getCenter());
    title.move(0, title.getPosition().y / -2);
}

void MenuScene::addMenuOption(const std::string& optionName) {
    sf::Text optionText;
    optionText.setFont(getSceneContext().fonts->get(FontIdentifier::Main));
    optionText.setString(optionName);
    optionText.setCharacterSize(optionsCharacterSize);

    setOriginToCenter(optionText);
    optionText.setPosition(getSceneContext().window->getView().getCenter());
    optionText.move(optionText.getLocalBounds().width * 0.5f, pixelsBetweenOptions * options.size());

    options.push_back(optionText);
}

void MenuScene::updateSelector() {
    selector.setPosition(options[selectedOption].getPosition());
    selector.move(options[selectedOption].getLocalBounds().width * -0.5f, 0.f);
}

MenuScene::MenuScene(SceneContext ctx, SceneList& sceneList)
: Scene(ctx, sceneList)
, title()
, options()
, selector()
, selectedOption(0) {
    setTitle("test_game");
    addMenuOption("play");
    addMenuOption("settings");
    addMenuOption("exit");

    selector.setTexture(ctx.textures->get(TextureIdentifier::MenuSelector));
    selector.scale(2.f, 2.f);
    setOriginToCenter(selector);
    updateSelector();
}

void MenuScene::draw() {
    sf::RenderWindow& window = *getSceneContext().window;

    window.draw(title);
    for (const sf::Text& text : options) {
        window.draw(text);
    }
    window.draw(selector);
}

bool MenuScene::update(sf::Time dt) {
    return false;
}

bool MenuScene::handleEvent(const sf::Event& event) {
    if (event.type != sf::Event::KeyPressed) {
        return false;
    } else {
        switch (event.key.code) {
            case sf::Keyboard::Up:
                if (selectedOption > 0) {
                    selectedOption--;
                } else {
                    selectedOption = options.size() - 1;
                }
                updateSelector();
                break;

            case sf::Keyboard::Down:
                if (selectedOption < options.size() - 1) {
                    selectedOption++;
                } else {
                    selectedOption = 0;
                }
                updateSelector();
                break;

            case sf::Keyboard::Return:
                switch (selectedOption) {
                    case OptionNames::Play:
                        requestListPopBack();
                        requestListPushBack(SceneIdentifier::Game);
                        break;
                    case OptionNames::Exit:
                        requestListClear();
                        break;
                }
        }
    }

    return false;
}
