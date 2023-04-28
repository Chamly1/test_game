#include "Game/GUI/ButtonList.h"
#include "Game/GUI/Button.h"

#include "SFML/Graphics/RenderTarget.hpp"

namespace GUI {

void ButtonList::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(buttons, states);
}

ButtonList::ButtonList(unsigned int characterSize, const sf::Font& font, const sf::Texture& selectorTexture)
: buttons()
, font(font)
, selectorTexture(selectorTexture)
, characterSize(characterSize)
, buttonsCount(0) {

}

void ButtonList::addButton(const std::string& text, std::function<void()> callback) {
    std::shared_ptr<GUI::Button> button = std::make_shared<GUI::Button>(text, font, selectorTexture);
    button->move(0.f, buttonsCount * (characterSize / 2));
    button->setCharacterSize(characterSize);
    button->setCallback(callback);

    buttons.pushBack(button);
    buttonsCount++;
}

bool ButtonList::isSelectable() const {
    return true;
}

void ButtonList::handleEvent(const sf::Event& event) {
    buttons.handleEvent(event);
}

}
