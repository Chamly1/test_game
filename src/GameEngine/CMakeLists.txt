add_library(game_engine_objlib OBJECT
        Application.cpp Player.cpp Animation.cpp Grid.cpp Cell.cpp
        SceneNodes/SceneNode.cpp SceneNodes/SpriteNode.cpp SceneNodes/CollidableNode.cpp
        Scenes/Scene.cpp Scenes/SceneList.cpp Scenes/SceneContext.cpp
        Commands/CommandQueue.cpp
        ResourceHolders/FontHolder.cpp ResourceHolders/TextureHolder.cpp
        GUI/Component.cpp GUI/Container.cpp
        Utils/DebugLog.cpp
        Utils/SceneNodeUtils.cpp)