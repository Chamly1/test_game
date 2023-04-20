#include "GUI/Button.h"

#include "SFML/Graphics/RenderTarget.hpp"

namespace GUI {

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(text, states);
    if (isSelected()) {
        target.draw(selector, states);
    }
}

Button::Button(const std::string& text, const sf::Font& font, const sf::Texture& selectorTexture)
: callback()
, text(text, font)
, selector(selectorTexture) {

}

void Button::setCallback(std::function<void()> callback) {
    this->callback = std::move(callback);
}

bool Button::isSelectable() const {
    return true;
}

void Button::activate() {
    if (callback) {
        callback();
    }
}

void Button::handleEvent(const sf::Event& event) {

}

}
