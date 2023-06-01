#include "GameEngine/Scenes/SceneList.hpp"

#include <cassert>

SceneList::PendingChange::PendingChange(PendingChangeAction action, unsigned int sceneId)
: action(action)
, sceneId(sceneId) {

}

std::unique_ptr<Scene> SceneList::createScene(unsigned int sceneId) {
    auto found = mSceneFactory.find(sceneId);
    assert(found != mSceneFactory.end());

    return found->second();
}

void SceneList::applyPendingChanges() {
    for (PendingChange change : mPendingChangeList) {
        switch (change.action) {
            case PendingChangeAction::PushBack:
                mSceneList.push_back(createScene(change.sceneId));
                break;
            case PendingChangeAction::PopBack:
                mSceneList.pop_back();
                break;
            case PendingChangeAction::Clear:
                mSceneList.clear();
                break;
        }
    }
    mPendingChangeList.clear();
}

SceneList::SceneList(SceneContext sceneContext)
: mSceneContext(sceneContext) {

}

void SceneList::update(sf::Time dt) {
    for (auto it = mSceneList.rbegin(); it != mSceneList.rend(); ++it) {
        if (!(*it)->update(dt)) {
            break;
        }
    }

    applyPendingChanges();
}

void SceneList::draw() {
    for (std::unique_ptr<Scene>& scene : mSceneList) {
        scene->draw();
        mSceneContext.window->setView(mSceneContext.window->getDefaultView());
    }
}

void SceneList::handleEvent(const sf::Event& event) {
    for (auto it = mSceneList.rbegin(); it != mSceneList.rend(); ++it) {
        if (!(*it)->handleEvent(event)) {
            break;
        }
    }

    applyPendingChanges();
}

void SceneList::pushBack(unsigned int sceneId) {
    mPendingChangeList.push_back(PendingChange(PendingChangeAction::PushBack, sceneId));
}

void SceneList::popBack() {
    mPendingChangeList.push_back(PendingChange(PendingChangeAction::PopBack));
}

void SceneList::clear() {
    mPendingChangeList.push_back(PendingChange(PendingChangeAction::Clear));
}

bool SceneList::isEmpty() const {
    return mSceneList.empty();
}
