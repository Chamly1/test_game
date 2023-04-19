#include "Scenes/PauseScene.h"
#include "Utils/Utils.h"

const unsigned int titleCharacterSize = 128;

PauseScene::PauseScene(SceneContext ctx, SceneList& sceneList)
: Scene(ctx, sceneList)
, title()
, backgroundShape() {
    title.setFont(getSceneContext().fonts->get(FontIdentifier::Main));
    title.setString("Pause");
    title.setCharacterSize(titleCharacterSize);
    setOriginToCenter(title);
    title.setPosition(getSceneContext().window->getView().getCenter());
    title.move(0, title.getPosition().y / -2);

    backgroundShape.setFillColor(sf::Color(0, 0, 0, 150));
    backgroundShape.setSize(ctx.window->getView().getSize());
}

void PauseScene::draw() {
    sf::RenderWindow& window = *getSceneContext().window;

    window.draw(backgroundShape);
    window.draw(title);
}

bool PauseScene::update(sf::Time dt) {
    return false;
}

bool PauseScene::handleEvent(const sf::Event& event) {
    if (event.type != sf::Event::KeyPressed) {
        return false;
    }

    switch (event.key.code) {
        case sf::Keyboard::Escape:
            requestListPopBack();
            break;
    }

    return false;
}
