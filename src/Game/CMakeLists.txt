add_library(game_objlib OBJECT
        main.cpp
        World.cpp DataTables.cpp AnimationManager.cpp PlayerCamera.cpp
        SceneNodes/MovableNode.cpp SceneNodes/Unit.cpp SceneNodes/NPCs/ZombieNPC.cpp
        Scenes/GameScene.cpp Scenes/TitleScene.cpp Scenes/MenuScene.cpp Scenes/PauseScene.cpp
        Utils/MapGenerateUtils.cpp Utils/Utils.cpp
        GUI/Label.cpp GUI/Button.cpp GUI/ButtonList.cpp
        AIs/ZombieAI.cpp
        )