#include "Scenes/Scene.h"

Scene::Scene(SceneContext ctx, SceneList& sceneList)
: ctx(ctx)
, sceneList(&sceneList) {

}

Scene::~Scene() {

}
