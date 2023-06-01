#include "GameEngine/Application.hpp"
#include "Game/Scenes/SceneIdentifiers.hpp"
#include "Game/Scenes/TitleScene.hpp"
#include "Game/Scenes/MenuScene.hpp"
#include "Game/Scenes/GameScene.hpp"
#include "Game/Scenes/PauseScene.hpp"

int main()
{

    Application app;

    app.registerScene<TitleScene>(SceneIdentifier::Title);
    app.registerScene<MenuScene>(SceneIdentifier::Menu);
    app.registerScene<GameScene>(SceneIdentifier::Game);
    app.registerScene<PauseScene>(SceneIdentifier::Pause);

    app.setStartScene(SceneIdentifier::Title);

    app.run();

    return 0;
}
