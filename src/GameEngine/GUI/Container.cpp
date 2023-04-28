#include "GameEngine/GUI/Container.h"

#include "SFML/Graphics/RenderTarget.hpp"

namespace GUI {

void Container::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();

    for (const std::shared_ptr<Component>& child : children) {
        target.draw(*child, states);
    }
}

bool Container::hasSelection() const {
    return selectedChild >= 0;
}

void Container::select(int index) {
    if (children[index]->isSelectable()) {
        if (hasSelection()) {
            children[selectedChild]->deselect();
        }
        children[index]->select();
        selectedChild = index;
    }
}

void Container::selectNext() {
    if (!hasSelection()) {
        return;
    }

    int next = selectedChild;
    do {
        next = (next + 1) % children.size();
    } while (!children[next]->isSelectable());

    select(next);
}

void Container::selectPrevious() {
    if (!hasSelection()) {
        return;
    }

    int prev = selectedChild;
    do {
        prev = (prev - 1 + children.size()) % children.size();
    } while (!children[prev]->isSelectable());

    select(prev);
}

Container::Container()
: children()
, selectedChild(-1) {

}

void Container::pushBack(std::shared_ptr<Component> component) {
    children.push_back(component);

    if (!hasSelection() && component->isSelectable()) {
        select(children.size() - 1);
    }
}

bool Container::isSelectable() const {
    return false;
}

void Container::handleEvent(const sf::Event& event) {
    if (hasSelection() && children[selectedChild]->isActive()) {
        children[selectedChild]->handleEvent(event);
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
                    children[selectedChild]->activate();
                }
                break;
        }
    }
}

}
