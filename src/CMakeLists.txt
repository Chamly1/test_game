include_directories("${CMAKE_SOURCE_DIR}/external/SFML-2.5.1/include")
include_directories("${CMAKE_SOURCE_DIR}/include")
add_library(main_obj OBJECT
        GameEngine/Application.cpp
        GameEngine/SceneNodes/SceneNode.cpp GameEngine/SceneNodes/SpriteNode.cpp GameEngine/SceneNodes/CollidableNode.cpp
        GameEngine/Scenes/Scene.cpp GameEngine/Scenes/SceneList.cpp GameEngine/Scenes/SceneContext.cpp
        GameEngine/Commands/CommandQueue.cpp
        GameEngine/ResourceHolders/FontHolder.cpp GameEngine/ResourceHolders/TextureHolder.cpp
        GameEngine/GUI/Component.cpp GameEngine/GUI/Container.cpp
        GameEngine/Player.cpp
        GameEngine/Animation.cpp
        GameEngine/Utils/DebugLog.cpp

        main.cpp

        Game/World.cpp Game/DataTables.cpp Game/AnimationManager.cpp Game/PlayerCamera.cpp
        Game/SceneNodes/Entity.cpp Game/SceneNodes/Unit.cpp
        Game/Scenes/GameScene.cpp Game/Scenes/TitleScene.cpp Game/Scenes/MenuScene.cpp Game/Scenes/PauseScene.cpp
        Game/Utils/MapGenerateUtils.cpp Game/Utils/Utils.cpp
        Game/GUI/Label.cpp Game/GUI/Button.cpp Game/GUI/ButtonList.cpp)