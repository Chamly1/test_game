#include "GameEngine/Scenes/Scene.hpp"
#include "GameEngine/Scenes/SceneList.hpp"

void Scene::requestListPushBack(unsigned int sceneId) {
    sceneList->pushBack(sceneId);
}

void Scene::requestListPopBack() {
    sceneList->popBack();
}

void Scene::requestListClear() {
    sceneList->clear();
}

SceneContext Scene::getSceneContext() const {
    return ctx;
}

Scene::Scene(SceneContext ctx, SceneList& sceneList)
: ctx(ctx)
, sceneList(&sceneList) {

}

Scene::~Scene() {

}
