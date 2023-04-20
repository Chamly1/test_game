#include "GUI/Button.h"
#include "Utils/Utils.h"

#include "SFML/Graphics/RenderTarget.hpp"

namespace GUI {

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(text, states);
    if (isSelected()) {
        target.draw(selector, states);
    }
}

void Button::correctSelector() {
    selector.setPosition(text.getPosition());
    selector.move(text.getLocalBounds().width * -0.5f, 0.f);
    selector.setScale(text.getLocalBounds().height * 2 / selector.getTexture()->getSize().x,
                      text.getLocalBounds().height * 2 / selector.getTexture()->getSize().y);
}

Button::Button(const std::string& text, const sf::Font& font, const sf::Texture& selectorTexture)
: callback()
, text(text, font)
, selector(selectorTexture) {
    setOriginToCenter(this->text);
    setOriginToCenter(selector);
    correctSelector();
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

void Button::setCharacterSize(unsigned int size) {
    text.setCharacterSize(size);
    setOriginToCenter(text);
    correctSelector();
}

}
