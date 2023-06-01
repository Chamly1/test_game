#ifndef TEST_GAME_SCENELIST_HPP
#define TEST_GAME_SCENELIST_HPP

#include "GameEngine/Scenes/Scene.hpp"

#include <list>

class SceneList : private sf::NonCopyable {
private:
    enum class PendingChangeAction {
        PushBack,
        PopBack,
        Clear
    };

    struct PendingChange
    {
        explicit PendingChange(PendingChangeAction action, unsigned int sceneId = 0);

        PendingChangeAction action;
        unsigned int sceneId;
    };

    std::list<std::unique_ptr<Scene>> mSceneList;
    std::list<PendingChange> mPendingChangeList;

    SceneContext mSceneContext;
    std::map<unsigned int, std::function<std::unique_ptr<Scene>()>> mSceneFactory;

    std::unique_ptr<Scene> createScene(unsigned int sceneId);
    void applyPendingChanges();

public:
    explicit SceneList(SceneContext sceneContext);

    void update(sf::Time dt);
    void draw();
    void handleEvent(const sf::Event& event);

    template <typename T>
    void registerScene(unsigned int sceneId);

    void pushBack(unsigned int sceneId);
    void popBack();
    void clear();

    bool isEmpty() const;

};

template <typename T>
void SceneList::registerScene(unsigned int sceneId) {
    mSceneFactory[sceneId] = [this] () {
        return std::unique_ptr<Scene>(new T(mSceneContext, *this));
    };
}

#endif //TEST_GAME_SCENELIST_HPP
