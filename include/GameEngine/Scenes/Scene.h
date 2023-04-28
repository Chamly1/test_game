#ifndef TEST_GAME_SCENE_H
#define TEST_GAME_SCENE_H

#include "SceneContext.h"

class SceneList;

class Scene {
private:
    SceneContext ctx;
    SceneList* sceneList;

protected:
    void requestListPushBack(unsigned int sceneId);
    void requestListPopBack();
    void requestListClear();
    SceneContext getSceneContext() const;

public:
    Scene(SceneContext ctx, SceneList& sceneList);
    virtual ~Scene();

    virtual void draw() = 0;
    /**
     *
     * @param dt
     * @return false meaning that scene doesn't want to let update other scenes in scene list
     */
    virtual bool update(sf::Time dt) = 0;
    /**
     *
     * @param event
     * @return false meaning that scene doesn't want to let input flow to other scenes in scene list
     */
    virtual bool handleEvent(const sf::Event& event) = 0;
};

#endif //TEST_GAME_SCENE_H
