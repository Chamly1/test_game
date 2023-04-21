#ifndef TEST_GAME_TEXTUREHOLDER_H
#define TEST_GAME_TEXTUREHOLDER_H

#include "SFML/Graphics/Texture.hpp"

#include <map>
#include <memory>

enum class TextureIdentifier {
    MenuSelector,

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

    HumanBaseIdleAnimation
};

class TextureHolder {
private:
    std::map<TextureIdentifier, std::unique_ptr<sf::Texture>> textureMap;

public:
    void load(TextureIdentifier id, const std::string& filePath, const sf::IntRect& area = sf::IntRect());
    const sf::Texture& get(TextureIdentifier id) const;
};

#endif //TEST_GAME_TEXTUREHOLDER_H
