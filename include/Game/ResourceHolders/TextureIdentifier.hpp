#ifndef TEST_GAME_TEXTUREIDENTIFIER_HPP
#define TEST_GAME_TEXTUREIDENTIFIER_HPP

namespace TextureIdentifier {

enum id {
    MenuSelector,

    MapEmptyRoom,
    MapImpassableZonesEmptyRoom,
    MapNotEmptyRoom,
    MapImpassableZonesNotEmptyRoom,

    TileBlack,
    TileFlorDungeon,

    TileWallDungeonTopLeftCornerTopPart,
    TileWallDungeonTopRightCornerTopPart,

    TileWallDungeonBottomLeftCornerTopPart,
    TileWallDungeonBottomLeftCornerBottomPart,
    TileWallDungeonBottomRightCornerTopPart,
    TileWallDungeonBottomRightCornerBottomPart,

    TileWallDungeonMiddleTopPart,
    TileWallDungeonMiddleBottomPart,
    TileWallDungeonSidePart,

    HumanBaseIdleAnimation,
    HumanBaseWalkAnimation,
    HumanBaseAttackAnimation,

    ZombieIdleAnimation,
    ZombieWalkAnimation
};

}

#endif //TEST_GAME_TEXTUREIDENTIFIER_HPP
