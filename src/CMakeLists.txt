include_directories("${CMAKE_SOURCE_DIR}/external/SFML-2.5.1/include")
include_directories("${CMAKE_SOURCE_DIR}/include")
add_library(main_obj OBJECT
        GameEngine/ResourceHolders/FontHolder.cpp GameEngine/ResourceHolders/TextureHolder.cpp
        GameEngine/GUI/Component.cpp GameEngine/GUI/Container.cpp

        main.cpp Application.cpp World.cpp  Command.cpp CommandQueue.cpp Player.cpp Animation.cpp DataTables.cpp AnimationManager.cpp PlayerCamera.cpp
        SceneNodes/SceneNode.cpp SceneNodes/SpriteNode.cpp SceneNodes/Entity.cpp SceneNodes/Unit.cpp SceneNodes/CollidableNode.cpp
        Scenes/Scene.cpp Scenes/SceneList.cpp Scenes/SceneContext.cpp Scenes/GameScene.cpp Scenes/TitleScene.cpp Scenes/MenuScene.cpp Scenes/PauseScene.cpp
        Utils/MapGenerateUtils.cpp Utils/DebugLog.cpp Utils/Utils.cpp
        GUI/Label.cpp GUI/Button.cpp GUI/ButtonList.cpp)