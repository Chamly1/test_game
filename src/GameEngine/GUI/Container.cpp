#include "GameEngine/GUI/Container.hpp"

#include "SFML/Graphics/RenderTarget.hpp"

namespace GUI {

void Container::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();

    for (const std::shared_ptr<Component>& child : mChildren) {
        target.draw(*child, states);
    }
}

bool Container::hasSelection() const {
    return mSelectedChild >= 0;
}

void Container::select(int index) {
    if (mChildren[index]->isSelectable()) {
        if (hasSelection()) {
            mChildren[mSelectedChild]->deselect();
        }
        mChildren[index]->select();
        mSelectedChild = index;
    }
}

void Container::selectNext() {
    if (!hasSelection()) {
        return;
    }

    int next = mSelectedChild;
    do {
        next = (next + 1) % mChildren.size();
    } while (!mChildren[next]->isSelectable());

    select(next);
}

void Container::selectPrevious() {
    if (!hasSelection()) {
        return;
    }

    int prev = mSelectedChild;
    do {
        prev = (prev - 1 + mChildren.size()) % mChildren.size();
    } while (!mChildren[prev]->isSelectable());

    select(prev);
}

Container::Container()
: mChildren()
, mSelectedChild(-1) {

}

void Container::pushBack(std::shared_ptr<Component> component) {
    mChildren.push_back(component);

    if (!hasSelection() && component->isSelectable()) {
        select(mChildren.size() - 1);
    }
}

bool Container::isSelectable() const {
    return false;
}

void Container::handleEvent(const sf::Event& event) {
    if (hasSelection() && mChildren[mSelectedChild]->isActive()) {
        mChildren[mSelectedChild]->handleEvent(event);
    } else if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::Up:
                selectPrevious();
                break;

            case sf::Keyboard::Down:
                selectNext();
                break;

            case sf::Keyboard::Return:
                if (hasSelection()) {
                    mChildren[mSelectedChild]->activate();
                }
                break;
        }
    }
}

}
