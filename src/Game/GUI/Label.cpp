#include "Game/GUI/Label.hpp"
#include "Game/Utils/Utils.hpp"

#include "SFML/Graphics/RenderTarget.hpp"

namespace GUI {

void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(mText, states);
}

Label::Label(const std::string& text, const sf::Font& font)
: mText(text, font) {
    setOriginToCenter(this->mText);
}

bool Label::isSelectable() const {
    return false;
}

void Label::handleEvent(const sf::Event& event) {

}

void Label::setCharacterSize(unsigned int size) {
    mText.setCharacterSize(size);
    setOriginToCenter(mText);
}

}
