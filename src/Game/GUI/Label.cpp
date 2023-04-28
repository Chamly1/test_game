#include "Game/GUI/Label.h"
#include "Game/Utils/Utils.h"

#include "SFML/Graphics/RenderTarget.hpp"

namespace GUI {

void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(text, states);
}

Label::Label(const std::string& text, const sf::Font& font)
: text(text, font) {
    setOriginToCenter(this->text);
}

bool Label::isSelectable() const {
    return false;
}

void Label::handleEvent(const sf::Event& event) {

}

void Label::setCharacterSize(unsigned int size) {
    text.setCharacterSize(size);
    setOriginToCenter(text);
}

}
