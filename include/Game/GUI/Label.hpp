#ifndef TEST_GAME_LABEL_HPP
#define TEST_GAME_LABEL_HPP

#include "GameEngine/GUI/Component.hpp"

#include "SFML/Graphics/Text.hpp"

namespace GUI {

class Label : public Component {
private:
    sf::Text mText;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
    Label(const std::string& text, const sf::Font& font);
    virtual bool isSelectable() const;
    virtual void handleEvent(const sf::Event& event);
    void setCharacterSize(unsigned int size);

};

}

#endif //TEST_GAME_LABEL_HPP
