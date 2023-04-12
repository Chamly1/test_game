#include "MapGenerateUtils.h"

std::vector<std::vector<int>> intStringToVector (const std::string& str) {
    int rows, columns;
    rows = std::count(str.begin(), str.end(), '\n');
    columns = std::count(str.begin(), str.end(), ',') / rows;

    std::vector<std::vector<int>> resVector(rows);
    for (int i = 0; i < rows; i++) {
        resVector[i] = std::vector<int>(columns);
    }

    int from = 0, to = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            to = str.find(',', from);

            resVector[i][j] = stoi(str.substr(from, to - from));

            from = to + 1;
        }
    }

    return resVector;
}

static TextureIdentifier vectorNumToTextureID(const std::vector<std::vector<int>>& vec, int row, int column) {
    switch (vec[row][column]) {
        case 0:
            return TextureIdentifier::TileBlack;
        case 1:
            return TextureIdentifier::TileFlorDungeon;
        case 2:
            //TODO
        default:
            return TextureIdentifier::TileBlack;
    }
}

std::unique_ptr<SceneNode> generateMapFromVector(const std::vector<std::vector<int>>& vec, const TextureHolder& textures) {
    std::unique_ptr<SceneNode> map(new SceneNode());

    std::unique_ptr<SceneNode> tmpMapRow;
    std::unique_ptr<SpriteNode> tmpMapSprite;
    for (int i = 0; i < vec.size(); i++) {
        tmpMapRow = std::make_unique<SceneNode>();
        tmpMapRow->move(0.f, 8.f * i);
        for (int j = 0; j < vec[i].size(); j++) {
            tmpMapSprite = std::make_unique<SpriteNode>(textures.get(vectorNumToTextureID(vec, i, j)));
            tmpMapSprite->move(8.f * j, 0.f);

            tmpMapRow->attachChild(std::move(tmpMapSprite));
        }

        map->attachChild(std::move(tmpMapRow));
    }

    return map;
}

std::unique_ptr<SceneNode> generateMapFromString(const std::string& str, const TextureHolder& textures) {
    std::vector<std::vector<int>> vec = intStringToVector(str);
    return generateMapFromVector(vec, textures);
}
