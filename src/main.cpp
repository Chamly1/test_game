#include "GameEngine/Application.h"
#include "Scenes/SceneIdentifiers.h"
#include "Scenes/TitleScene.h"
#include "Scenes/MenuScene.h"
#include "Scenes/GameScene.h"
#include "Scenes/PauseScene.h"

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
