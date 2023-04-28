#ifndef TEST_GAME_SCENENODECATEGORY_H
#define TEST_GAME_SCENENODECATEGORY_H

namespace SceneNodeCategory {
    enum Type {
        None = 0,
        Scene = 1 << 0,
        PlayerUnit = 1 << 1,
        EnemyUnit = 1 << 2,
        Player = 1 << 3,
        ImpassableZone = 1 << 4
    };
}

#endif //TEST_GAME_SCENENODECATEGORY_H
