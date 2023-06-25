#ifndef TEST_GAME_SCENENODEUTILS_HPP
#define TEST_GAME_SCENENODEUTILS_HPP

#include "GameEngine/SceneNodes/SceneNode.hpp"
#include "GameEngine/SceneNodes/CollidableNode.hpp"

bool isSceneNodeCollidable(SceneNode& nodeToCheck);

/**
 * Check collisions between:
 *  - this node and nodeToCheck
 *  - children(and all tree) of this node and nodeToCheck.
 * Store detected collision to collisionPairs.
 *
 * @param thisNode
 * @param nodeToCheck SceneNode with which collision check.
 * @param collisionPairs container where detected collision pairs are stored.
 */
void checkNodeCollisions(SceneNode& thisNode, SceneNode& nodeToCheck, std::set<std::pair<SceneNode*, SceneNode*>>& collisionPairs);

void checkNodeAndChildrenCollisions(SceneNode& thisNode, SceneNode& nodeToCheck, std::set<std::pair<SceneNode*, SceneNode*>>& collisionPairs);

/**
 * Check collisions of each SceneNode with each in the tree. Stores detected collisions to collisionPairs.
 *
 * @param sceneGraph SceneNode to check collision.
 * @param collisionPairs container where detected collision pairs are stored.
 */
void checkAllCollisions(SceneNode& sceneGraph, std::set<std::pair<SceneNode*, SceneNode*>>& collisionPairs);

#endif //TEST_GAME_SCENENODEUTILS_HPP
