#include "Game/Scenes/PauseScene.hpp"
#include "Game/Utils/Utils.hpp"
#include "Game/ResourceHolders/FontIdentifier.hpp"
#include "Game/ResourceHolders/TextureIdentifier.hpp"
#include "Game/Scenes/SceneIdentifiers.hpp"

const unsigned int titleCharacterSize = 128;
const unsigned int buttonsCharacterSize = 64;

std::shared_ptr<GUI::Label> PauseScene::createTitle(const sf::Font& font) {
    std::shared_ptr<GUI::Label> title = std::make_shared<GUI::Label>("Pause", font);
    title->setPosition(getSceneContext().window->getView().getCenter());
    title->move(0, title->getPosition().y / -2);
    title->setCharacterSize(titleCharacterSize);

    return title;
}

std::shared_ptr<GUI::ButtonList> PauseScene::createButtons(const sf::Font& font, const sf::Texture& selectorTexture) {
    std::shared_ptr<GUI::ButtonList> buttons = std::make_shared<GUI::ButtonList>(buttonsCharacterSize, font, selectorTexture);
    buttons->setPosition(getSceneContext().window->getView().getCenter());

    buttons->addButton("resume", [this] () {
        requestListPopBack();
    });

    buttons->addButton("settings", [this] () {

    });

    buttons->addButton("quit to main menu", [this] () {
        requestListClear();
        requestListPushBack(SceneIdentifier::Menu);
    });

    buttons->addButton("quit to desktop", [this] () {
        requestListClear();
    });

    return buttons;
}

PauseScene::PauseScene(SceneContext ctx, SceneList& sceneList)
: Scene(ctx, sceneList)
, guiContainer()
, backgroundShape() {
    const sf::Font& mainFont = ctx.fonts->get(FontIdentifier::Main);
    const sf::Texture& selectorTexture = ctx.textures->get(TextureIdentifier::MenuSelector);

    std::shared_ptr<GUI::Label> title = createTitle(mainFont);

    std::shared_ptr<GUI::ButtonList> buttons = createButtons(mainFont, selectorTexture);
    buttons->activate();

    guiContainer.pushBack(title);
    guiContainer.pushBack(buttons);

    backgroundShape.setFillColor(sf::Color(0, 0, 0, 150));
    backgroundShape.setSize(ctx.window->getView().getSize());
}

void PauseScene::draw() {
    sf::RenderWindow& window = *getSceneContext().window;

    window.draw(backgroundShape);
    window.draw(guiContainer);
}

bool PauseScene::update(sf::Time dt) {
    return false;
}

bool PauseScene::handleEvent(const sf::Event& event) {
    guiContainer.handleEvent(event);

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        requestListPopBack();
    }

    return false;
}
