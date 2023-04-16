#include "Scenes/SceneList.h"

#include <cassert>

SceneList::PendingChange::PendingChange(PendingChangeAction action, SceneIdentifier sceneId)
: action(action)
, sceneId(sceneId) {

}

std::unique_ptr<Scene> SceneList::createScene(SceneIdentifier sceneId) {
    auto found = sceneFactory.find(sceneId);
    assert(found != sceneFactory.end());

    return found->second();
}

void SceneList::applyPendingChanges() {
    for (PendingChange change : pendingChangeList) {
        switch (change.action) {
            case PendingChangeAction::PushBack:
                sceneList.push_back(createScene(change.sceneId));
                break;
            case PendingChangeAction::PopBack:
                sceneList.pop_back();
                break;
            case PendingChangeAction::Clear:
                sceneList.clear();
                break;
        }
    }
    pendingChangeList.clear();
}

SceneList::SceneList(SceneContext sceneContext)
: sceneContext(sceneContext) {

}

void SceneList::update(sf::Time dt) {
    for (auto it = sceneList.rbegin(); it != sceneList.rend(); ++it) {
        if (!(*it)->update(dt)) {
            break;
        }
    }

    applyPendingChanges();
}

void SceneList::draw() {
    for (std::unique_ptr<Scene>& scene : sceneList) {
        scene->draw();
        sceneContext.window->setView(sceneContext.window->getDefaultView());
    }
}

void SceneList::handleEvent(const sf::Event& event) {
    for (auto it = sceneList.rbegin(); it != sceneList.rend(); ++it) {
        if (!(*it)->handleEvent(event)) {
            break;
        }
    }

    applyPendingChanges();
}

void SceneList::pushBack(SceneIdentifier sceneId) {
    pendingChangeList.push_back(PendingChange(PendingChangeAction::PushBack, sceneId));
}

void SceneList::popBack() {
    pendingChangeList.push_back(PendingChange(PendingChangeAction::PopBack));
}

void SceneList::clear() {
    pendingChangeList.push_back(PendingChange(PendingChangeAction::Clear));
}

bool SceneList::isEmpty() const {
    return sceneList.empty();
}
