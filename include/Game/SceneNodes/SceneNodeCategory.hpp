#ifndef TEST_GAME_SCENENODECATEGORY_HPP
#define TEST_GAME_SCENENODECATEGORY_HPP

namespace SceneNodeCategory {

enum Type {
    None = 0,
    Scene = 1 << 0,
    PlayerUnit = 1 << 1,
    EnemyUnit = 1 << 2,
    Player = 1 << 3,
    ImpassableZone = 1 << 4,
    ImpassableUnit = 1 << 5
};

}

#endif //TEST_GAME_SCENENODECATEGORY_HPP
