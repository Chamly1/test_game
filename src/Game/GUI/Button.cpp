#include "Game/GUI/Button.hpp"
#include "Game/Utils/Utils.hpp"

#include "SFML/Graphics/RenderTarget.hpp"

namespace GUI {

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(mText, states);
    if (isSelected()) {
        target.draw(mSelector, states);
    }
}

void Button::correctSelector() {
    mSelector.setPosition(mText.getPosition());
    mSelector.move(mText.getLocalBounds().width * -0.5f, 0.f);
    mSelector.setScale(mText.getLocalBounds().height * 2 / mSelector.getTexture()->getSize().x,
                       mText.getLocalBounds().height * 2 / mSelector.getTexture()->getSize().y);
}

Button::Button(const std::string& text, const sf::Font& font, const sf::Texture& selectorTexture)
: mCallback()
, mText(text, font)
, mSelector(selectorTexture) {
    setOriginToCenter(this->mText);
    setOriginToCenter(mSelector);
    correctSelector();
}

void Button::setCallback(std::function<void()> callback) {
    this->mCallback = std::move(callback);
}

bool Button::isSelectable() const {
    return true;
}

void Button::activate() {
    if (mCallback) {
        mCallback();
    }
}

void Button::handleEvent(const sf::Event& event) {

}

void Button::setCharacterSize(unsigned int size) {
    mText.setCharacterSize(size);
    setOriginToCenter(mText);
    correctSelector();
}

}
