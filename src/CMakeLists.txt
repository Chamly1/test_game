include_directories("${CMAKE_SOURCE_DIR}/external/SFML-2.5.1/include")
include_directories("${CMAKE_SOURCE_DIR}/include")
add_library(main_obj OBJECT
        GameEngine/SceneNodes/SceneNode.cpp GameEngine/SceneNodes/SpriteNode.cpp GameEngine/SceneNodes/CollidableNode.cpp
        GameEngine/Scenes/Scene.cpp GameEngine/Scenes/SceneList.cpp GameEngine/Scenes/SceneContext.cpp
        GameEngine/Commands/CommandQueue.cpp
        GameEngine/ResourceHolders/FontHolder.cpp GameEngine/ResourceHolders/TextureHolder.cpp
        GameEngine/GUI/Component.cpp GameEngine/GUI/Container.cpp
        GameEngine/Player.cpp
        GameEngine/Animation.cpp

        main.cpp Application.cpp World.cpp DataTables.cpp AnimationManager.cpp PlayerCamera.cpp
        SceneNodes/Entity.cpp SceneNodes/Unit.cpp
        Scenes/GameScene.cpp Scenes/TitleScene.cpp Scenes/MenuScene.cpp Scenes/PauseScene.cpp
        Utils/MapGenerateUtils.cpp Utils/DebugLog.cpp Utils/Utils.cpp
        GUI/Label.cpp GUI/Button.cpp GUI/ButtonList.cpp)