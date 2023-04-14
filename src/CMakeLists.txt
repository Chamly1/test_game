include_directories("${CMAKE_SOURCE_DIR}/external/SFML-2.5.1/include")
include_directories("${CMAKE_SOURCE_DIR}/include")
add_library(main_obj OBJECT main.cpp Game.cpp DebugLog.cpp SceneNode.cpp World.cpp SpriteNode.cpp MapGenerateUtils.cpp Command.cpp CommandQueue.cpp Player.cpp
        Entities/Entity.cpp Entities/Unit.cpp
        ResourceHolders/FontHolder.cpp ResourceHolders/TextureHolder.cpp)