#ifndef TEST_GAME_MAPGENERATEUTILS_H
#define TEST_GAME_MAPGENERATEUTILS_H

#include "SceneNodes/SceneNode.h"
#include "GameEngine/ResourceHolders/TextureHolder.h"

const std::string testMapStr1= "0, 0, 0, 0, 0, 0, 0, 0, 0,\n"
                               "0, 2, 2, 2, 2, 2, 2, 2, 0,\n"
                               "0, 2, 2, 2, 2, 2, 2, 2, 0,\n"
                               "0, 2, 1, 1, 1, 1, 1, 2, 0,\n"
                               "0, 2, 1, 1, 1, 1, 1, 2, 0,\n"
                               "0, 2, 1, 1, 1, 1, 1, 2, 0,\n"
                               "0, 2, 1, 1, 1, 1, 1, 2, 0,\n"
                               "0, 2, 1, 1, 1, 1, 1, 2, 0,\n"
                               "0, 2, 2, 2, 2, 2, 2, 2, 0,\n"
                               "0, 2, 2, 2, 2, 2, 2, 2, 0,\n"
                               "0, 0, 0, 0, 0, 0, 0, 0, 0,\n";

/**
 * Convert string representation of a two dimensional matrix array to vector.
 * Rows MUST be separated by '\n' symbol. Numbers in a row MUST be separated by coma.
 * At the end of EVERY row MUST be '\n' and after EVERY number MUST be coma.
 * Number of spaces between numbers doesn't matter.
 *
 * Example:
 *
 * string str = "1,  2,  3,  4,\n"
 *              "5,  6,  7,  8,\n"
 *              "9, 10, 11, 12,\n";
 *
 * @param str string to convert.
 * @return result vector.
 */
std::vector<std::vector<int>> intStringToVector (const std::string& str);

std::unique_ptr<SceneNode> generateMapFromVector(const std::vector<std::vector<int>>& vec, const TextureHolder& textures);

std::unique_ptr<SceneNode> generateMapFromString(const std::string& str, const TextureHolder& textures);

#endif //TEST_GAME_MAPGENERATEUTILS_H
