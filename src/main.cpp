#include "GameEngine/Application.h"
#include "Game/Scenes/SceneIdentifiers.h"
#include "Game/Scenes/TitleScene.h"
#include "Game/Scenes/MenuScene.h"
#include "Game/Scenes/GameScene.h"
#include "Game/Scenes/PauseScene.h"

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
