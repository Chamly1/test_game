#ifndef TEST_GAME_SCENE_HPP
#define TEST_GAME_SCENE_HPP

#include "GameEngine/Scenes/SceneContext.hpp"

class SceneList;

class Scene {
private:
    SceneContext mCtx;
    SceneList* mSceneList;

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

#endif //TEST_GAME_SCENE_HPP
