#include "GameEngine/Utils/SceneNodeUtils.hpp"
#include "GameEngine/SceneNodes/CollidableNode.hpp"

bool isSceneNodeCollidable(SceneNode& nodeToCheck) {
    if (dynamic_cast<CollidableNode*>(&nodeToCheck) != nullptr) {
        return true;
    }
    return false;
}

void checkNodeCollisions(SceneNode& thisNode, SceneNode& nodeToCheck, std::set<std::pair<SceneNode*, SceneNode*>>& collisionPairs) {
    if (!isSceneNodeCollidable(nodeToCheck)) {
        return;
    }

    if (&thisNode != &nodeToCheck && isSceneNodeCollidable(thisNode) &&
        dynamic_cast<CollidableNode&>(thisNode).isIntersect(dynamic_cast<CollidableNode&>(nodeToCheck))) {
        // std::minmax() to avoid duplication
        collisionPairs.insert(std::minmax(&thisNode, &nodeToCheck));
    }

    for (std::unique_ptr<SceneNode>& child : thisNode.mChildren) {
        checkNodeCollisions(*child, nodeToCheck, collisionPairs);
    }
}

void checkNodeAndChildrenCollisions(SceneNode& thisNode, SceneNode& nodeToCheck, std::set<std::pair<SceneNode*, SceneNode*>>& collisionPairs) {
    checkNodeCollisions(thisNode, nodeToCheck, collisionPairs);

    for (std::unique_ptr<SceneNode>& child : nodeToCheck.mChildren) {
        checkNodeAndChildrenCollisions(thisNode, *child, collisionPairs);
    }
}

void checkAllCollisions(SceneNode& sceneGraph, std::set<std::pair<SceneNode*, SceneNode*>>& collisionPairs) {
    checkNodeAndChildrenCollisions(sceneGraph, sceneGraph, collisionPairs);
}
