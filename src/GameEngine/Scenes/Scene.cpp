#include "GameEngine/Scenes/Scene.hpp"
#include "GameEngine/Scenes/SceneList.hpp"

void Scene::requestListPushBack(unsigned int sceneId) {
    mSceneList->pushBack(sceneId);
}

void Scene::requestListPopBack() {
    mSceneList->popBack();
}

void Scene::requestListClear() {
    mSceneList->clear();
}

SceneContext Scene::getSceneContext() const {
    return mCtx;
}

Scene::Scene(SceneContext ctx, SceneList& sceneList)
: mCtx(ctx)
, mSceneList(&sceneList) {

}

Scene::~Scene() {

}
