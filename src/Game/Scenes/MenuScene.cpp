#include "Game/Scenes/MenuScene.hpp"
#include "Game/Utils/Utils.hpp"
#include "Game/GUI/Label.hpp"
#include "Game/ResourceHolders/FontIdentifier.hpp"
#include "Game/ResourceHolders/TextureIdentifier.hpp"
#include "Game/Scenes/SceneIdentifiers.hpp"

const unsigned int titleCharacterSize = 128;
const unsigned int buttonsCharacterSize = 64;

std::shared_ptr<GUI::Label> MenuScene::createTitle(const sf::Font& font) {
    std::shared_ptr<GUI::Label> title = std::make_shared<GUI::Label>("test_game", font);
    title->setPosition(getSceneContext().window->getView().getCenter());
    title->move(0, title->getPosition().y / -2);
    title->setCharacterSize(titleCharacterSize);

    return title;
}

std::shared_ptr<GUI::ButtonList> MenuScene::createButtons(const sf::Font& font, const sf::Texture& selectorTexture) {
    std::shared_ptr<GUI::ButtonList> buttons = std::make_shared<GUI::ButtonList>(buttonsCharacterSize, font, selectorTexture);
    buttons->setPosition(getSceneContext().window->getView().getCenter());

    buttons->addButton("play", [this] () {
        requestListPopBack();
        requestListPushBack(SceneIdentifier::Game);
    });

    buttons->addButton("settings", [this] () {

    });

    buttons->addButton("quit to desktop", [this] () {
        requestListClear();
    });

    return buttons;
}

MenuScene::MenuScene(SceneContext ctx, SceneList& sceneList)
: Scene(ctx, sceneList)
, guiContainer() {

    const sf::Font& mainFont = ctx.fonts->get(FontIdentifier::Main);
    const sf::Texture& selectorTexture = ctx.textures->get(TextureIdentifier::MenuSelector);

    std::shared_ptr<GUI::Label> title = createTitle(mainFont);

    std::shared_ptr<GUI::ButtonList> buttons = createButtons(mainFont, selectorTexture);
    buttons->activate();

    guiContainer.pushBack(title);
    guiContainer.pushBack(buttons);
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
