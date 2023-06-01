#include "Game/GUI/ButtonList.hpp"
#include "Game/GUI/Button.hpp"

#include "SFML/Graphics/RenderTarget.hpp"

namespace GUI {

void ButtonList::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(mButtons, states);
}

ButtonList::ButtonList(unsigned int characterSize, const sf::Font& font, const sf::Texture& selectorTexture)
: mButtons()
, mFont(font)
, mSelectorTexture(selectorTexture)
, mCharacterSize(characterSize)
, mButtonsCount(0) {

}

void ButtonList::addButton(const std::string& text, std::function<void()> callback) {
    std::shared_ptr<GUI::Button> button = std::make_shared<GUI::Button>(text, mFont, mSelectorTexture);
    button->move(0.f, mButtonsCount * (mCharacterSize / 2));
    button->setCharacterSize(mCharacterSize);
    button->setCallback(callback);

    mButtons.pushBack(button);
    mButtonsCount++;
}

bool ButtonList::isSelectable() const {
    return true;
}

void ButtonList::handleEvent(const sf::Event& event) {
    mButtons.handleEvent(event);
}

}
