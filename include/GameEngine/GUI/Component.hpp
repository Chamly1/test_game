#ifndef TEST_GAME_COMPONENT_HPP
#define TEST_GAME_COMPONENT_HPP

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/Transformable.hpp"
#include "SFML/System/NonCopyable.hpp"
#include "SFML/Window/Event.hpp"

namespace GUI {

class Component : public sf::Drawable, public sf::Transformable, private sf::NonCopyable {
private:
    bool mIsSelected;
    bool mIsActive;

public:
    Component();

    virtual bool isSelectable() const = 0;
    bool isSelected() const;
    virtual void select();
    virtual void deselect();

    virtual bool isActive() const;
    virtual void activate();
    virtual void deactivate();

    virtual void handleEvent(const sf::Event& event) = 0;

};

}

#endif //TEST_GAME_COMPONENT_HPP
