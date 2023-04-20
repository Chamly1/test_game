#include "Scenes/MenuScene.h"
#include "Utils/Utils.h"
#include "GUI/Label.h"
#include "GUI/Button.h"

const unsigned int titleCharacterSize = 128;
const unsigned int buttonsCharacterSize = 64;
const unsigned int pixelsBetweenOptions = 32;

std::shared_ptr<GUI::Label> MenuScene::createTitle(const std::string& titleName, const sf::Font& font) {
    std::shared_ptr<GUI::Label> title = std::make_shared<GUI::Label>(titleName, font);
    title->setPosition(getSceneContext().window->getView().getCenter());
    title->move(0, title->getPosition().y / -2);
    title->setCharacterSize(titleCharacterSize);

    return title;
}

std::shared_ptr<GUI::Button> MenuScene::createButton(const std::string& text, const sf::Font& font,
                                                     const sf::Texture& selectorTexture) {
    std::shared_ptr<GUI::Button> button = std::make_shared<GUI::Button>(text, font, selectorTexture);
    button->setPosition(getSceneContext().window->getView().getCenter());
    buttonsCount++;
    //TODO change pixels shift to relative
    button->move(0.f, pixelsBetweenOptions * buttonsCount);
    button->setCharacterSize(buttonsCharacterSize);

    return button;
}

MenuScene::MenuScene(SceneContext ctx, SceneList& sceneList)
: Scene(ctx, sceneList)
, guiContainer()
, buttonsCount(0) {

    const sf::Font& mainFont = ctx.fonts->get(FontIdentifier::Main);
    const sf::Texture& selectorTexture = ctx.textures->get(TextureIdentifier::MenuSelector);

    std::shared_ptr<GUI::Label> title = createTitle("test_game", mainFont);

    std::shared_ptr<GUI::Button> playButton = createButton("play", mainFont, selectorTexture);
    playButton->setCallback([this] () {
        requestListPopBack();
        requestListPushBack(SceneIdentifier::Game);
    });

    std::shared_ptr<GUI::Button> settingsButton = createButton("settings", mainFont, selectorTexture);

    std::shared_ptr<GUI::Button> exitButton = createButton("exit", mainFont, selectorTexture);
    exitButton->setCallback([this] () {
        requestListClear();
    });

    guiContainer.pushBack(title);
    guiContainer.pushBack(playButton);
    guiContainer.pushBack(settingsButton);
    guiContainer.pushBack(exitButton);
}

void MenuScene::draw() {
    sf::RenderWindow& window = *getSceneContext().window;
    window.draw(guiContainer);
}

bool MenuScene::update(sf::Time dt) {
    return false;
}

bool MenuScene::handleEvent(const sf::Event& event) {
    guiContainer.handleEvent(event);

    return false;
}
