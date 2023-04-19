#include "GUI/Label.h"

#include "SFML/Graphics/RenderTarget.hpp"

namespace GUI {

void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(text, states);
}

Label::Label(const std::string& text, const sf::Font& font)
: text(text, font) {

}

bool Label::isSelectable() const {
    return false;
}

void Label::handleEvent(const sf::Event& event) {

}

}
