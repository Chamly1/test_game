#ifndef TEST_GAME_TEXTUREIDENTIFIER_H
#define TEST_GAME_TEXTUREIDENTIFIER_H

namespace TextureIdentifier {

enum id {
    MenuSelector,

    MapEmptyRoom,
    MapImpassableZonesEmptyRoom,

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

    zombie,

    HumanBaseIdleAnimation,
    HumanBaseWalkAnimation
};

}

#endif //TEST_GAME_TEXTUREIDENTIFIER_H
