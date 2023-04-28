#ifndef TEST_GAME_SCENELIST_H
#define TEST_GAME_SCENELIST_H

#include "GameEngine/Scenes/Scene.h"

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

    std::list<std::unique_ptr<Scene>> sceneList;
    std::list<PendingChange> pendingChangeList;

    SceneContext sceneContext;
    std::map<unsigned int, std::function<std::unique_ptr<Scene>()>> sceneFactory;

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
    sceneFactory[sceneId] = [this] () {
        return std::unique_ptr<Scene>(new T(sceneContext, *this));
    };
}

#endif //TEST_GAME_SCENELIST_H
