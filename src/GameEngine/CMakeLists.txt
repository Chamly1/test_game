add_library(game_engine_objlib OBJECT
        Application.cpp Player.cpp Animation.cpp VectorFieldGrid.cpp VectorFieldCell.cpp
        SceneNodes/SceneNode.cpp SceneNodes/SpriteNode.cpp SceneNodes/CollidableNode.cpp SceneNodes/MovableNode.cpp SceneNodes/AttackableNode.cpp SceneNodes/DamageableNode.cpp
        Scenes/Scene.cpp Scenes/SceneList.cpp Scenes/SceneContext.cpp
        Commands/CommandQueue.cpp
        ResourceHolders/FontHolder.cpp ResourceHolders/TextureHolder.cpp
        GUI/Component.cpp GUI/Container.cpp
        Utils/DebugLog.cpp
        Utils/SceneNodeUtils.cpp
        Utils/PerformanceStatisticManager.cpp
        Utils/UtilsFunctions.cpp)