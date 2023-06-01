#include "Game/Scenes/TitleScene.hpp"
#include "Game/Utils/Utils.hpp"
#include "Game/ResourceHolders/FontIdentifier.hpp"
#include "Game/ResourceHolders/TextureIdentifier.hpp"
#include "Game/Scenes/SceneIdentifiers.hpp"

#include "SFML/Window.hpp"

static const float textBlinkingPeriodSec = 0.75f;

TitleScene::TitleScene(SceneContext ctx, SceneList& sceneList)
: Scene(ctx, sceneList)
, text()
, showText(true)
, textEffectTime() {

    ctx.fonts->load(FontIdentifier::Main, "resources/fonts/game_over.ttf");
    //TODO this texture must load somewhere else but not here
    ctx.textures->load(TextureIdentifier::MenuSelector,
                       "resources/textures/Minifantasy_Userinterface_Assets/Menus/Selectors/Minifantasy_GuiSelectors.png",
                       sf::IntRect(0, 16 * 20, 16, 16));

    text.setFont(ctx.fonts->get(FontIdentifier::Main));
    text.setString("Press any key to play");
    text.setCharacterSize(64);
    setOriginToCenter(text);
    text.setPosition(ctx.window->getView().getSize() / 2.f);
}
void TitleScene::draw() {
    if (showText) {
        getSceneContext().window->draw(text);
    }
}

bool TitleScene::update(sf::Time dt) {
    textEffectTime += dt;

    if (textEffectTime.asSeconds() >= textBlinkingPeriodSec) {
        showText = !showText;
        textEffectTime -= sf::seconds(textBlinkingPeriodSec);
    }

    return false;
}

bool TitleScene::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        requestListPopBack();
        requestListPushBack(SceneIdentifier::Menu);
    }

    return false;
}
