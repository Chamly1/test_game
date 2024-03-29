#ifndef TEST_GAME_CONTAINER_HPP
#define TEST_GAME_CONTAINER_HPP

#include "GameEngine/GUI/Component.hpp"

#include <vector>
#include <memory>

namespace GUI {

class Container : public Component {
private:
    std::vector<std::shared_ptr<Component>> mChildren;
    int mSelectedChild;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    bool hasSelection() const;
    void select(int index);
    void selectNext();
    void selectPrevious();

public:
    Container();
    void pushBack(std::shared_ptr<Component> component);
    virtual bool isSelectable() const;
    virtual void handleEvent(const sf::Event& event);

};

}

#endif //TEST_GAME_CONTAINER_HPP
