#ifndef TEST_GAME_SCENELIST_H
#define TEST_GAME_SCENELIST_H

#include "Scenes/Scene.h"

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
        explicit PendingChange(PendingChangeAction action, SceneIdentifier sceneId = SceneIdentifier::None);

        PendingChangeAction action;
        SceneIdentifier sceneId;
    };

    std::list<std::unique_ptr<Scene>> sceneList;
    std::list<PendingChange> pendingChangeList;

    SceneContext sceneContext;
    std::map<SceneIdentifier, std::function<std::unique_ptr<Scene>()>> sceneFactory;

    std::unique_ptr<Scene> createScene(SceneIdentifier sceneId);
    void applyPendingChanges();

public:
    explicit SceneList(SceneContext sceneContext);

    void update(sf::Time dt);
    void draw();
    void handleEvent(const sf::Event& event);

    template <typename T>
    void registerScene(SceneIdentifier id);

    void pushBack(SceneIdentifier sceneId);
    void popBack();
    void clear();

    bool isEmpty() const;

};

template <typename T>
void SceneList::registerScene(SceneIdentifier id) {
    sceneFactory[id] = [this] () {
        return std::unique_ptr<Scene>(new T(sceneContext, *this));
    };
}

#endif //TEST_GAME_SCENELIST_H
